#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {5, 10, 15, 5};
    int arr2[] = {10, 15, 4, 5};

    unordered_set<int> s;
    for (int x : arr1)
    {
        s.insert(x);
    }
    for (int y : arr2)
    {
        s.insert(y);
    }
    cout << s.size();

    return 0;
}