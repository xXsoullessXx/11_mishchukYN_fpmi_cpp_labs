#include <iostream>
#include <limits>
#include <ctime>
#include <random>

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void getMatrixInput(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            if (!(std::cin >> matrix[i][j])) {
                throw std::invalid_argument("Invalid input - expected integer");
            }
        }
    }
}

void generateRandomMatrix(int** matrix, int rows, int cols, int minValue, int maxValue) {
    std::mt19937 generator(45218965);
    std::uniform_real_distribution<> distribution(minValue, maxValue);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = distribution(generator);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    std::cout << "\nMatrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void findMaxInNonPositiveColumns(int** matrix, int rows, int cols) {
    std::cout << "\nMax elements in columns without positive elements:\n";
    bool found = false;
    
    for (int j = 0; j < cols; ++j) {
        bool hasPositive = false;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        
        if (!hasPositive) {
            found = true;
            int maxVal = matrix[0][j];
            for (int i = 1; i < rows; ++i) {
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                }
            }
            std::cout << "Column " << j << ": " << maxVal << std::endl;
        }
    }
    
    if (!found) {
        std::cout << "No columns without positive elements found.\n";
    }
}

int countNegativesInLowerRightTriangle(int** matrix, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1 - i; j < size; ++j) {
            if (matrix[i][j] < 0) {
                count++;
            }
        }
    }
    return count;
}

void inputBorders(int& minValue, int& maxValue) {
    std::cout << "Enter lower bound: ";
    if (!(std::cin >> minValue)) throw std::invalid_argument("Expected integer");
    std::cout << "Enter upper bound: ";
    if (!(std::cin >> maxValue)) throw std::invalid_argument("Expected integer");
    if (minValue > maxValue) throw std::invalid_argument("Lower bound is greater than upper bound");
}    

int main() {
    int rows, cols;
    int inputMethod;
    
    try {
        std::cout << "Enter number of rows: ";
        if (!(std::cin >> rows) || rows <= 0) throw std::invalid_argument("Invalid rows value");
        
        std::cout << "Enter number of columns: ";
        if (!(std::cin >> cols) || cols <= 0) throw std::invalid_argument("Invalid columns value");
        
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square (rows == columns)");
        }
        
        std::cout << "Choose input method:\n1. Manual input\n2. Random generation\n";
        if (!(std::cin >> inputMethod) || (inputMethod != 1 && inputMethod != 2)) {
            throw std::invalid_argument("Invalid input method selection");
        }
        
        int** matrix = createMatrix(rows, cols);
        
        if (inputMethod == 1) {
            getMatrixInput(matrix, rows, cols);
        } else {
            int minValue, maxValue;
            inputBorders(minValue, maxValue);
            generateRandomMatrix(matrix, rows, cols, minValue, maxValue);
        }
        
        printMatrix(matrix, rows, cols);
        findMaxInNonPositiveColumns(matrix, rows, cols);
        
        int negativeCount = countNegativesInLowerRightTriangle(matrix, rows);
        std::cout << "\nNumber of negative elements in lower right triangle: "
             << negativeCount << std::endl;
        
        deleteMatrix(matrix, rows);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}