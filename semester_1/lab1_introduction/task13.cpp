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

    int a = 0, b = 1, c;

    if (n >= 1) std::cout << 0 << " "; 
    if (n >= 2) std::cout << 1 << " "; 
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}