// solve task with usage of
// dynamic arrays
#include <iostream>
#include <random>
#include <cmath>
#include <limits>

int main() {
    int arraySize;
    std::cout << "Enter n (>0): ";
    if (!(std::cin >> arraySize) || arraySize <= 0) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }
    double* array = new double[arraySize];
    std::cout << "Fill from keyboard (1) or random (2): ";
    int fillChoice;
    if (!(std::cin >> fillChoice)) {
        std::cout << "Invalid choice" << std::endl;
        delete[] array;
        return 1;
    }
    if (fillChoice == 1) {
        std::cout << "Enter " << arraySize << " doubles: ";
        for (int i = 0; i < arraySize; i++) {
            if (!(std::cin >> array[i])) {
                std::cout << "Invalid input for element " << i + 1 << std::endl;
                delete[] array;
                return 1;
            }
        }
    } else if (fillChoice == 2) {
        double minValue, maxValue;
        std::cout << "Enter a b (a <= b): ";
        if (!(std::cin >> minValue >> maxValue) || minValue > maxValue) {
            std::cout << "Invalid input" << std::endl;
            delete[] array;
            return 1;
        }
        std::mt19937 generator(45218965);
        std::uniform_real_distribution<> distribution(minValue, maxValue);
        for (int i = 0; i < arraySize; i++) array[i] = distribution(generator);
    } else {
        std::cout << "Invalid choice" << std::endl;
        delete[] array;
        return 1;
    }
    std::cout << "Initial array: ";
    for (int i = 0; i < arraySize; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
    double maxValue = array[0], minValue = array[0];
    int firstMaxIndex = 0, lastMinIndex = 0;
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            firstMaxIndex = i;
        }
        if (array[i] < minValue) {
            minValue = array[i];
            lastMinIndex = i;
        } else if (array[i] == minValue) {
            lastMinIndex = i;
        }
    }
    double sum = 0.0;
    int startIndex, endIndex;
    if (firstMaxIndex < lastMinIndex) {
        startIndex = firstMaxIndex + 1;
        endIndex = lastMinIndex - 1;
    } else {
        startIndex = lastMinIndex + 1;
        endIndex = firstMaxIndex - 1;
    }
    bool hasElements = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        sum += array[i];
        hasElements = 1;
    }
    if (!hasElements) {
        std::cout << "No elements between first max and last min, sum = 0" << std::endl;
    } else {
        std::cout << "Sum of elements between first min (" << maxValue << " at " << firstMaxIndex << ") and last max (" << minValue << " at " << lastMinIndex << "): " << sum << std::endl;
    }
    double minModule = std::fabs(array[0]), maxModule = std::fabs(array[0]);
    int minModuleIndex = 0, maxModuleIndex = 0;
    for (int i = 1; i < arraySize; i++) {
        double module = std::fabs(array[i]);
        if (module < minModule) {
            minModule = module;
            minModuleIndex = i;
        }
        if (module > maxModule) {
            maxModule = module;
            maxModuleIndex = i;
        }
    }
    std::swap(array[minModuleIndex], array[maxModuleIndex]);
    std::cout << "After std::swapping min mod (" << std::fabs(array[maxModuleIndex]) << " at " << minModuleIndex << ") and max mod (" << std::fabs(array[minModuleIndex]) << " at " << maxModuleIndex << "): ";
    for (int i = 0; i < arraySize; i++) 
        std::cout << array[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] > array[j]) std::swap(array[i], array[j]);
        }
    }
    std::cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    delete[] array;
    return 0;
}