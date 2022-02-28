#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++; // count the frequency of each element
    }
    int count = 0;
    for (auto i : mp)
    {
        if (i.second > (n / 2))
        {
            count = 1;
            cout << "Majority Element is: " << i.first << endl;
            break;
        }
    }
    if (count == 0)
    {
        cout << "No Majority element" << endl;
    }
}

int main()
{
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajority(arr, n);

    return 0;
}
