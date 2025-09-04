#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template<class T>
void quickSort(T* arr, int size);

template<class T>
void swapInArray(T* arr, int i, int j);

template<class T>
void print(T* arr, int size);

// Include implementation for templates
#include "../src/QuickSort.cpp"

#endif
