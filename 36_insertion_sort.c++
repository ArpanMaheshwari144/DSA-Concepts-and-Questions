#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {8, 4, 1, 5, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "\nAfter sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}