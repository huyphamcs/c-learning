#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
    {
        int arrSize = end - start;
        int num_elements = 0;
        for (int i = segment_idx; i < arrSize; i += cur_segment_total)
        {
            // cout << i << " ";
            num_elements++;
        }
        // cout << num_elements << endl;
        for (int i = 0; i < num_elements - 1; i++)
        {
            for (int j = 0; j < num_elements - i - 1; j++)
            {
                int first_index = segment_idx + cur_segment_total * j;
                int second_index = segment_idx + cur_segment_total * (j + 1);
                if (start[first_index] > start[second_index])
                {
                    // cout << start[first_index] << " " << start[second_index] << endl;
                    int temp = start[first_index];
                    start[first_index] = start[second_index];
                    start[second_index] = temp;
                }
            }
        }
        

    }
    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
    {
        for (int i = num_phases - 1; i >= 0; i--){
            for (int j = 0; j < num_segment_list[i]; j++){
                sortSegment(start, end, j, num_segment_list[i]);
            }
            cout << num_segment_list[i] << " segments: ";
            printArray(start, end);
        }
    }
};

void test()
{
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
}

int main()
{
    test();
    return 0;
}