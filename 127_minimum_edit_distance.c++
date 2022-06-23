#include <bits/stdc++.h>
using namespace std;

int editDistance(string a, string b)
{
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string a = "sunday";
    string b = "saturday";

    cout << "Minimum number of operations(Insertion, Deletion, Replace) to covert " << a << " string to " << b << " is: " << editDistance(a, b);

    return 0;
}