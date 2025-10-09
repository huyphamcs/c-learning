#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

void clear(stack<int> &s)
{
    while (!s.empty())
        s.pop();
}

int main()
{
    // vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = {31,27,14,21,30,22};

    vector<int> stock_span;
    stock_span.push_back(1);
    size_t vSize = v.size();
    for (size_t i = 1; i < vSize; i++){
        vector<int> temp;
        stack<int> sTemp;
        for (int j = 0; j <= i; j++){
            if (v[j] < v[i]) sTemp.push(0);
            else{
                temp.push_back(sTemp.size());
                clear(sTemp);
            } 
        }
        stock_span.push_back((*max_element(temp.begin(), temp.end())) + 1);
    }
    for (int x: stock_span) cout << x << " ";
    cout << endl;

    return 0;
}