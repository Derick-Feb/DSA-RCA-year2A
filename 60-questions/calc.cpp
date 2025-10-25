#include <iostream>
#include <iomanip>

using namespace std;

namespace arithmetic {
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) {
        if(b == 0)
            throw runtime_error("Error: dividing by zero!");
            
            return a / b;
        }
        
    int modulo(int a, int b) { 
        if(b == 0)
            throw runtime_error("Error: Modulus by zero!");

        return a % b; 
    }
}

int main() {
    int choice, num1, num2;

    cout << "\nMenu\n";
    cout << setw(5) << "1. Add\n";
    cout << setw(5) << "2. Subtract\n";
    cout << setw(5) << "3. Multiply\n";
    cout << setw(5) << "4. Divide\n";
    cout << setw(5) << "5. Modulus\n";
    
    cout << "\nEnter a choice:";
    cin >> choice;

    cout << "\nEnter two numbers:";
    cin >> num1 >> num2;

    int result;
    switch(choice){
        case 1: result = arithmetic::add(num1, num2); break;
        case 2: result = arithmetic::subtract(num1, num2); break;
        case 3: result = arithmetic::multiply(num1, num2); break;
        case 4:
            try {
                result = arithmetic::divide(num1, num2); break;
            }
            catch(const runtime_error& e){
                cout << e.what() << endl;
            }
        case 5:
            try {
                result = arithmetic::modulo(num1, num2); break;
            }
            catch(const exception& e){
                cout << e.what() << endl;
            }
        default: cout << "Invalid choice!" << endl;
    }

    cout << "Result: " << result << endl;

    return 0;
}