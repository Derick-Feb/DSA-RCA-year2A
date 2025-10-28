#include <iostream>

using namespace std;

class Number {
    int array[5] = {0, 1, 2, 3, 4};

    public:
        int n;

        Number(int set_n): n(set_n) {}

        Number operator+(const Number &numA) {
            return Number(this->n + numA.n);
        }

        bool operator==(const Number &numA) {
            return this->n == numA.n;
        }

        int& operator[](int index) {
            return array[index];
        }
};

int main() {

    Number a(5);
    Number b(10);

    b[3] = 20;

    // left operand is 'this' pointer
    // right operand is 'numA'
    Number c = a + b;

    cout << "Result: " << c.n << endl;

    if (a == b) cout << "a and b are equal" << endl;
    else cout << "a and b are not equal" << endl;

    return 0;
}