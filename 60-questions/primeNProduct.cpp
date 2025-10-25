#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n <= 0) return false;
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    long long product = 1;
    for(int i = 2; i <= 100; i++)
        if(isPrime(i)) 
            product *= i;

    cout << "Product of prime numbers between 1 and 100 is: " << product << endl;

    return 0;
}