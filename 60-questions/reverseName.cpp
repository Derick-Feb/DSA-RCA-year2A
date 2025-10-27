#include <iostream>
#include <string>
using namespace std;

void reverseName(string first, string last) {
    cout << "Name in reverse is: " << last << " " << first << endl;
}

int main() {
    string firstName, lastName;
    cout << "Input First Name: ";
    cin >> firstName;
    cout << "Input Last Name: ";
    cin >> lastName;

    reverseName(firstName, lastName);
    return 0;
}
