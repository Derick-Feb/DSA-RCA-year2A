#include <iostream>
using namespace std;

int countDigit(int number, int num, int count=0) {
    if(number == 0) return count;
    if(number%10 == num) count++;
    return countDigit(number/10, num, count);
}

/*
  initialize cache array:

  cache[n+1];
  for(int i=0; i<n; i++) cache[i] = -1;
*/

int fibonacci(int n, int cache[]){
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(cache[n] != -1) return cache[n];

    cache[n] = fibonacci(n-1, cache) + fibonacci(n-2, cache);

    return cache[n];
}

int pow(int x, int y){
    if(y == 0) return 1;
    return x * pow(x, y-1);
}

/*
    - normal(named) namespace
    - nested namespace
    - anonymous(unnamed) namespace

    we also have the using declartion and using directive
    declaration
*/

int main() {
    cout << countDigit(142445, 4);
    return 0;
}
