#include <iostream>

int BubbleSort(int* arr, size_t n) {
    for(int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(arr[i]) < abs(arr[j])) { 
                int buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
        }
    }
    return *arr;
}

void InputArray (int* arr, size_t n) {
    for (int i = 0; i < n; ++i) {
        if (!std::cin >> arr[i]) {
            std::cout << "Unavailable value for an element";
            std::exit(0);
        }
    }
}

void OutputArray(int* arr, size_t n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    std::cout << "Enter size of the array: ";
    //std::cin.clear();
    //я не знаю почему оно не читает)
    if (!std::cin >> n || n < 1) {
        std::cout << "Unavailable size of array";
        return 0; 
    }

    int* a[n];
    InputArray(*a, n);

    BubbleSort(*a, n);
    std::cout << "SFGdhd";
    OutputArray(*a, n);
    
    return 0;
}