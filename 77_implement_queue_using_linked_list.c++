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

// we can use 'struct' also instead of 'class'
class Queue
{
public:
    struct Node *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int key)
    {
        struct Node *newNode = new Node(key);
        newNode->data = key;
        newNode->next = NULL;

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << key << " has been inserted successfully." << endl;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty";
            return;
        }
        cout << front->data << " is being deleted " << endl;

        // if there is only one node
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
    }

    void print()
    {
        if ((front == NULL) && (rear == NULL))
        {
            cout << "Queue is empty" << endl;
            return;
        }

        struct Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "After insertion Queue ==> ";
    q.print();

    q.dequeue();
    q.dequeue();

    cout << "After deletion Queue ==> ";
    q.print();

    return 0;
}