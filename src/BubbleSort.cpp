#include <iostream>
using namespace std;

template<class T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class T>
void swapInArray(T* arr, int i, int j) {
    if (i != j) { // Avoid self-assignment
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

template<class T>
void bubbleSort(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false; // Optimization: early termination
        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swapInArray(arr, j - 1, j);
                swapped = true;
            }
        }
        // If no swapping occurred, array is already sorted
        if (!swapped) break;
    }
}
