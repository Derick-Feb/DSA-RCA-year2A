#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int nextindex;
    int capacity;

public:
    Stack()
    {
        this->capacity = 4;
        arr = new int[capacity];
        nextindex = 0;
    }

    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        nextindex = 0;
    }

    int size() { return nextindex; }

    bool isEmpty()
    {
        return nextindex == 0;
    }

    void push(int ele)
    {
        if (nextindex == capacity)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        arr[nextindex] = ele;
        nextindex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty";
            return;
        }

        nextindex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return 0;
        }

        return arr[nextindex - 1];
    }

    void display()
    {
        while (!isEmpty())
        {
            cout << top() << endl;
            pop();
        }
    }
};

int main()
{

    Stack s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    Stack s2(10);
    for (int i = 1; i <= 10; i++)
    {
        s2.push(i);
    }

    /// print content of stack
    while (!s2.isEmpty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }
    cout << s2.size() << endl;

    return 0;
}
