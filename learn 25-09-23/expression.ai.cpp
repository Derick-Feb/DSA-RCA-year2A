#include <iostream>
using namespace std;

int main() {

    int x=10, y=20, z=5, t=2, s=7;

    int h = x * y / z % s * t - s * x / t + y / x * t;

    cout << "value of h: " << h << endl;
    
    int p = y / x % z / t * s - s * x / t + y / x * t;
    
    cout << "value of p: " << p << endl;

    // operation precendence: *, /, % from left to right
    // operation precendence: +, - from left to right
}