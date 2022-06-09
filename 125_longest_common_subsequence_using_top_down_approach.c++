#include <bits/stdc++.h>
using namespace std;

int lcs(int m, int n, string a, string b, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (a[m - 1] == b[n - 1])
    {
        return dp[m][n] = 1 + lcs(m - 1, n - 1, a, b, dp);
    }
    else
    {
        return dp[m][n] = max(lcs(m, n - 1, a, b, dp), lcs(m - 1, n, a, b, dp));
    }
}

int main()
{
    string a = "ABCAB";
    string b = "AECB";
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "LCS is: " << lcs(m, n, a, b, dp);

    return 0;
}