#include <iostream>
using namespace std;

long fib(int);
long *fibArray(int, long *);
// The tower of Hanoi
void move(int, char, char, char);

// IMPLEMETATION
long fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void move(int n, char source, char destination, char auxiliary)
{
    static int step = 0;
    if (n == 1)
        cout << "Step " << ++step << ": Move from " << source << " to " << destination << endl;
    else
    {
        move(n - 1, source, auxiliary, destination);
        move(1, source, destination, auxiliary);
        move(n - 1, auxiliary, destination, source);
    }
}

long *fibArray(int n, long *arr)
{
    if (n == 0)
    {
        *arr = 0;
        return arr;
    }
    else if (n == 1)
    {
        *arr = 0;
        *(arr + sizeof(int)) = 1;
        return arr;
    }
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
        arr[i] = arr[i-1] + arr[i-2];
    return arr;
}