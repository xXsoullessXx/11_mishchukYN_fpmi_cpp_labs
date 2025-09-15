#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<double> nums(10);
    std::cout << "Enter 10 real numbers: ";
    for (int i = 0; i < 10; ++i) {
        while (!(std::cin >> nums[i])) {
            std::cout << "Invalid input for number " << i + 1 << ". Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int count = 0;
    if (nums[0] < nums[1]) {
        ++count;
    }

    for (int i = 1; i < 9; ++i) {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            ++count;
        }
    }

    if (nums[9] < nums[8]) {
        ++count;
    }

    std::cout << "Number of elements less than their neighbors: " << count << std::endl;

    return 0;
}