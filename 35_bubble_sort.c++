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
    int arr[] = {4, 3, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr, j + 1, j);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    cout << "\nAfter sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}