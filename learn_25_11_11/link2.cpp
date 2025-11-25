#include <iostream>
using namespace std;

class Student{
    public:
        int code;
        string name;
        string school;
        Student *next;

        Student(int c, string nm, string sch) : code(c), name(nm), school(sch), next(nullptr) {}

        
};

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
