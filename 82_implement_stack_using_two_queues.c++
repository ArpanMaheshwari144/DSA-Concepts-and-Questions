#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    void push(int data)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int front = q1.front();
        q1.pop();
        return front;
    }

    int getFront()
    {
        return q1.front();
    }
};

int main()
{
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Front element is: " << s.getFront() << endl;

    return 0;
}