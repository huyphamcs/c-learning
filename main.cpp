#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void sortByFrequency(int arr[], int n)
{
    if (n <= 2)
        return;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    sort(arr, arr + n);
    // cout << "SORTED: ";
    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;
    int i = 0;
    vector<vector<int>> f;
    while (i < n)
    {
        int count = 1;
        // int first_index = i;
        while (arr[i] == arr[i + 1] && i != n - 1)
        {
            count++;
            i++;
        }
        f.push_back({arr[i], count, (int)((long int)&(*find(temp.begin(), temp.end(), arr[i])) - (long int)&(*temp.begin())) / 4});
        i++;
    }
    // for (vector<int> x: f){
    //     // for (int y: x) cout << y << " ";
    //     cout << x[1] << " ";
    // }
    // cout << endl;
    auto cmp = [&](vector<int> a, vector<int> b)
    {
        if (a[1] == b[1])
            return (a[2] < b[2]);
        return a[1] > b[1];
    };
    sort(f.begin(), f.end(), cmp);
    int index = 0;
    for (vector<int> x : f)
    {
        // for (int y: x) cout << y << " ";
        // cout << x[0] << " " << x[1] << " " << x[2] << endl;
        for (int i = 0; i < x[1]; i++)
        {
            arr[index + i] = x[0];
            // cout << index + i << " " << arr[index+i] << endl;
        }
        index+=x[1];
    }
}

int main()
{
    // int arr[] = {-4, 1, 2, 2, -4, 9, 1, -1};
    
    int arr[] = {5, 5, 4, 6, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortByFrequency(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}