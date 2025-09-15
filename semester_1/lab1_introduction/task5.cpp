#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    int n, m;
    std::cout << "Enter n and m: ";
    while (!(std::cin >> n >> m)) {
        std::cout << "Invalid input. Please enter two integers: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (n <= 0 || m <= 0) {
        std::cout << "n and m must be positive." << std::endl;
        return 1;
    }

    int minVal = std::min(n, m);
    std::cout << "Common divisors: ";
    for (int i = 1; i <= minVal; ++i) {
        if (n % i == 0 && m % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}