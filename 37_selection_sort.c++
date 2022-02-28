// Selection sort -> always select minimum element in the array and place that in 0th index in the array

#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int arr[] = {4, 1, 9, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n - 1; i++)
    {
        int min = i; // storing index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // storing index
            }
        }
        if (min != i)
        {
            swap(arr, min, i);
        }
    }

    cout << "\nAfter sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}