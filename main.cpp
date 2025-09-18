#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int val)
{
    int outIndex = 0;
    for (outIndex = 0; outIndex < size; outIndex++)
    {
        if (arr[outIndex] == val)
            return outIndex;
    }
    return -1;
}

int jumpSearch(int *arr, int size, int val, int blockSize)
{
    int outIndex = 0;
    int segments = size / blockSize;
    for (int i = 0; i < segments; i++)
    {
        if (arr[i * blockSize] >= val && arr[(i + 1) * blockSize] < val)
        {
            cout << "FOUND" << endl;
            outIndex = i * blockSize + linearSearch(arr + i * blockSize, blockSize, val);
            return outIndex;
        }
    }
    return linearSearch(arr + segments*blockSize, size - segments*blockSize , val);

    return -1;
}

double interpolationSearch (int* arr, int size, int val){
    double pos = (val - arr[0])*(size-1)/(arr[size-1]-arr[0]);
    cout << pos << endl;
    if (arr[(int)pos] == val) return pos;
    else if (val<arr[(int)pos]) pos = interpolationSearch(arr, pos, val);
    else pos = pos + interpolationSearch(arr+1, size-pos-1, val);
    return pos;
}

int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int size = sizeof(arr) / sizeof(arr[0]);
    int blockSize = 4;
    // cout << jumpSearch(arr, size, 21, blockSize) << endl;
    // cout << interpolationSearch(arr, size, 233) << endl;
    for (int i = 0; i < size; i++){
        cout << interpolationSearch(arr, size, arr[i]) << "-----" << arr[i] << endl;
    }
    return 0;
}