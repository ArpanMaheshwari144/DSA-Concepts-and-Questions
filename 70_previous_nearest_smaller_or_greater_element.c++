#include <bits/stdc++.h>
using namespace std;

void previousNearestSmallerElement(int arr[], int n)
{
    //*****************BY THE HELP OF STACK*****************
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            cout << "-1"
                 << " ";
        }
        else
        {
            cout << st.top() << " ";
        }
        st.push(arr[i]);
    }

    //*****************BY THE HELP OF DEQUE*****************
    // deque<int> dq;
    // for (int i = 0; i < n; i++)
    // {
    //     while (!dq.empty() && dq.front() >= arr[i])
    //     {
    //         dq.pop_front();
    //     }

    //     if (dq.empty())
    //     {
    //         cout << "-1"
    //              << " ";
    //     }
    //     else
    //     {
    //         cout << dq.front() << " ";
    //     }
    //     dq.push_front(arr[i]);
    // }
}

void previousNearestGreaterElement(int arr[], int n)
{
    //*****************BY THE HELP OF STACK*****************
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            cout << "-1"
                 << " ";
        }
        else
        {
            cout << st.top() << " ";
        }
        st.push(arr[i]);
    }

    //*****************BY THE HELP OF DEQUE*****************
    // deque<int> dq;
    // for (int i = 0; i < n; i++)
    // {
    //     while (!dq.empty() && dq.front() <= arr[i])
    //     {
    //         dq.pop_front();
    //     }

    //     if (dq.empty())
    //     {
    //         cout << "-1"
    //              << " ";
    //     }
    //     else
    //     {
    //         cout << dq.front() << " ";
    //     }
    //     dq.push_front(arr[i]);
    // }
}

int main()
{
    int arr[] = {4, 10, 5, 18, 3, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The previous nearest smaller elements are: ";
    previousNearestSmallerElement(arr, n);

    cout << "\nThe previous nearest greater elements are: ";
    previousNearestGreaterElement(arr, n);

    return 0;
}