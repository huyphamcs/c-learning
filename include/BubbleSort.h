#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

template<class T>
void bubbleSort(T* arr, int size);

template<class T>
void swapInArray(T* arr, int i, int j);

template<class T>
void print(T* arr, int size);

// Include implementation for templates
#include "../src/BubbleSort.cpp"

#endif
