#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;

    const auto myConstant = "42";

    // myConstant = "43"; // This line would cause a compilation error

    cout << "The constant value is: " << myConstant << endl;
    return 0;
}
