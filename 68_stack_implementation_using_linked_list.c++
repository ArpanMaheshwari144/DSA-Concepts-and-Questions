#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class MyStack
{
    struct Node *head;
    int size;

public:
    MyStack(int capacity)
    {
        head = NULL;
        size = 0;
    }

    void push(int data)
    {
        struct Node *temp = new Node(data);
        temp->next = head;
        size++;
        head = temp;
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack is empty";
            exit(0);
        }
        return head->data;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty";
            exit(0);
        }
        int res = head->data;
        head = head->next;
        size--;
        return res;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int mySize()
    {
        return size;
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
    cout << "Size of the stack is: " << s.mySize() << endl;

    if (!s.isEmpty())
    {
        cout << "Stack is not empty" << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }

    cout << "Elements present in stack: ";
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}