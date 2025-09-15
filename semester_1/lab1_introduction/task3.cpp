#include <iostream>
#include <cmath>
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

    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += std::pow(i, i);
    }

    std::cout << "Sum: " << sum << std::endl;

    // Переполнение типа данных 

    return 0;
}