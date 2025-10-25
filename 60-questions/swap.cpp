#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Input 1st number: ";
    cin >> a;
    cout << "Input 2nd number: ";
    cin >> b;

    // Swapping using a temporary variable
    int temp = a;
    a = b;
    b = temp;

    cout << "After swapping the 1st number is: " << a << endl;
    cout << "After swapping the 2nd number is: " << b << endl;

    return 0;
}
