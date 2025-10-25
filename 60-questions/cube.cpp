#include <iostream>
using namespace std;

int cubeVolume(int side) {
    return side * side * side;
}

int main() {
    int side;
    cout << "Enter side of the cube: ";
    cin >> side;

    cout << "Volume of the cube: " << cubeVolume(side) << endl;
    return 0;
}
