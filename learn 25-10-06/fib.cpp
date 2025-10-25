#include <iostream>
using namespace std;

int fib(int n){
    cout << n << ", ";
    if (n = 0) return 0;
    if (n = 1) return 1;
    return fib(n) + fib(n-1);
}

int main(){

    int n = 10;
    int result = fib(n);
    cout << endl;
    cout << "The fib series at: " << n << " is " << result << endl;

    return 0;
}