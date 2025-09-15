#include <iostream>
#include <limits>

int main() {
    int num;
    std::cout << "Enter a 6-digit number: ";
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (num < 100000 || num > 999999) {
        std::cout << "The number is not 6-digit." << std::endl;
        return 1;
    }

    int d1 = num / 100000;
    int d2 = (num / 10000) % 10;
    int d3 = (num / 1000) % 10;
    int d4 = (num / 100) % 10;
    int d5 = (num / 10) % 10;
    int d6 = num % 10;

    int sum1 = d1 + d2 + d3;
    int sum2 = d4 + d5 + d6;

    if (sum1 == sum2) {
        std::cout << "The number is lucky." << std::endl;
    } else {
        std::cout << "The number is not lucky." << std::endl;
    }

    return 0;
}