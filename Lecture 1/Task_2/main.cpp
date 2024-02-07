#include <iostream>

int main(int argc, char *argv[])
{
    int income;
    const int low_income = 1000, high_income = 1000000;
    std::cout << "Please enter your income: ";
    std::cin >> income;
    if (income < low_income) {
        std::cout << "\nWork harder!";
    }
    if (high_income < income) {
        std::cout << "\nYou are a millionaire!";
    }
    if (income > low_income && income < high_income) {
        std::cout << "\nGood work!";
    }
    std::cout << "\n...But you're awesome anyway!";
    return 0;
}
