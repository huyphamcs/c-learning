#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T *start, T *middle, T *end)
    {
        InsertionSort(start, end);
    }

public:
    static void InsertionSort(T *start, T *end)
    {
        int size = end - start; // 6
        for (int i = 1; i < size; i++)
        {
            T *curr = start + i;
            while (*curr < *(curr - 1) && curr > start)
            {
                T temp = *curr;
                *curr = *(curr - 1);
                *(curr - 1) = temp;
                curr--;
            }
        }
    }
    static void TimSort(T *start, T *end, int min_size)
    {
        // TODO
        if (start == end)
            return;
        // You must print out the array after using insertion sort and everytime calling method merge.
        T *left = start;
        T *right = end;
        int size = right - left;
        int segments = 0;
        for (int i = 0; i < size; i += min_size)
        {
            if (left + i + 1 * min_size <= right)
            {
                // cout << "TRUE" << endl;
                // cout << "Before: ";
                // printArray(left+i, left+i+4);
                InsertionSort(left + i, left + i + min_size);
                // cout << "After: ";
                // printArray(left+i,left+i+4);
            }
            else
            {
                // cout << "FALSE" << endl;
                // cout << "Before: ";
                // printArray(left+i,end);
                // printArray(left+i,right);
                InsertionSort(left + i, right);
                // cout << "After: ";
                // printArray(left+i,end);
            }
            segments++;
        }
        cout << "Insertion Sort: ";
        printArray(left, right);
        // cout << segments<<endl;
        int overall_merge_time = 1;
        while (segments > 1)
        {
            int merge_time = (segments % 2 == 0) ? segments / 2 : segments / 2 + 1;

            for (int i = 0; i < merge_time; i++)
            {
                if (i != merge_time - 1)
                    merge(start + i * min_size * 2, start + i * min_size * 2 + min_size, start + i * min_size * 2 + 2 * min_size);
                else
                {
                    if (segments == 2)
                        merge(start, start + 1, end);
                    else
                    {
                    }
                }
                cout << "Merge " << overall_merge_time++ << ": ";
                printArray(start, end);
            }

            segments = merge_time;
            min_size *= 2;
        }
        merge(start, start + 1, end);
    }
};
int main()
{

    int array[] = {19, 20, 18, 17, 12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3, 5, 2, 4, 1, 3};
    cout << "Original Array: ";
    for (int x: array) cout << x << " "; cout << endl;
    int min_size = 4;
    int size = sizeof(array)/sizeof(array[0]);
    Sorting<int>::TimSort(&array[0], &array[size], min_size);
    return 0;
}