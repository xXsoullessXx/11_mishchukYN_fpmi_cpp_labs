#include <iostream>
#include <limits>

int main() {
    int n;
    std::cout << "Enter n: ";
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    if (n <= 0) {
        std::cout << "n must be positive." << std::endl;
        return 1;
    }

    long long sumEven = 0;
    long long productOdd = 1;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            sumEven += i;
        } else {
            productOdd *= i;
        }
    }

    std::cout << "Sum of even numbers: " << sumEven << std::endl;
    std::cout << "Product of odd numbers: " << productOdd << std::endl;
    return 0;
}