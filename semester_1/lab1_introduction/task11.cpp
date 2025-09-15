#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main() {
    int num;
    std::cout << "Enter a natural decimal number: ";
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (num <= 0) {
        std::cout << "Number must be positive." << std::endl;
        return 1;
    }

    std::string binary = "";
    int temp = num;
    if (temp == 0) {
        binary = "0";
    } else {
        while (temp > 0) {
            char buf = '0';
            if (temp % 2) {
                buf = '1';
            }
            binary = buf + binary;
            temp /= 2;
        }
    }
    std::cout << "Binary: " << binary << std::endl;

    return 0;
}