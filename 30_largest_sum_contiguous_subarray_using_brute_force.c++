#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {-5, -4, -2, 6, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    cout << "Maximum sum is: " << maxSum;

    return 0;
}