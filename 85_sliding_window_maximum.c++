#include <bits/stdc++.h>
using namespace std;

// Brute-Force Approach
// void printKMax(int arr[], int n, int k)
// {
//     int max;
//     for (int i = 0; i <= n - k; i++)
//     {
//         max = arr[i];
//         for (int j = 1; j < k; j++)
//         {
//             if (arr[i + j] > max)
//             {
//                 max = arr[i + j];
//             }
//         }
//         cout << max << " ";
//     }
// }

// Using Priority-Queue Approach
// vector<int> printKMax(int arr[], int n, int k)
// {
//     priority_queue<pair<int, int>> pq;
//     vector<int> ans;

//     // creating maxHeap using first k elements only
//     for (int i = 0; i < k; ++i)
//     {
//         pq.push(make_pair(arr[i], i));
//     }
//     ans.push_back(pq.top().first);

//     // then creating maxHeap from the rest of the elements
//     for (int i = k; i < n; ++i)
//     {
//         // pushing in the priority queue
//         pq.push(make_pair(arr[i], i));

//         // if the index of the top is out of bound of the window size then pop
//         while (pq.top().second <= i - k)
//         {
//             pq.pop();
//         }
//         ans.push_back(pq.top().first);
//     }
//     return ans;
// }

// Using Deque Approach
void printKMax(int arr[], int n, int k)
{
    deque<int> dq;

    // process first k(or first window) elements of array
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            // remove from rear
            dq.pop_back();
        }

        // add new element at rear of queue
        dq.push_back(i);
    }

    // process rest of the elements, i.e form arr[k] to arr[n-1]
    for (; i < n; i++)
    {
        /* the element at the front of the queue is the largest element of previous window, so print it */
        cout << arr[dq.front()] << " ";

        // remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // remove all elements smaller than the currently being added element (removu=ing useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        // add the current element at the rear
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}

int main()
{
    int arr[] = {4, 1, 3, 5, 1, 2, 3, 2, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // window size

    // Brute-Force Approach
    // cout << "Maximum elements are: ";
    // printKMax(arr, n, k);

    // Using Priority-Queue Approach
    // vector<int> ans = printKMax(arr, n, k);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // Using Deque Approach
    cout << "Maximum elements are: ";
    printKMax(arr, n, k);

    return 0;
}