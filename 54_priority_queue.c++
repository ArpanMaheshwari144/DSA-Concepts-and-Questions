#include <bits/stdc++.h>
using namespace std;

int main()
{
    // by default it is a max-heap
    priority_queue<int> pq;

    // it is a min-heap
    // priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(15);
    pq.push(10);
    cout << pq.size() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}