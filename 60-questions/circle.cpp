#include <iostream>
#define PI 3.14
using namespace std;

double circleArea(double r) {
    return PI * r * r;
}

double circleCircumference(double r) {
    return 2 * PI * r;
}

int main() {
    double radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    cout << "Area: " << circleArea(radius) << endl;
    cout << "Circumference: " << circleCircumference(radius) << endl;

    return 0;
}
