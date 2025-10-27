#include <iostream>
using namespace std;

void checkNumber(int n) {
    if (n > 0) cout << "Positive" << endl;
    else if (n < 0) cout << "Negative" << endl;
    else cout << "Zero" << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    checkNumber(n);

    return 0;
}
