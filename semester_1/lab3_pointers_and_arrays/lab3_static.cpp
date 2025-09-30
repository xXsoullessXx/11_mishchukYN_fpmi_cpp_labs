// solve task with usage of
// static arrays
#include <iostream>
#include <random>
#include <limits>

int main() {
    const int maxSize = 100;
    int array[maxSize], arraySize;
    std::cout << "Enter n (1-" << maxSize << "): ";
    if (!(std::cin >> arraySize) || arraySize <= 0 || arraySize > maxSize) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }
    std::cout << "Fill from keyboard (1) or random (2): ";
    int fillChoice;
    if (!(std::cin >> fillChoice)) {
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }
    if (fillChoice == 1) {
        std::cout << "Enter " << arraySize << " integers: ";
        for (int i = 0; i < arraySize; i++) {
            if (!(std::cin >> array[i])) {
                std::cout << "Invalid input for element " << i + 1 << std::endl;
                return 1;
            }
        }
    } else if (fillChoice == 2) {
        int minValue, maxValue;
        std::cout << "Enter a b (a <= b): ";
        if (!(std::cin >> minValue >> maxValue) || minValue > maxValue) {
            std::cout << "Invalid a or b" << std::endl;
            return 1;
        }
        std::mt19937 generator(45218965);
        std::uniform_int_distribution<> distribution(minValue, maxValue);
        for (int i = 0; i < arraySize; i++) 
            array[i] = distribution(generator);
    } else {
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }
    std::cout << "Initial array: ";
    for (int i = 0; i < arraySize; i++) 
        std::cout << array[i] << " ";
    std::cout << std::endl;
    int maxValue = array[0], minValue = array[0];
    int lastMaxIndex = 0, lastMinIndex = 0;
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            lastMaxIndex = i;
        } else if (array[i] == maxValue) {
            lastMaxIndex = i;
        }
        if (array[i] < minValue) {
            minValue = array[i];
            lastMinIndex = i;
        } else if (array[i] == minValue) {
            lastMinIndex = i;
        }
    }
    int product = 1;
    int startIndex, endIndex;
    if (lastMaxIndex < lastMinIndex) {
        startIndex = lastMaxIndex + 1;
        endIndex = lastMinIndex - 1;
    } else {
        startIndex = lastMinIndex + 1;
        endIndex = lastMaxIndex - 1;
    }
    bool hasElements = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        product *= array[i];
        hasElements = 1;
    }
    if (!hasElements) {
        std::cout << "No elements between last max and last min, product = 1" << std::endl;
    } else {
        std::cout << "Product of elements between last min (" << maxValue << " at " << lastMaxIndex << ") and last max (" << minValue << " at " << lastMinIndex << "): " << product << std::endl;
    }
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] > array[j]) std::swap(array[i], array[j]);
        }
    }
    std::cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
    int uniqueIndex = 0;
    for (int i = 1; i < arraySize; i++) {
        if (array[i] != array[uniqueIndex]) {
            uniqueIndex++;
            array[uniqueIndex] = array[i];
        }
    }
    arraySize = uniqueIndex + 1;
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < arraySize; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
    return 0;
}