#include <iostream>
using namespace std;

int perimeter(int length, int width) {
    return 2 * (length + width);
}

int area(int length, int width) {
    return length * width;
}

int main() {
    int length, width;
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;

    cout << "Area: " << area(length, width) << endl;
    cout << "Perimeter: " << perimeter(length, width) << endl;

    return 0;
}
