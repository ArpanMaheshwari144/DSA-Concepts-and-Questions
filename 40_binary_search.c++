#include <bits/stdc++.h>
using namespace std;

//***************BINARY SEARCH ITERATIVE********************************
int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
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

//***************BINARY SEARCH RECURSIVE********************************
int binarySearchRecursive(int arr[], int n, int key, int low, int high)
{
    // If element is not present
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (key > arr[mid])
    {
        return binarySearchRecursive(arr, n, key, mid + 1, high);
    }
    return binarySearchRecursive(arr, n, key, low, mid - 1);
}

int main()
{
    int arr[] = {-4, -1, 3, 7, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 11; // find key and return the index

    // int ans = binarySearchIterative(arr, n, key);
    // if (ans != -1)
    // {
    //     cout << "Element found at index: " << ans;
    // }
    // else
    // {
    //     cout << "Element is not found";
    // }

    int ans = binarySearchRecursive(arr, n, key, 0, n - 1);
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