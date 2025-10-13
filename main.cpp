#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getMSB(long long n){
    if (n>=0 && n<=9) return n;
    while(n>10){
        n = n /10;
    }
    return n;
}
int getLSB(long long n){
    return n%10;
}
long long nthNiceNumber(int n) {
    long long output;
    if (n==1) return 2;
    if (n==2) return 5;
    queue<long long> q;
    q.push(2);
    q.push(5);
    for (int i = 0; i < n - 2; i++){
        if(true) {
            if(getLSB(q.back()) == 5)q.push(q.front()*10 + 2);
            else {
                q.push(q.back()+3);
                q.pop();
            }
        }

    }
    return q.back();
}


int main()
{
    // cout << getMSB(254871);
    cout << nthNiceNumber(10000);
    return 0;   
}