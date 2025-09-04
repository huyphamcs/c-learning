#include "../include/InsertionSort.h"
#include <cstring>

template <class T>
void insertionSort(T *arr, int size)
{
    if (size > 1)
    {
        for (int i = 1; i < size; i++)
        {
            int current = i;
            int walker = i - 1;
            while (arr[walker] > arr[i] && walker > -1)
            {
                walker--;
            }

            if (walker == i - 1)
                continue;
            else if (walker < i - 1 || walker == -1)
            {
                T temp = arr[current];
                memmove(arr + walker + 2, arr + walker + 1, (current - walker - 1) * sizeof(T));
                arr[walker + 1] = temp;
            }
        }
    }
}
