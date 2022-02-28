#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n)
{
    int ansIndex = 0; // index 0 stores in ansIndex
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[ansIndex])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            ansIndex = i;
            count = 1;
        }
    }
    return arr[ansIndex];
}

bool isMajority(int arr[], int n, int candidate)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }
    if (count > (n / 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printMajority(int arr[], int n)
{
    int candidate = majorityElement(arr, n);

    if (isMajority(arr, n, candidate))
    {
        cout << "Majority Element is: " << candidate;
    }
    else
    {
        cout << "No majority element";
    }
}

int main()
{
    int arr[] = {1, 1, 3, 3, 3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMajority(arr, n);

    return 0;
}