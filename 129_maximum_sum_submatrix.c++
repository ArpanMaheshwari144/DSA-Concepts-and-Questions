// Question Link [https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1]

#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int> &sum)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < sum.size(); i++)
    {
        currSum = currSum + sum[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int maxSum = INT_MIN;
    for (int cStart = 0; cStart < C; cStart++)
    {
        vector<int> sum(R, 0);
        for (int cEnd = cStart; cEnd < C; cEnd++)
        {
            for (int row = 0; row < R; row++)
            {
                sum[row] += M[row][cEnd];
            }
            int currMaxSum = kadanes(sum);
            maxSum = max(maxSum, currMaxSum);
        }
    }
    return maxSum;
}

int main()
{
    int R = 4;
    int C = 5;
    vector<vector<int>> M = {{1, 2, -1, -4, -20},
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};
    cout << "Max Sum of submatrix is: " << maximumSumRectangle(R, C, M);

    return 0;
}