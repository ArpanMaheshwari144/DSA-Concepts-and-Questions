#include <bits/stdc++.h>
using namespace std;

// Find the maximum profit you can achieve. You may complete as many transactions as you like(buy one and sell one share of the stock multiple times).
// You may not engage in multiple transactions simultaneously(you must sell the stock before you buy again).

int main()
{
    int arr[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int profit = 0;

    // start for-loop from i = 1 bcoz if condition has i or i-1 and we checking whose smaller if we start for loop from i = 0 so i-1 does not exist in the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }

    cout << "Maximum Profit is: " << profit;

    return 0;
}