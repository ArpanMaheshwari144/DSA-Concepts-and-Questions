#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "First element: " << q.front() << endl;
    cout << "Last element: " << q.back() << endl;
    q.pop(); // pop() return's void
    cout << "First element: " << q.front() << endl;

    cout << "Is Queue empty: ";
    if (q.empty())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}