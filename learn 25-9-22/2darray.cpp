#include <iostream>
using namespace std;

int main(){

    int marks[3][4] = {
        {80, 75, 76, 75},
        {54, 72, 56, 70},
        {65, 85, 35, 59}
    };

    cout << "Marks: " << marks[1][3] << endl;

    return 0;
}