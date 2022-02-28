#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();

    cout << "Size: " << s.size() << endl;

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}