#include <iostream>
#include <string>
#include <limits>

int main() {
    long long n;
    std::cout << "Enter a number: ";

    if (!(std::cin >> n)) {
        std::cout << "Invalid input. ";
        return 1;
    }

    std::string str = std::to_string(n);
    char min = '9';
    for (auto c: str) {
        if (c < min && c != '-') min = c;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == min) {
            str.erase(i, 1);
            i--;
        }
    }

    std::cout << "Your number without " << min << " (min char): " << str << std::endl;

    return 0;
}