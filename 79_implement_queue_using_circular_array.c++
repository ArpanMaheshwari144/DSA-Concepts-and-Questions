#include <bits/stdc++.h>
using namespace std;

#define size 100

// TC of enqueue -> O(1) and for dequeue -> O(1)
class CircularArrayQueue
{
public:
    int arr[size];
    int N;
    int front = -1, rear = -1;

    CircularArrayQueue(int n)
    {
        this->N = n;
    }

    void enqueue(int data)
    {
        // agar rear ke turant baad front aa jaa raha hai to queue full hai
        if ((rear + 1) % N == front)
        {
            return;
        }

        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % N;
        arr[rear] = data;
    }

    int dequeue()
    {
        if (front == -1)
        {
            throw std::underflow_error("Queue is empty");
        }
        int result = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }
        return result;
    }

    int getFront()
    {
        if (rear == -1)
        {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }

    void isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
    }

    void isFull()
    {
        if ((rear + 1) % N == front)
        {
            cout << "Queue is full" << endl;
            return;
        }
    }

    void print()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // bcoz rear = -1 so we start the loop form 0 and end to rear+1
        for (int i = front; i < rear + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularArrayQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "After insertion Queue ==> ";
    q.print();

    q.isFull();

    q.dequeue();
    q.dequeue();

    cout << "After deletion Queue ==> ";
    q.print();

    q.isEmpty();

    cout << "Front element ==> " << q.getFront() << endl;

    return 0;
}