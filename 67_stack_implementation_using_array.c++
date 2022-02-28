#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    // this is the way we represent the array
    int *a;
    int top;
    int capacity;

public:
    MyStack(int capacity)
    {
        this->capacity = capacity;
        top = -1;

        // and initialize the array here
        a = new int[capacity];
    }

    void push(int data)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full";
            return;
        }
        top++;
        a[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            exit(0);
        }
        int res = a[top];
        top--;
        return res;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            exit(0);
        }
        return a[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    MyStack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() << " Popped from stack" << endl;
    cout << "Size of the stack is: " << s.size() << endl;

    if (!s.isEmpty())
    {
        cout << "Stack is not empty" << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }

    if (!s.isFull())
    {
        cout << "Stack is not full" << endl;
    }
    else
    {
        cout << "Stack is full" << endl;
    }

    cout << "Elements present in stack: ";
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}