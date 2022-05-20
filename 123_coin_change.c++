#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, vector<int> &arr, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (n - arr[i] >= 0)
        {
            int subAns = 0;
            if (dp[n - arr[i]] != -1)
            {
                subAns = dp[n - arr[i]];
            }
            else
            {
                subAns = minCoins(n - arr[i], arr, dp);
            }

            if (subAns != INT_MAX && subAns + 1 < ans)
            {
                ans = subAns + 1;
            }
        }
    }
    return dp[n] = ans;
}

int main()
{
    int n = 18;
    vector<int> arr = {7, 5, 1};
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    int ans = minCoins(n, arr, dp);
    cout << "Minimum coins required is: " << ans;

    return 0;
}