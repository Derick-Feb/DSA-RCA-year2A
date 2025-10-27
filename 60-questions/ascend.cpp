#include <iostream>
using namespace std;

void sortThree(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
}

int main() {
    int x, y, z;
    cout << "Enter three integers: ";
    cin >> x >> y >> z;

    sortThree(x, y, z);
    cout << "Ascending order: " << x << " " << y << " " << z << endl;

    return 0;
}
