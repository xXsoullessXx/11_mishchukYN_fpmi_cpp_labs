#include <iostream>
#include <limits>

int main() {
    int a, b, d;
    std::cout << "Enter a (first term), b (upper limit), d (difference): ";
    while (!(std::cin >> a >> b >> d)) {
        std::cout << "Invalid input. Please enter three integers: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (a > b || d <= 0) {
        std::cout << "Invalid values: a must be <= b, d must be > 0." << std::endl;
        return 1;
    }

    for (int k = a; k <= b; k += d) {
        if (k % 3 == 0) {
            std::cout << k << std::endl;
        }
    }

    return 0;
}