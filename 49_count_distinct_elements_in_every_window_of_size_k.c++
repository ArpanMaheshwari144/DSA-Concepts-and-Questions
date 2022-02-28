#include <bits/stdc++.h>
using namespace std;

void countDistinctElements(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int dist_count = 0;
    for (int i = 0; i < k; i++)
    {
        if (mp[arr[i]] == 0)
        {
            dist_count++;
        }
        mp[arr[i]] += 1;
    }
    cout << dist_count << endl;

    for (int i = k; i < n; i++)
    {
        if (mp[arr[i - k]] == 1)
        {
            dist_count--;
        }
        mp[arr[i - k]] -= 1;

        if (mp[arr[i]] == 0)
        {
            dist_count++;
        }
        mp[arr[i]] += 1;
        cout << dist_count << endl;
    }
}

int main()
{
    int arr[]{1, 2, 2, 1, 3, 1, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    countDistinctElements(arr, n, k);

    return 0;
}