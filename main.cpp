#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

void printArray(int n, int c = 0){
    // if (n==0) cout << n << " ";
    if (n>0)printArray(n-1,1);
    if (c == 1) cout << n << ", ";
    else cout << n << endl;

}

void printFromTop(int n){
    if (n>=-4){
        cout << n << " ";
        printFromTop(n-5);
    }
}

// int getCount(int n){
//     int output = 0;
//     if (n>0){
//         output = 1 + getCount(n-5);
//     }
//     return output;
// }

void printFromBottom(int n, int c = 0){
    // int count = getCount(n);
    if (n>0) {
        printFromBottom(n-5, 1);
        if (c==0) cout << n;
        else cout << n << " ";
    }
}
void printPattern(int n) {
    if (n==0) cout << n;
    printFromTop(n);
    printFromBottom(n);
}

int findMax(int* arr, int length, int max = 0)
{
    // max = *arr;
    if (max < *arr){
        max = *arr;
    }
    if (length>1)max = findMax(arr+1, length-1, max);
    return max;
}

string preprocessing(string str){
    string output = "";
    int size = str.length();
    for (int i = 0; i < size; i++){
        if (str[i]!= ' ') output += str[i];
    }
    return output;
} 

bool isPalindrome(string str) 
{ 
    str = preprocessing(str);
    int size = str.length();
    if (size <=1) return 1;
    if (str[0] == str[size-1]) return isPalindrome(str.substr(1, size-2));
    return 0;
}

// string reverseSentence(string s, string tempStr = "", string tempChar = "") {
//     // STUDENT ANSWER
//     string output = "";

//     if (tempChar[0]!=' '){
//         tempStr += s[0];
//         reverseSentence(s.substr(1,s.length()-1), tempStr, );
//     }

//     return output;
// }

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    size_t size = nums.size();
    if (size == 0)return true;
    size_t left = 0;
    size_t right = size-1;
    while (true){
        if ((nums[left] == 1) || (left == size)) break;
        left++;
    }
    while(true){
        if ((nums[right] == 1) || (right == 0)) break;
        right --;
    }
    // cout << left << " " << right << endl;
    // if (left == right || left == right - 1) return true;
    if (left < right){
        while(true){
            if (nums[left] == 1) left++;
            if (left == right) return true;
            if(nums[left] == 0) return false;
            if (nums[right] == 1) right--;
            if(nums[left] == 0) return false;

            if (left == right) return true;
            
            // return false;
        }
    }
    return true;
}
int main () {
    vector<int> nums {1,1, 1,1,1,1,1,1};
    cout << consecutiveOnes(nums);
    return 0;   
}