#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {5, 10, 15, 5, 10};
    int b[] = {15, 10, 4};
    int count = 0;

    unordered_set<int> s;
    for (int x : a)
    {
        s.insert(x);
    }
    for (int y : b)
    {
        if (s.find(y) != s.end())
        {
            count++;
            s.erase(y);
        }
    }
    cout << count;

    return 0;
}