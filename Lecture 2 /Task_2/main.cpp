#include <iostream>

int main()
{
    int size, smallest_element_index = 0, biggest_element_index = 0;
    std::cout << "Please enter size of numbers array: ";
    std::cin >> size;
    int array[size];
    for (int i = 0 ; i < size ; i++) {
        int num;
        std::cout << "Please enter number: ";
        std::cin >> num;
        array[i] = num;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] < array[smallest_element_index]) {
            smallest_element_index = i;
        }
        if (array[i] > array[biggest_element_index]) {
            biggest_element_index = i;
        }
    }

    std::cout << "Smallest element: " << array[smallest_element_index] << std::endl;
    std::cout << "Biggest element: " << array[biggest_element_index] << std::endl;

    return 0;
}
