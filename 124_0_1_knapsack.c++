#include <bits/stdc++.h>
using namespace std;

int knapsackMemoizationOrTopDown(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] > W)
    {
        return dp[n][W] = knapsackMemoizationOrTopDown(wt, val, W, n - 1, dp);
    }
    else
    {
        return dp[n][W] = max(val[n - 1] + knapsackMemoizationOrTopDown(wt, val, W - wt[n - 1], n - 1, dp), knapsackMemoizationOrTopDown(wt, val, W, n - 1, dp));
    }
}

int main()
{
    int W = 10;
    int n = 4;
    vector<int> wt = {1, 3, 4, 6};
    vector<int> val = {20, 30, 10, 50};
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << knapsackMemoizationOrTopDown(wt, val, W, n, dp);

    return 0;
}