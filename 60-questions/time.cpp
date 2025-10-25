#include <iostream>
#include <ctime>

using namespace std;

void displayTime() {
    time_t now = time(0);
    char *dt = ctime(&now);

    cout << "Current time and date: " << dt << endl;
}

int main() {

    displayTime();

    return 0;
}