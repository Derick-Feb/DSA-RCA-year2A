#include <iostream>
#include <string>
using namespace std;

class Shape {
    string name;

protected:
    double dim = 6.0;

public:
    Shape(string n, double d) : name(n), dim(d) {}
    Shape(double d) : dim(d) {}

    virtual double getArea() = 0;
    virtual double perimeter() = 0;

    virtual void printInfo() {
        cout << "Shape of name: " << name << " with dimension: " << dim << endl;
    }

    ~Shape() {}
};

class Triangle : public Shape {
    string name;  // separate from Shape::name
    double height;
    double base;

public:
    // Constructor: keep separate Triangle name optional
    Triangle(double h, double b) : Shape(h) { // call Shape(double d) constructor
        height = h;
        base = b;
    }

    string getName() { return name; }
    void setName(string n) { name = n; }

    double getArea() override { return 0.5 * base * height; }
    double perimeter() override { return 3 * base; } // dummy implementation

    void printInfo() override {
        cout << "Triangle of name: " << name
             << " with height: " << height
             << " and base: " << base << endl;
    }
};

class RightTriangle: public Triangle {
public:
    RightTriangle(double h, double b, double c): Triangle(h, b) {}
};

int main() {
    Triangle t(6, 8);
    t.setName("Tri1");
    t.printInfo();
    cout << "Area: " << t.getArea() << endl;
    cout << "Perimeter: " << t.perimeter() << endl;
}
