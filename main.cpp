#include <iostream>
#include <vector>
#include <string>
#include "include/ShellSort.h"
using namespace std;

template<typename T>
void testShellSort(T* arr, int size, const string& testName) {
    cout << "\n--- " << testName << " ---" << endl;
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    shellSort(arr, size);
    
    cout << "After:  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== SHELL SORT TEST CASES ===" << endl;
    
    // Test Case 1: Simple two-element case
    {
        int arr[] = {2, 1};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Simple Two Elements");
    }
    
    // Test Case 2: Original test case (from insertion/selection sort)
    {
        int arr[] = {23, 78, 45, 8, 32, 56};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Original Test Case");
    }
    
    // Test Case 3: Already sorted array
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Already Sorted Array");
    }
    
    // Test Case 4: Reverse sorted array
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Reverse Sorted Array");
    }
    
    // Test Case 5: Array with duplicates
    {
        int arr[] = {5, 2, 8, 2, 9, 1, 5, 5, 8, 1};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Duplicates");
    }
    
    // Test Case 6: Single element
    {
        int arr[] = {42};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Single Element");
    }
    
    // Test Case 7: All same elements
    {
        int arr[] = {7, 7, 7, 7, 7, 7, 7};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "All Same Elements");
    }
    
    // Test Case 8: Negative numbers
    {
        int arr[] = {-3, -1, -7, -2, -5, -10, -4};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Negative Numbers");
    }
    
    // Test Case 9: Mixed positive and negative
    {
        int arr[] = {-10, 5, -3, 0, 8, -1, 12, -7, 15};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Mixed Positive and Negative");
    }
    
    // Test Case 10: Large numbers
    {
        int arr[] = {1000000, 500000, 2000000, 100000, 750000, 1500000};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Large Numbers");
    }
    
    // Test Case 11: Random order (medium size)
    {
        int arr[] = {17, 3, 44, 6, 20, 1, 35, 18, 9, 25, 12, 30};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Random Order (Medium)");
    }
    
    // Test Case 12: Float numbers
    {
        float arr[] = {3.14f, 2.71f, 1.41f, 0.57f, 4.47f, 1.73f, 2.23f};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Float Numbers");
    }
    
    // Test Case 13: Characters
    {
        char arr[] = {'z', 'a', 'm', 'b', 'x', 'c', 'p', 'k', 'e'};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Characters");
    }
    
    // Test Case 14: Edge case with zero
    {
        int arr[] = {0, -1, 1, 0, 2, -2, 3, 0, -3};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Multiple Zeros");
    }
    
    // Test Case 15: Large array (testing gap efficiency)
    {
        int arr[] = {99, 88, 77, 66, 55, 44, 33, 22, 11, 0, 100, 50, 25, 75, 90, 10, 60, 40, 80, 20, 70, 30};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Large Array (Gap Testing)");
    }
    
    // Test Case 16: Power of 2 sized array
    {
        int arr[] = {16, 8, 4, 12, 2, 14, 6, 10, 1, 15, 3, 13, 5, 11, 7, 9};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Power of 2 Size (16 elements)");
    }
    
    // Test Case 17: Small arrays that test different gap sequences
    {
        int arr[] = {5, 1, 4, 2, 3};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Small Array (5 elements)");
    }
    
    // Test Case 18: Array that benefits from shell sort's gap approach
    {
        int arr[] = {50, 1, 49, 2, 48, 3, 47, 4, 46, 5, 45, 6};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Alternating High-Low Pattern");
    }
    
    // Test Case 19: Min/Max integer values
    {
        int arr[] = {2147483647, -2147483648, 0, 1, -1, 1000, -1000};
        testShellSort(arr, sizeof(arr) / sizeof(arr[0]), "Min/Max Integer Values");
    }
    
    cout << "\n=== ALL SHELL SORT TEST CASES COMPLETED ===" << endl;
    return 0;
}