/* A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). */

#include <bits/stdc++.h>
using namespace std;

// Function to find Majority element in an array - TC -> O(n^2)
void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > n / 2)
    {
        cout << "Majority Element is: " << arr[index] << endl;
    }
    else
    {
        cout << "No Majority Element" << endl;
    }
}

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMajority(arr, n);

    return 0;
}
