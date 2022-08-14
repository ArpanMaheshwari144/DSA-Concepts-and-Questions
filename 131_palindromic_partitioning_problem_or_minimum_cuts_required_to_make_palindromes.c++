#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
        {
            return false;
        }
    }
    return true;
}

int palindromicPartition(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int gap = 1; gap < n; gap++)
    {
        for (int row = 0, col = gap; row < n - gap; row++, col++)
        {
            if (isPalindrome(str, row, col))
            {
                dp[row][col] = 0;
            }
            else
            {
                dp[row][col] = INT_MAX;
                for (int k = row; k < col; k++)
                {
                    dp[row][col] = min(dp[row][col], 1 + dp[row][k] + dp[k + 1][col]);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string str = "aaabba";
    cout << palindromicPartition(str);

    return 0;
}