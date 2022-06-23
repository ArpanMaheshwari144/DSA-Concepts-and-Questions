#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], price[j] + dp[i - j - 1]);
        }
    }
    return dp[n];
}

int main()
{
    int n = 8; // length of the rod
    vector<int> price = {1, 5, 6, 9, 11, 12, 14, 16};
    cout << "Maximum profit for cutting the rod is: " << cutRod(price, n);

    return 0;
}