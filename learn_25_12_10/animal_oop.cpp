#include <iostream>
using namespace std;

class Animal {
    string name;
    int age;

public:
    // initialization list constructor
    Animal(string n, int a) : name(n), age(a) {};  

    // basic abstract methods about animal behavior
    virtual void speak() { cout << "Animal speaking..." << endl; }
    virtual void move() { cout << "Animal moving..." << endl; }
    virtual void eat() { cout << "Animal eating..." << endl; }

    virtual void info() { cout << "Animal Name: " << name << ", Age: " << age << endl; }

    ~Animal() { cout << "Animal killed." << endl; }
};

class DomesticAnimal : public Animal {
    string emotion;

public:
    DomesticAnimal(string n, int a, string em) : Animal(n, a) { this->emotion = em; }

    void speak() override { cout << "Domestic Animal sound..." << endl; }
    void move() override { cout << "Domestic Animal moving around..." << endl; }
    void eat() override { cout << "Domestic Animal eating food..." << endl; }

    void sleep() { cout << "Domestic Animal sleeping..." << endl; }
    void readMaster() { cout << "Domestic Animal reading its master..." << endl; }
    void showEmotion() { cout << "Domestic Animal showing " << this->emotion << " ..." << endl; }

    void info() override {
        cout << "This is a domestic animal." << endl;
        Animal::info();
    }
};

class Dog : public DomesticAnimal {
    string emotion = "happiness";
public:
    Dog(string n, int a, string em) : DomesticAnimal(n, a, em) {}

    void speak() override { cout << "Woof Woof!" << endl; }
    void move() override { cout << "Dog running around..." << endl; }
    void eat() override { cout << "Dog eating dog food..." << endl; }

    void fetch() { cout << "Dog fetching the ball..." << endl; }
    void wagTail() { cout << "Dog wagging its tail..." << endl; }
    void readMaster() { cout << "Dog reading its master enthusiastically..." << endl; }
    void showEmotion() { cout << "Dog showing " << this->emotion << " ..." << endl; }

    void info() override {
        cout << "This is a dog." << endl;
        DomesticAnimal::info();
    }
};

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
