#include <iostream>

int main()
{
    int num, size = 0;
    int *numbers;
    std::cout << "Enter numbers one by one, end input with 0" << std::endl;
    do {
        std::cin >> num;
        if (num != 0) {
            int *temp_numbers = new int[size], prev_size = size;
            if (size > 0) {
                for (int i = 0 ; i < prev_size ; i++) {
                    temp_numbers[i] = numbers[i];
                }
                delete[] numbers;
            }
            size++;
            numbers = new int[size];
            for (int i = 0 ; i < prev_size ; i++) {
                numbers[i] = temp_numbers[i];
            }
            numbers[size - 1] = num;
            delete[] temp_numbers;
        }
    } while (num != 0);
    int biggest_element_index = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] > numbers[biggest_element_index]) {
            biggest_element_index = i;
        }
    }
    for (int i = 0 ; i < size ; i++) {
        int start_index = ((numbers[biggest_element_index] - numbers[i]) / 2);
        for (int j = 0 ; j < (numbers[i] + start_index) ; j++) {
            if (j >= start_index) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    delete[] numbers;
    return 0;
}
