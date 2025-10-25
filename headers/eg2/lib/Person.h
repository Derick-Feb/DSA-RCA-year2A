#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
    std::string name;
    int age;

    public:
        Person(const std::string& name, int age);
        void greet() const;

        void setname(const std::string& name);
        std::string getname() const;

        void setage(const int& age);
        int getage() const;
};

#endif