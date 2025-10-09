#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

bool isNumber(string s){
    if (s.size() == 1 && s[0]>='0' && s[0] <='9') return 1;
    if (s.size()>1) return 1;
    return 0;
}
// bool isOperator (string s){
//     return !isNumber(s);
// }

int evaluatePostfix(string expr){
    /*TODO*/
    stringstream ss(expr);
    string token;
    stack<int> s;
    while(ss>>token){
        if(isNumber(token)) s.push(stoi(token));
        else {
            int operand1, operand2, result;
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();
            if (token == "+") result = operand1 + operand2;
            else if (token == "-") result = operand1 - operand2;
            else if (token == "*") result = operand1 * operand2;
            else if (token == "/") result = operand1 / operand2;
            s.push(result);
        }
    }
    return s.top();
}

int main () {
    cout << evaluatePostfix("100 200 + 2 / 5 * 7 +");
    return 0;
}