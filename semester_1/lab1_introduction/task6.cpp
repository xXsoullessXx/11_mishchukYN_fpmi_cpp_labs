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

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 2 * i + 1;
    }

    std::cout << "Sum of first " << n << " odd numbers: " << sum << std::endl;

    return 0;
}