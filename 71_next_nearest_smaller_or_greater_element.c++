#include <bits/stdc++.h>
using namespace std;

void nextNearestSmallerElement(int arr[], int n)
{
    //*****************BY THE HELP OF STACK*****************
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    //*****************BY THE HELP OF DEQUE*****************
    // deque<int> dq;
    // vector<int> ans;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     while (!dq.empty() && dq.front() >= arr[i])
    //     {
    //         dq.pop_front();
    //     }

    //     if (dq.empty())
    //     {
    //         ans.push_back(-1);
    //     }
    //     else
    //     {
    //         ans.push_back(dq.front());
    //     }
    //     dq.push_front(arr[i]);
    // }
    // for (int i = ans.size() - 1; i >= 0; i--)
    // {
    //     cout << ans[i] << " ";
    // }
}

void nextNearestGreaterElement(int arr[], int n)
{
    //*****************BY THE HELP OF STACK*****************
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    //*****************BY THE HELP OF DEQUE*****************
    // deque<int> dq;
    // vector<int> ans;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     while (!dq.empty() && dq.front() <= arr[i])
    //     {
    //         dq.pop_front();
    //     }

    //     if (dq.empty())
    //     {
    //         ans.push_back(-1);
    //     }
    //     else
    //     {
    //         ans.push_back(dq.front());
    //     }
    //     dq.push_front(arr[i]);
    // }
    // for (int i = ans.size() - 1; i >= 0; i--)
    // {
    //     cout << ans[i] << " ";
    // }
}

int main()
{
    int arr[] = {3, 10, 5, 1, 15, 10, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The next nearest smaller elements are: ";
    nextNearestSmallerElement(arr, n);

    cout << "\nThe next nearest greater elements are: ";
    nextNearestGreaterElement(arr, n);

    return 0;
}