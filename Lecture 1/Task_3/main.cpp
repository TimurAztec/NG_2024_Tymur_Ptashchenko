#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "Enter Xmas tree height: ";
    cin >> height;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height + i; ++j) {
            if (j < height - i - 1)
                cout << " ";
            else
                cout << "*";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < height; ++j) {
        cout << " ";
    }
    cout << "*" << std::endl;

    return 0;
}
