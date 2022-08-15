#include <bits/stdc++.h>
using namespace std;

int wineSelling(vector<int> &a)
{
    int n = a.size();
    int buy = 0, sell = 0;
    int ans = 0;
    while (buy < n && sell < n)
    {
        while (a[buy] <= 0)
        {
            buy++;
            if (buy == n)
            {
                return ans;
            }
        }
        while (a[sell] >= 0)
        {
            sell++;
            if (sell == n)
            {
                return ans;
            }
        }
        if (abs(a[buy]) >= abs(a[sell]))
        {
            ans += abs(buy - sell) * abs(a[sell]);
            a[buy] += a[sell];
            a[sell] = 0;
        }
        else
        {
            ans += abs(buy - sell) * abs(a[buy]);
            a[sell] += a[buy];
            a[buy] = 0;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, -4, 1, -3, 1};
    cout << wineSelling(arr);

    return 0;
}