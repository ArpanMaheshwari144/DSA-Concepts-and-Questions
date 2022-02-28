#include <bits/stdc++.h>
using namespace std;

int binarySearchSortedAndRotatedArray(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {20, 30, 40, 50, 60, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 90; // find key and return the index

    int ans = binarySearchSortedAndRotatedArray(arr, n, key);
    if (ans != -1)
    {
        cout << "Element found at index: " << ans;
    }
    else
    {
        cout << "Element is not found";
    }
    return 0;
}