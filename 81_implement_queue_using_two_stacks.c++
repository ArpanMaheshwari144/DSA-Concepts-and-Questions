#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int data)
    {
        s1.push(data);
    }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int ans = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int getFront()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int ans = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
};

int main()
{
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Popped element is: " << q.pop() << endl;
    cout << "Popped element is: " << q.pop() << endl;
    cout << "Front element is: " << q.getFront() << endl;

    return 0;
}