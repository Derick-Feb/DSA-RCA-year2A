#include <iostream>
using namespace std;

void quotientRemainder(int a, int b, int &quot, int &rem) {
    if (b != 0) {
        quot = a / b;
        rem = a % b;
    } else {
        cout << "Error: Division by zero!" << endl;
        quot = rem = 0;
    }
}

int main() {
    int num1, num2, q, r;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    quotientRemainder(num1, num2, q, r);
    cout << "Quotient: " << q << ", Remainder: " << r << endl;

    return 0;
}
