#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, int age)
    : name(name), age(age) {}

void Person::greet() const {
    std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
}

void Person::setname(const std::string& name) {
    this->name = name;
}

std::string Person::getname() const {
    return this->name;
}

void Person::setage(const int& age) {
    this->age = age;
}

int Person::getage() const {
    return this->age;
}