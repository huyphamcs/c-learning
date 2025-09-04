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
void quickSort(T* arr, int size) {
    if (size <= 1) return;
    
    T pivot = arr[0];
    int left = 1;
    int right = size - 1;
    
    // Partitioning phase
    while (left <= right) {
        // Find element from left that should be on right side of pivot
        while (left <= right && arr[left] < pivot)
            left++;
        
        // Find element from right that should be on left side of pivot
        while (left <= right && arr[right] >= pivot)
            right--;
        
        // If we found elements to swap
        if (left < right) {
            swapInArray(arr, left, right);
            left++;
            right--;
        }
    }
    
    // Place pivot in correct position
    swapInArray(arr, 0, right);
    
    // Recursively sort left and right subarrays
    quickSort(arr, right);
    quickSort(arr + right + 1, size - right - 1);
}
