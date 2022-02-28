#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, low);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nAfter sorting the array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}