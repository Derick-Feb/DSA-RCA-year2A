#include <iostream>
using namespace std;

/*
 Operations on the Queue:
    1. Dequeue: removing or accessing the element/node at the front (head)
    2. Enqueue: adding an element/node at the rear (tail)
    3. Initialize()
    4. peeek, front: accessing the element/node at the front (head) without removing it
    5. isEmpty
    6. isFull
*/

// implementation of Queue using sequential allocation (array)

template <typename T>

class ArrayQueue
{
    T front, rear;
    int capacity, size;
    T *array;

public:
    ArrayQueue(int n) : front(-1), rear(-1), capacity(n)
    {
        array = new T[capacity];
        size = 0;
    }

    // some getters;
    T getFront() { return array[front]; }
    T getRear() { return array[rear]; }
    int getCapacity() { return capacity; }
    int getSize() { return size; }

    bool isEmpty() { return front == -1; }
    // bool isFull() { return rear == capacity - 1; }
    bool isFull() { return capacity == size; }

    void enlargeCapacity()
    {
        int newCapacity = capacity * 2;
        T *newArray = new T[newCapacity];

        // copy the old elements to the new array
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[(front + i) % capacity];
        }

        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    void enqueue(T el)
    {
        if (isFull())
        {
            cout << "Queue overflow! Enlarging capacity..." << endl;
            enlargeCapacity();
        }

        rear++;
        front = isEmpty() ? 0 : front;
        // front = isEmpty() ? front++ : front;

        array[rear] = el;
    }

    // don't auto complete here
    void dequeue()
    {
        if (isEmpty() || front > rear)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        // if queue has one element left;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void safeDequeue()
    {
        if (isEmpty() || front > rear)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        cout << "Dequeued element: " << array[front] << endl;

        for (int i = front; i < rear; i++)
        {
            array[i] = array[i + 1];
        }

        rear--;
        capacity--;
    }

    int top()
    {
        if (isEmpty() || front > rear)
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        return array[front];
    }

    // this is a helper function to reset the front pointer when the queue becomes empty after dequeuing all elements

    void display()
    {
        if (isEmpty() || front > rear)
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    ~ArrayQueue()
    {
        delete[] array;
    }
};

template <typename G>

class Node
{
public:
    G data;
    Node *next;

    Node(G value) : data(value), next(nullptr) {}
};

template <typename F>

class LinkedListQueue
{
public:
    Node<F> *front, *rear;

    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    F getFront() { return front->data; }
    F getRear() { return rear->data; }

    bool isEmpty() { return front == nullptr; }

    void enqueue(F el)
    {
        Node<F>* newNode = new Node<F>(el);

        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return;
        }

        Node<F> *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = front = nullptr;
        }

        delete temp;
    }

    void display()
    {
        Node<F> *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    F peek() 
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return -1; // or throw an exception
        }

        return front->data;
    }

    void display2()
    {
        while(!isEmpty())
        {
            cout << peek() << " ";
            dequeue();
        }
    }
};

int main()
{

    /*
    Array Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(6); // to check the overflow

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.dequeue(); // to check the underflow

    // using the display function to show the contents of the queue
    */

    LinkedListQueue<int> llq;
    llq.enqueue(1);
    llq.enqueue(2);
    llq.enqueue(3);
    llq.enqueue(4);
    llq.enqueue(5);

    llq.display();

    llq.dequeue();
    llq.dequeue();
    llq.dequeue();

    llq.display();

    return 0;
}
