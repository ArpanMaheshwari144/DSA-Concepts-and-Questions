#include <bits/stdc++.h>
using namespace std;

#define size 100

// TC of enqueue -> O(1) and for dequeue -> O(n)
class Queue
{
public:
    int arr[size];
    int capacity;
    int rear;

    Queue(int n)
    {
        capacity = n;
        rear = -1;
    }

    void enqueue(int data)
    {
        if (rear == capacity - 1)
        {
            throw std::overflow_error("Queue is full");
        }
        rear++;
        arr[rear] = data;
    }

    int dequeue()
    {
        if (rear == -1)
        {
            throw std::underflow_error("Queue is empty");
        }
        int result = arr[0];
        for (int i = 0; i < rear; i++)
        {
            arr[i] = arr[i + 1];
        }
        rear--;
        return result;
    }

    int getFront()
    {
        if (rear == -1)
        {
            throw std::underflow_error("Queue is empty");
        }
        return arr[0];
    }

    void print()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // bcoz rear = -1 so we start the loop form 0 and end to rear+1
        for (int i = 0; i < rear + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "After insertion Queue ==> ";
    q.print();

    q.dequeue();
    q.dequeue();

    cout << "\nAfter deletion Queue ==> ";
    q.print();

    cout << "\nFront element ==> " << q.getFront();

    return 0;
}

// *******************************************************************************************

// #include <bits/stdc++.h>
// using namespace std;

// #define size 100

// // TC of enqueue -> O(1) and for dequeue -> O(n)
// class Queue
// {
// public:
//     int arr[size];
//     int capacity;
//     int front, rear;

//     Queue(int n)
//     {
//         capacity = n;
//         rear = -1;
//     }

//     void enqueue(int data)
//     {
//         if (rear == capacity - 1)
//         {
//             cout << "Queue is full";
//             return;
//         }
//         else
//         {
//             rear++;
//             arr[rear] = data;
//         }
//         return;
//     }

//     void dequeue()
//     {
//         if (rear == -1)
//         {
//             cout << "Queue is empty";
//             return;
//         }
//         else
//         {
//             for (int i = 0; i < rear; i++)
//             {
//                 arr[i] = arr[i + 1];
//             }
//             rear--;
//         }
//         return;
//     }

//     void getFront()
//     {
//         if (rear == -1)
//         {
//             cout << "Queue is empty";
//             return;
//         }
//         else
//         {
//             cout << "Front element ==> " << arr[0];
//         }
//     }

//     void print()
//     {
//         if (rear == -1)
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         else
//         {
//             // bcoz rear = -1 so we start the loop form 0 and end to rear+1
//             for (int i = 0; i < rear + 1; i++)
//             {
//                 cout << arr[i] << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
// };

// int main()
// {
//     Queue q(5);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);

//     cout << "After insertion Queue ==> ";
//     q.print();

//     q.enqueue(6);

//     q.dequeue();
//     q.dequeue();

//     cout << "\nAfter deletion Queue ==> ";
//     q.print();

//     q.getFront();

//     return 0;
// }