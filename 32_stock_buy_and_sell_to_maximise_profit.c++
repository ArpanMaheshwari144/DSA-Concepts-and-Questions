#include <bits/stdc++.h>
using namespace std;

// only one stock buy at a time and sell the stock if you buy another one and find maximum profit in between you buy and sell the stock

int main()
{
    int arr[] = {3, 1, 4, 8, 7, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxProfit = 0;
    int min_so_far = arr[0];

    for (int i = 0; i < n; i++)
    {
        min_so_far = min(min_so_far, arr[i]);
        int profit = arr[i] - min_so_far;
        maxProfit = max(maxProfit, profit);
    }

    cout << "Maximum Profit is: " << maxProfit;

    return 0;
}