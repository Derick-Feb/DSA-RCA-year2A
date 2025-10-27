#include <iostream>
#include <string>
#define PI 3.14159265358979323846

using namespace std;

namespace Rectangle {
    const double length = 5.0;
    const double width = 3.0;

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
}

namespace Square {
    const double side = 4.0;

    double area() {
        return side * side;
    }

    double perimeter() {
        return 4 * side;
    }
}

namespace Circle {
    const double radius = 2.0;

    double area() {
        return PI * radius * radius;
    }

    double circumference() {
        return 2 * PI * radius;
    }
}

// by default using Rectangle namespace
using namespace Rectangle;

int main() {
    
    cout << "Rectangle Area: " << area() << endl;
    cout << "Rectangle Perimeter: " << perimeter() << endl;

    cout << "Square Area: " << Square::area() << endl;
    cout << "Square Perimeter: " << Square::perimeter() << endl;

    cout << "Circle Area: " << Circle::area() << endl;
    cout << "Circle Circumference: " << Circle::circumference() << endl;

    string s = R"(This is a raw string literal
that can span multiple lines
and include "quotes" and \backslashes\ without needing escapes.)";

    return 0;
}
