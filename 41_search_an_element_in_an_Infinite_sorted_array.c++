#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(int arr[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int searchInfinite(int arr[], int key)
{
    int low = 0, high = 1;
    while (arr[high] < key)
    {
        low = high;
        high = 2 * high;
    }
    return binarySearchIterative(arr, key, low, high);
}

int main()
{
    int arr[] = {1, 3, 7, 8, 12, 14, 20, 21, 25, 29, 30, 31, 41, 50, 58, 72, 96, 100, 101, 102, 110, 111, 201, 290, 300, 310, 350, 390, 490, 590, 600}; // infinite sorted array
    int key = 590;

    int ans = searchInfinite(arr, key);
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