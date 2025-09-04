#include <iostream>
#include <vector>
#include <string>
#include "include/BubbleSort.h"
using namespace std;

template<typename T>
void testBubbleSort(T* arr, int size, const string& testName) {
    cout << "\n--- " << testName << " ---" << endl;
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(arr, size);
    
    cout << "After:  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== BUBBLE SORT TEST CASES ===" << endl;
    
    // Test Case 1: Original test case
    {
        int arr[] = {23, 78, 45, 8, 56, 32};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Original Test Case");
    }
    
    // Test Case 2: Already sorted array (tests early termination optimization)
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Already Sorted Array");
    }
    
    // Test Case 3: Reverse sorted array (worst case)
    {
        int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Reverse Sorted Array (Worst Case)");
    }
    
    // Test Case 4: Array with duplicates
    {
        int arr[] = {5, 2, 8, 2, 9, 1, 5, 5, 8, 1};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Duplicates");
    }
    
    // Test Case 5: Single element
    {
        int arr[] = {42};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Single Element");
    }
    
    // Test Case 6: Two elements (unsorted)
    {
        int arr[] = {7, 3};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Two Elements (Unsorted)");
    }
    
    // Test Case 7: Two elements (already sorted)
    {
        int arr[] = {3, 7};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Two Elements (Already Sorted)");
    }
    
    // Test Case 8: All same elements
    {
        int arr[] = {7, 7, 7, 7, 7, 7, 7};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "All Same Elements");
    }
    
    // Test Case 9: Negative numbers
    {
        int arr[] = {-3, -1, -7, -2, -5, -10, -4};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Negative Numbers");
    }
    
    // Test Case 10: Mixed positive and negative
    {
        int arr[] = {-10, 5, -3, 0, 8, -1, 12, -7, 15};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Mixed Positive and Negative");
    }
    
    // Test Case 11: Large numbers
    {
        int arr[] = {1000000, 500000, 2000000, 100000, 750000, 1500000};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Large Numbers");
    }
    
    // Test Case 12: Random order
    {
        int arr[] = {17, 3, 44, 6, 20, 1, 35, 18, 9, 25, 12, 30};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Random Order");
    }
    
    // Test Case 13: Float numbers
    {
        float arr[] = {3.14f, 2.71f, 1.41f, 0.57f, 4.47f, 1.73f, 2.23f};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Float Numbers");
    }
    
    // Test Case 14: Characters
    {
        char arr[] = {'z', 'a', 'm', 'b', 'x', 'c', 'p', 'k', 'e'};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Characters");
    }
    
    // Test Case 15: Edge case with zero
    {
        int arr[] = {0, -1, 1, 0, 2, -2, 3, 0, -3};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Array with Multiple Zeros");
    }
    
    // Test Case 16: Nearly sorted array (best case for optimized bubble sort)
    {
        int arr[] = {1, 2, 3, 5, 4, 6, 7, 8, 9};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Nearly Sorted Array");
    }
    
    // Test Case 17: Bubble sort torture test (many swaps needed)
    {
        int arr[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Maximum Swaps Pattern");
    }
    
    // Test Case 18: Min/Max integer values
    {
        int arr[] = {2147483647, -2147483648, 0, 1, -1, 1000, -1000};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Min/Max Integer Values");
    }
    
    // Test Case 19: Empty array edge case (size 0) - we'll skip this as it would be problematic
    
    // Test Case 20: Performance test - larger array
    {
        int arr[] = {50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93, 3, 15, 28, 40, 53};
        testBubbleSort(arr, sizeof(arr) / sizeof(arr[0]), "Performance Test (20 elements)");
    }
    
    cout << "\n=== ALL BUBBLE SORT TEST CASES COMPLETED ===" << endl;
    return 0;
}