#include <iostream>
#include <string>
using namespace std;

class Animal {
    protected:
        string name = "Animal";
        int age = 0;

    public:
        Animal(string n, int a): name(n), age(a) {}
        ~Animal() {
            cout << "Destroying Animal: " << name << endl;
        }

        virtual void printInfo() {
            cout << "Animal: " << name << ", age: " << age << endl;
        }

        virtual string makeSound() {
            return "Animal sound";
        }
};

class Dog: public Animal {
    string breed;

    public:
        Dog(string n, int a, string b) : Animal(n, a), breed(b) {}
        ~Dog() {
            cout << "Destroying Dog: " << name << endl;
        }

        void printInfo() override {
            cout << "Dog: " << name << ", breed: " << breed << ", age: " << age << endl;
        }

        string makeSound() override {
            return "Woof!";
        }
};

class Cat: public Animal {
    string color;

    public:
        Cat(string n, int a, string c) : Animal(n, a), color(c) {}
        ~Cat() {
            cout << "Destroying Cat: " << name << endl;
        }

        void printInfo() override {
            cout << "Cat: " << name << ", color: " << color << ", age: " << age << endl;
        }

        string makeSound() override {
            return "Meow!";
        }
};

int main(){

    Dog myDog("Buddy", 3, "Golden Retriever");
    myDog.printInfo();
    cout << "Sound: " << myDog.makeSound() << endl;

    Cat myCat("Whiskers", 2, "Tabby");
    myCat.printInfo();
    cout << "Sound: " << myCat.makeSound() << endl;

    Animal* animals[2] = { &myDog, &myCat };
    for (Animal* animal : animals) {
        animal->printInfo();
        cout << "Sound: " << animal->makeSound() << endl;
    }

    delete animals[0];
    delete animals[1];

    return 0;
}