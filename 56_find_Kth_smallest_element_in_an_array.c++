#include <bits/stdc++.h>
using namespace std;

int kThSmallest(int arr[], int n, int k)
{
    // it is a max-heap
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {20, 60, 30, 50, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << kThSmallest(arr, n, k);

    return 0;
}