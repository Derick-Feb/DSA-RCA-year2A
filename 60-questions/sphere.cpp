#include <iostream>
#define PI 3.14
using namespace std;

double sphereVolume(double radius) {
    return (4.0 / 3) * PI * radius * radius * radius;
}

int main() {
    double r;
    cout << "Enter the radius of the sphere: ";
    cin >> r;
    cout << "Volume of the sphere is: " << sphereVolume(r) << endl;
    return 0;
}
