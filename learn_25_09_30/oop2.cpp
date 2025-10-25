#include <iostream>
using namespace std;

class Persona {
    public:
    string lastname;
    string firstname;
    int age;

    Persona() {}

    Persona(string first, string last, int age) {
        firstname = first;
        lastname  = last;
        age = age;
    }

    void printMe() {
        cout << firstname << " " << lastname << " " << endl;
    }

    void setFirstname(string name) {
        firstname = name;
    }
    void getFirstname(string name) {
        cout << firstname;
    }

    void setLastname(string name) {
        lastname = name;
    }
    void getLastname(string name) {
        cout << lastname;
    }
};

class Student: Person {}

int main() {
    // code
    Persona person1 ("Ange", "Mugisha", 15);

    Persona person2 {"Peter", "Neza", 18};

    Persona person3 = {"Mary", "Keza", 20};

    Persona *person4 = new Persona("Arlene", "Ishimwe", 14);

    Persona person5;
    person5.firstname = "Samuel";
    person5.lastname = "Byringiro";
    person5.age = 14;

    cout << "Printing all personality: \n";
    person1.printMe();
    person2.printMe();
    person3.printMe();
    person4->printMe();
    person5.printMe();

    delete person4;
    return 0;
}