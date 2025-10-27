#include <iostream>
#include "rect.h"

int main() {
    Rectangle r1(5.0, 3.0);
    Rectangle r2(7.5, 2.5);
    Rectangle r3(4.0, 6.0);

    std::cout << "Area of r1: " << r1.area() << std::endl;
    std::cout << "Area of r2: " << r2.area() << std::endl;
    std::cout << "Area of r3: " << r3.area() << std::endl;

    return 0;
}
