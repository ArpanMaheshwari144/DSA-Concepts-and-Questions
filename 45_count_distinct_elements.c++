#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 10, 15, 5, 4, 5};

    unordered_set<int> s;
    for (int elements : arr)
    {
        s.insert(elements);
    }
    cout << "Count of distinct elements are: " << s.size();

    return 0;
}