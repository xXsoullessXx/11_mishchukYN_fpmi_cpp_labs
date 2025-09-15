#include <iostream>
#include <limits>

int main() {
    int num;
    std::cout << "Enter a 4-digit number: ";
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (num < 1000 || num > 9999) {
        std::cout << "The number is not 4-digit." << std::endl;
        return 1;
    }

    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    if (d1 == d4 && d2 == d3) {
        std::cout << "The number is a palindrome." << std::endl;
    } else {
        std::cout << "The number is not a palindrome." << std::endl;
    }

    return 0;
}