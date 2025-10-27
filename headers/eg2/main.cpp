#include <iostream>
#include "lib/Person.h"

int main() {

    Person p("Derick", 21);
    p.greet();

    p.setname("Eric");
    p.setage(22);

    p.greet();

    return 0;
}