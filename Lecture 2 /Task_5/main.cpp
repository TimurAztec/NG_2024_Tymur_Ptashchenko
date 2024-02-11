#include <functional> // Add this line
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>
#include <unistd.h> // for usleep()
#include <cstdlib>
#include <ctime>

using namespace std;

struct position {
    int x;
    int y;
};

const int ROW_SIZE = 10;
const int COL_SIZE = 20;
const int INITIAL_HEALTH = 100;
const int ENEMY_DAMAGE = 10;

int playerHealth = INITIAL_HEALTH;

void drawLine(int size) {
    for (int elemNumber = 0; elemNumber < size; elemNumber++)
        cout << "=";
    cout << endl;
}

void drawMap(char map[ROW_SIZE][COL_SIZE], position player, position enemy) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (row == player.y && col == player.x)
                cout << "@";
            else
                cout << map[row][col];
        }
        cout << endl;
    }
    cout << "Player Health: " << playerHealth << endl;
}

void mapInit(char map[ROW_SIZE][COL_SIZE], char playerMap[ROW_SIZE][COL_SIZE]) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (row == 0 || col == 0 || row == ROW_SIZE - 1 || col == COL_SIZE - 1)
                map[row][col] = '*';
            else {
                int chance = rand() % 10;
                switch(chance) {
                case 1: map[row][col] = 's'; break;
                case 2: map[row][col] = 't'; break;
                default: map[row][col] = ' ';
                }
            }
            playerMap[row][col] = '*';
        }
    }
}

bool checkPosition(char map[ROW_SIZE][COL_SIZE], position pos) {
    char item = map[pos.y][pos.x];
    return item == ' ';
}

bool updatePlayerPosition(char map[ROW_SIZE][COL_SIZE], char direction, position *player) {
    position tempPosition;
    tempPosition = *player;
    switch (direction) {
    case 'w': tempPosition.y--; break;
    case 's': tempPosition.y++; break;
    case 'a': tempPosition.x--; break;
    case 'd': tempPosition.x++; break;
    }
    if (checkPosition(map, tempPosition)) {
        *player = tempPosition;
        return true;
    }
    return false;
}

void updatePlayerMap(char map[ROW_SIZE][COL_SIZE], char playerMap[ROW_SIZE][COL_SIZE], position player) {
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            playerMap[row][col] = '*';
        }
    }
    for (int row = player.y-1; row <= player.y+1; row++) {
        for (int col = player.x - 50; col <= player.x + 50; col++) {
            playerMap[row][col] = map[row][col];
        }
    }
}

void placeEnemy(char map[ROW_SIZE][COL_SIZE], position *enemy) {
    int enemyX, enemyY;
    do {
        enemyX = rand() % (COL_SIZE - 2) + 1;
        enemyY = rand() % (ROW_SIZE - 2) + 1;
    } while (map[enemyY][enemyX] != ' ');
    enemy->x = enemyX;
    enemy->y = enemyY;
}

vector<position> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(position pos) {
    return pos.x >= 0 && pos.x < COL_SIZE && pos.y >= 0 && pos.y < ROW_SIZE;
}

bool isObstacle(char map[ROW_SIZE][COL_SIZE], position pos) {
    return map[pos.y][pos.x] != ' ';
}

int manhattanDistance(position p1, position p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void moveEnemy(char map[ROW_SIZE][COL_SIZE], position& enemy, position player) {
    bool playerInSight = false;
    for (const auto& dir : directions) {
        position nextPos = {enemy.x + dir.x, enemy.y + dir.y};
        while (isValid(nextPos) && !isObstacle(map, nextPos)) {
            if (nextPos.x == player.x && nextPos.y == player.y) {
                playerInSight = true;
                break;
            }
            nextPos.x += dir.x;
            nextPos.y += dir.y;
        }
        if (playerInSight) break;
    }

    if (playerInSight) {
        int dx = (player.x > enemy.x) - (player.x < enemy.x);
        int dy = (player.y > enemy.y) - (player.y < enemy.y);
        position nextPos = {enemy.x + dx, enemy.y + dy};
        if (isValid(nextPos) && !isObstacle(map, nextPos)) {
            map[enemy.y][enemy.x] = ' ';
            enemy = nextPos;
            map[enemy.y][enemy.x] = 'Z';
            return;
        }
    }

    int minObstacles = 16;
    int dx = 0, dy = 0;

    for (const auto& dir : directions) {
        position nextPos = {enemy.x + dir.x, enemy.y + dir.y};
        if (isValid(nextPos) && !isObstacle(map, nextPos)) {
            int obstacles = 0;
            for (const auto& d : directions) {
                position neighbor = {nextPos.x + d.x, nextPos.y + d.y};
                if (!isValid(neighbor) || isObstacle(map, neighbor)) {
                    obstacles++;
                }
            }
            if (obstacles < minObstacles) {
                minObstacles = obstacles;
                dx = dir.x;
                dy = dir.y;
            } else if (obstacles == minObstacles) {
                position candidatePos = {enemy.x + dx, enemy.y + dy};
                position nextPosWithDir = {enemy.x + dir.x, enemy.y + dir.y};
                if (manhattanDistance(nextPosWithDir, player) < manhattanDistance(candidatePos, player)) {
                    dx = dir.x;
                    dy = dir.y;
                }
            }
        }
    }

    position nextPos = {enemy.x + dx, enemy.y + dy};
    if (isValid(nextPos) && !isObstacle(map, nextPos)) {
        map[enemy.y][enemy.x] = ' ';
        enemy = nextPos;
        map[enemy.y][enemy.x] = 'Z';
    }
}

int main() {
    srand(time(NULL));

    char map[ROW_SIZE][COL_SIZE];
    char playerMap[ROW_SIZE][COL_SIZE];

    position player;
    player.x = COL_SIZE / 2;
    player.y = ROW_SIZE / 2;
    position enemy;

    char direction;

    mapInit(map, playerMap);
    placeEnemy(map, &enemy);

    while (true) {
        drawMap(playerMap, player, enemy);
        drawLine(COL_SIZE);

        cout << "Enter direction: ";
        direction = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (updatePlayerPosition(map, direction, &player)) {
            updatePlayerMap(map, playerMap, player);
        }

        moveEnemy(map, enemy, player);

        if (player.x == enemy.x && player.y == enemy.y) {
            playerHealth -= ENEMY_DAMAGE;
            if (playerHealth <= 0) {
                cout << "Game Over! You have been defeated." << endl;
                break;
            }
        }
        system("clear");
    }

    return 0;
}
