#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cout << "Enter n: ";
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (n < 0) {
        std::cout << "n must be non-negative." << std::endl;
        return 1;
    }

    std::vector<long long> fib;
    if (n >= 1) fib.push_back(0);
    if (n >= 2) fib.push_back(1);
    for (int i = 2; i < n; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    for (size_t i = 0; i < fib.size(); ++i) {
        std::cout << fib[i];
        if (i < fib.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}