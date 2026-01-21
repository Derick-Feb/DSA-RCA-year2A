#include <iostream>
using namespace std;

void enqueue(int n, int arrQ[], int &front, int &rear, int value) {
    if(rear == n - 1) {
        cout << "Queue overflow" << endl;
        return;
    }

    if(front == -1) {
        front = 0;
    }

    rear++;
    arrQ[rear] = value;

    cout << "Value inserted: " << value << endl;
}

int main() {
    int n = 100;
    int arrQ[n], front = -1, rear = -1;

    enqueue(n, arrQ, front, rear, 10);
    enqueue(n, arrQ, front, rear, 20);
    enqueue(n, arrQ, front, rear, 30);

    return 0;
}
