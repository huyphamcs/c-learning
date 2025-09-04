#ifndef SHELL_SORT_H
#define SHELL_SORT_H

// Gap sequence for shell sort
extern const int gaps[];
extern const int gapsArraySize;

template<class T>
void shellSort(T* arr, int size);

template<class T>
void insertionSortWithGap(T* arr, int numElements, int gap);

template<class T>
void print(T* arr, int size);

// Include implementation for templates
#include "../src/ShellSort.cpp"

#endif
