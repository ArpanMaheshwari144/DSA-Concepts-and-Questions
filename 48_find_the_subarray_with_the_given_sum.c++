#include <bits/stdc++.h>
using namespace std;

void subArraySum(int arr[], int n, int sum)
{
    int currSum = 0;
    int start = 0;
    int end = -1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum - sum == 0)
        {
            start = 0;
            end = i;
            break;
        }
        if (mp.find(currSum - sum) != mp.end())
        {
            start = mp[currSum - sum] + 1;
            end = i;
            break;
        }
        mp[currSum] = i;
    }
    if (end == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << "(" << start << ", " << end << ")";
    }
}

int main()
{
    int arr[] = {10, 15, -5, 15, -10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 5;

    subArraySum(arr, n, sum);
    return 0;
}