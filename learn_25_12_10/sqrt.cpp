#include <iostream>
#include <iomanip>
using namespace std;


// using the networn-raphson method to find the square root;
double mySqrt(double x) {
    if (x < 0){
        cerr << "Error: Negative input" << endl;
        return -1;
    }

    if (x == 0 || x == 1) {
        return x;
    }

    double guess = x;
    double eps = 1e-9;

    while(true) {
        double guess_next = guess - (guess * guess - x) / (2 * guess);
        if(abs(guess_next - guess) < eps) break;

        guess = guess_next;
    }

    return guess;
}

int main() {
    cout << fixed << setprecision(12) << mySqrt(45) << endl; 
    return 0;
}


/*
    ostream& operator<<(ostream& out, cout classs_Name obj){
        out << obj.member1 << " " << obj.member2;
        return out;
    }
*/