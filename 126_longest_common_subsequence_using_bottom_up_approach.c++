#include <bits/stdc++.h>
using namespace std;

int lcs(int m, int n, string a, string b, vector<vector<int>> &dp)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string a = "ABCAB";
    string b = "AECB";
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    cout << "LCS is: " << lcs(m, n, a, b, dp);

    return 0;
}