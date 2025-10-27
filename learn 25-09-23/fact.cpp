#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return n * fact(n - 1);
}

int main(){

    // add code
    int num = 5;
    int result = fact(num);

    cout << result << endl;

    return 0;
}