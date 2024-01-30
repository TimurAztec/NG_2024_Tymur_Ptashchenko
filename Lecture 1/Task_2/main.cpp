#include <iostream>

void check_income(int income) {
    const int low_income = 1000, high_income = 1000000;
    if (((income - low_income) >> 31) & 1) {
        std::cout << "\nWork harder!";
        return;
    }
    if (((high_income - income) >> 31) & 1) {
        std::cout << "\nYou are a millionaire!";
        return;
    }
    std::cout << "\nGood work!";
}

int main(int argc, char *argv[])
{
    int income;
    std::cout << "Please enter your income: ";
    std::cin >> income;
    check_income(income);
    std::cout << "\n...But you're awesome anyway!";
    return 0;
}
