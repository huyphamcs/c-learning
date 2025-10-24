
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template<class T>
void swap(T* a, T* b){
    // cout << "Before: " << *a << " " << *b << endl;
    T temp = *a;
    *a = *b;
    *b = temp;
    // cout << "After: " << *a << " " << *b << endl;

}
template<class T>
void printArray(T* start, T* end){
    for (int i = 0; i < end - start; i++) cout << *(start + i) << " ";
    cout << endl;
}


template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end){
        if (start == end - 1) return start;
        if (start == end - 2){
            // cout << "HAHAA";
        }
        T* p = start;
        T* l = start + 1;
        T* r = end - 1;
        // cout << l - start << " " << r - start << endl;

        while(true){
            while(l <= r){
                if(*l >= *p) break;
                l++;
            }
            // cout << l - start << endl;
            while(l<=r){
                if(*r<*p)break;
                r--;
            }
            // cout << r - start << endl;
            if (l>r) {
                swap(p,r);
                p = r;
                break;
            }
            swap(l,r);
            l++;
            r--;
        }
        // cout << "Pivot Index: " << p - start << endl;
        return p;
    }

public:
    static void QuickSort(T *start, T *end, int first_index = 0){
        // cout << "HAHAHA " << *Partition(start, end);
        // Partition(start, end);
        if (start == end - 1) {
            cout << 0 << " ";
            return;
        }


        if (start == end) return;
        T* p = Partition(start, end);
        cout << p - start  << " ";
        QuickSort(start, p, 0);
        QuickSort(p+1, end, p - start + 1);


    }
};

void test()
{
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
cout << "Index of pivots: ";
Sorting<int>::QuickSort(&array[0], &array[20]);
cout << "\n";
cout << "Array after sorting: ";
for (int i : array) cout << i << " ";
}
int main (){
    test();
    return 0;
}