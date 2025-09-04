#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

template <class T>
void selectionSort(T *arr, int size);

template <class T>
int findMinInArray(T *arr, int size);

template <class T>
void swapInArray(T *arr, int i, int j);

template <class T>
void print(T *arr, int size);

// Include implementation for templates
#include "../src/SelectionSort.cpp"

#endif
