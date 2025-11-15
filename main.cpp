#include <iostream>
using namespace std;
void reheapDown(int maxHeap[], int n, int index)
{
    
    while (true)
    {
        int l = 2 * index + 1;
        int r = l + 1;
        if (l > n - 1)
            break;
        else if (l == n - 1)
        {
            if (maxHeap[index] < maxHeap[l])
            {
                int temp = maxHeap[index];
                maxHeap[index] = maxHeap[l];
                maxHeap[l] = temp;
                index = l;
            }
        }
        else if (l < n - 1)
        {
            if (maxHeap[index] >= maxHeap[l] && maxHeap[index] >= maxHeap[r])
                break;
            else if (maxHeap[index] < maxHeap[l] && maxHeap[index] > maxHeap[r])
            {
                // Swap index and left child
                int temp = maxHeap[index];
                maxHeap[index] = maxHeap[l];
                maxHeap[l] = temp;
                index = l;
            }
            else if (maxHeap[index] > maxHeap[l] && maxHeap[index] < maxHeap[r])
            {
                // Swap index and right child
                int temp = maxHeap[index];
                maxHeap[index] = maxHeap[r];
                maxHeap[r] = temp;
                index = r;
            }
            else if (maxHeap[index] < maxHeap[l] && maxHeap[index] < maxHeap[r])
            {
                // Root is smaller than both 2 children
                if (maxHeap[l] > maxHeap[r])
                {
                    // Swap root with left child
                    int temp = maxHeap[index];
                    maxHeap[index] = maxHeap[l];
                    maxHeap[l] = temp;
                    index = l;
                }
                else
                {
                    // Swap root with right child
                    int temp = maxHeap[index];
                    maxHeap[index] = maxHeap[r];
                    maxHeap[r] = temp;
                    index = r;
                }
            }
        }
    }
}

void reheapUp(int maxHeap[], int n, int index)
{
    int i = index;
    if (i == 0)
        return;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (maxHeap[parent] < maxHeap[i])
        {
            int temp = maxHeap[parent];
            maxHeap[parent] = maxHeap[i];
            maxHeap[i] = temp;
            i = parent;
        }
        else
            break;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    reheapDown(arr, size, 0);
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "]";
    return 0;
}