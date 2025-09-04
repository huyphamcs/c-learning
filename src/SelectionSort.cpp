#include <iostream>
using namespace std;

template <class T>
int findMinInArray(T *arr, int size)
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == min)
            return i;
    }
    return -1;
}

template <class T>
void swapInArray(T *arr, int i, int j)
{
    if (i != j)
    { // Avoid self-assignment for XOR swap
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

template <class T>
void print(T *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <class T>
void selectionSort(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = findMinInArray(arr + i, size - i) + i;
        swapInArray(arr, i, minIndex);
    }
}
