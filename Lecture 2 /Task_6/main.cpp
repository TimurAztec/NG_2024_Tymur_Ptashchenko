#include <iostream>

int main()
{
    int size = 10;
    int accounts[size];
    for (int i = 0 ; i < size ; i++) {
        accounts[i] = 0;
    }
    for (int i = 0 ; i < size ; i++) {
        std::cout << accounts[i] << " ";
    }
    while(true) {
        int card, money;
        std::cout << "\nCard: ";
        std::cin >> card;
        std::cout << "Money: ";
        std::cin >> money;
        accounts[card-1] += money;
        for (int i = 0 ; i < size ; i++) {
            std::cout << accounts[i] << " ";
        }
    }
    return 0;
}
