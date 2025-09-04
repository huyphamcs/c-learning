#include <iostream>
#include <vector>
#include <string>
#include "include/QuickSort.h"
using namespace std;

template<typename T>
void testQuickSort(T* arr, int size, const string& testName) {
    cout << "\n--- " << testName << " ---" << endl;
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, size);
    
    cout << "After:  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== QUICK SORT TEST CASES ===" << endl;
    
    // Test Case 1: Original test case (with duplicates)
    {
        int arr[] = {26, 33, 35, 29, 19, 12, 22, 12, 19, 22, 26, 29, 33, 35};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Original Test Case (with Duplicates)");
    }
    
    // Test Case 2: Simple test case
    {
        int arr[] = {23, 78, 45, 8, 32, 56};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Simple Test Case");
    }
    
    // Test Case 3: Already sorted array
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Already Sorted Array");
    }
    
    // Test Case 4: Reverse sorted array (worst case for simple pivot selection)
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Reverse Sorted Array");
    }
    
    // Test Case 5: Array with many duplicates
    {
        int arr[] = {5, 5, 2, 8, 5, 2, 9, 1, 5, 5, 8, 1};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Many Duplicates");
    }
    
    // Test Case 6: Single element
    {
        int arr[] = {42};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Single Element");
    }
    
    // Test Case 7: Two elements (unsorted)
    {
        int arr[] = {7, 3};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Two Elements (Unsorted)");
    }
    
    // Test Case 8: Two elements (already sorted)
    {
        int arr[] = {3, 7};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Two Elements (Already Sorted)");
    }
    
    // Test Case 9: All same elements
    {
        int arr[] = {7, 7, 7, 7, 7, 7, 7};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "All Same Elements");
    }
    
    // Test Case 10: Negative numbers
    {
        int arr[] = {-3, -1, -7, -2, -5, -10, -4};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Negative Numbers");
    }
    
    // Test Case 11: Mixed positive and negative
    {
        int arr[] = {-10, 5, -3, 0, 8, -1, 12, -7, 15};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Mixed Positive and Negative");
    }
    
    // Test Case 12: Large numbers
    {
        int arr[] = {1000000, 500000, 2000000, 100000, 750000, 1500000};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Large Numbers");
    }
    
    // Test Case 13: Random order
    {
        int arr[] = {17, 3, 44, 6, 20, 1, 35, 18, 9, 25, 12, 30};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Random Order");
    }
    
    // Test Case 14: Float numbers
    {
        float arr[] = {3.14f, 2.71f, 1.41f, 0.57f, 4.47f, 1.73f, 2.23f};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Float Numbers");
    }
    
    // Test Case 15: Characters
    {
        char arr[] = {'z', 'a', 'm', 'b', 'x', 'c', 'p', 'k', 'e'};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Characters");
    }
    
    // Test Case 16: Edge case with zero
    {
        int arr[] = {0, -1, 1, 0, 2, -2, 3, 0, -3};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Multiple Zeros");
    }
    
    // Test Case 17: Pivot as smallest element
    {
        int arr[] = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Pivot as Smallest Element");
    }
    
    // Test Case 18: Pivot as largest element
    {
        int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Pivot as Largest Element");
    }
    
    // Test Case 19: Alternating pattern
    {
        int arr[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Alternating Pattern");
    }
    
    // Test Case 20: Min/Max integer values
    {
        int arr[] = {2147483647, -2147483648, 0, 1, -1, 1000, -1000};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Min/Max Integer Values");
    }
    
    // Test Case 21: Performance test - larger array
    {
        int arr[] = {50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93, 3, 15, 28, 40, 53, 65, 78, 21, 46, 59, 84, 9, 34, 71, 96};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Performance Test (30 elements)");
    }
    
    // Test Case 22: Array with pattern that tests partitioning
    {
        int arr[] = {5, 1, 5, 2, 5, 3, 5, 4, 5};
        testQuickSort(arr, sizeof(arr) / sizeof(arr[0]), "Partitioning Test Pattern");
    }
    
    cout << "\n=== ALL QUICK SORT TEST CASES COMPLETED ===" << endl;
    return 0;
}