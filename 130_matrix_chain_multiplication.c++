#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 2; len < n; len++)
    {
        for (int row = 0, col = len; row < n - len; row++, col++)
        {
            dp[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++)
            {
                dp[row][col] = min(dp[row][col], dp[row][k] + dp[k][col] + arr[row] * arr[k] * arr[col]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n = 5;
    int arr[] = {40, 20, 30, 10, 30};
    cout << "MCM is: " << matrixMultiplication(n, arr);

    return 0;
}