#include<iostream>
#include<string>
#define MAX 10000009

using namespace std;

string matrix[MAX];
void initialize(){
    for(int i = 0; i < MAX; i++) matrix[i] = "/";
}

bool empty(string A){
    if(A == "/") return true;
    return false;
}

string stradd(string A, string B){
    int len = A.length() - B.length();
    if(len > 0){
        string s="0";
        for(int i = 1; i < len; i++) s += "0";
        B = s+B; 
    }
    else if(len < 0){
        string s="0";
        for(int i = 1; i < abs(len); i++) s+="0";
        A =s+A;
    }
    int sum = 0, carry = 0, n = A.length();
    for(int i = n-1; i >=0; i--){
        sum = carry + (int)A[i] + (int)B[i] - '0' - '0';
        carry = sum / 10;

        sum = sum % 10;
        A[i] = char(sum + '0'); 

    }
    if(carry > 0) A = to_string(carry) + A; 
    return A;
}

string fib(int n){
    if(n < 2) return to_string(n);
    if(!empty(matrix[n])) return matrix[n];
    matrix[n] = stradd(fib(n-1) , fib(n-2));
    return matrix[n];
}

int main(){
    initialize();
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << fib(n)<<endl;
}
