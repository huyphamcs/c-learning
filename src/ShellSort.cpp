#include "../include/InsertionSort.h"
#include <iostream>
using namespace std;

// Gap sequence for shell sort
const int gaps[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
const int gapsArraySize = sizeof(gaps) / sizeof(gaps[0]);

template<class T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class T>
void insertionSortWithGap(T* arr, int numElements, int gap) {
    T* newArr = new T[numElements];
    for (int i = 0; i < numElements; i++)
        newArr[i] = arr[i * gap];
    insertionSort(newArr, numElements);
    for (int i = 0; i < numElements; i++)
        arr[i * gap] = newArr[i];
    delete[] newArr;
}

template<class T>
void shellSort(T* arr, int size) {
    if (size <= 1) return;
    
    int numSegments = 0;
    int gapsIndex = 0;
    
    // Find the appropriate starting gap
    for (int i = 0; i < gapsArraySize; i++) {
        if (gaps[i] * 2 > size) {
            if (i > 0) {
                numSegments = gaps[i - 1];
                gapsIndex = i - 1;
            } else {
                numSegments = gaps[0];
                gapsIndex = 0;
            }
            break;
        }
        if (i == gapsArraySize - 1) {
            numSegments = gaps[i];
            gapsIndex = i;
        }
    }
    
    while (numSegments >= 1) {
        for (int i = 0; i < numSegments; i++) {
            int numElements = 0;
            int j = i;
            do {
                numElements++;
                j += numSegments;
            } while (j < size);
            
            if (numElements > 1) {
                insertionSortWithGap(arr + i, numElements, numSegments);
            }
        }
        gapsIndex--;
        if (gapsIndex >= 0) {
            numSegments = gaps[gapsIndex];
        } else {
            break;
        }
    }
}
