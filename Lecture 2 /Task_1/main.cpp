#include <iostream>

int main()
{
    int size, sum = 0, odd_sum = 0, even_sum = 0;
    std::cout << "Please enter size of numbers array: ";
    std::cin >> size;
    int array[size];
    for (int i = 0 ; i < size ; i++) {
        int num;
        std::cout << "Please enter number: ";
        std::cin >> num;
        array[i] = num;
        sum += num;
        if (num % 2 == 0) {
            even_sum += num;
        } else {
            odd_sum += num;
        }
    }

    std::cout << "Sum of numbers: " << sum << std::endl;
    std::cout << "Sum of even numbers: " << even_sum << std::endl;
    std::cout << "Sum of odd numbers: " << odd_sum << std::endl;

    return 0;
}
