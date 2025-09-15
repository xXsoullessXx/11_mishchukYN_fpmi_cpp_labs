#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cout << "Enter the number of elements: " << std::endl;
    while (!(std::cin >> n)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (n <= 0) {
        std::cout << "Number of elements must be positive." << std::endl;
        return 1;
    }
    std::cout << "Enter the elements: " << std::endl;
    std::vector<double> nums(n);
    for (int i = 0; i < n; ++i) {
        while (!(std::cin >> nums[i])) {
            std::cout << "Invalid input for element " << i + 1 << ". Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (nums.empty()) {
        std::cout << "No elements entered." << std::endl;
        return 0;
    }

    double sum = 0, min_val = nums[0], max_val = nums[0];
    for (auto x : nums) {
        sum += x;
        if (x < min_val) min_val = x;
        if (x > max_val) max_val = x;
    }

    double avg = sum / n;
    std::cout << "Average: " << avg << std::endl;
    std::cout << "Min: " << min_val << std::endl;
    std::cout << "Max: " << max_val << std::endl;

    return 0;
}