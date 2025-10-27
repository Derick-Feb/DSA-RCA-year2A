#include <iostream>
using namespace std;

struct Person {
    string firstname;
    string lastname;
    int age;

    Person() {}

    Person(string first, string last, int age) {
        firstname = first;
        lastname  = last;
        age = age;
    }

    void printMe() {
        cout << firstname << " " << lastname << " " << endl;
    }
};

int main() {
    // code
    Person person1 ("Ange", "Mugisha", 15);

    Person person2 {"Peter", "Neza", 18};

    Person person3 = {"Mary", "Keza", 20};

    Person *person4 = new Person("Arlene", "Ishimwe", 14);

    Person person5;
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