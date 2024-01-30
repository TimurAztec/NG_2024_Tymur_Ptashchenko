#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "Enter Xmas tree height: ";
    cin >> height;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "*";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < height - 1; ++j) {
        cout << " ";
    }
    cout << "*" << std::endl;

    return 0;
}
