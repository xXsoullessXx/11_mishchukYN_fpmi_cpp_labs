#include <iostream>
#include <limits>

int main() {
    int k;
    std::cout << "Enter k: ";
    while (!(std::cin >> k)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (k < 0) {
        std::cout << "k must be non-negative." << std::endl;
        return 1;
    }

    long long result = 1;
    if (k % 2 == 0) {
        // even
        for (int i = 2; i <= k; i += 2) {
            result *= i;
        }
    } else {
        // odd
        for (int i = 1; i <= k; i += 2) {
            result *= i;
        }
    }

    std::cout << "Double factorial: " << result << std::endl;

    return 0;
}