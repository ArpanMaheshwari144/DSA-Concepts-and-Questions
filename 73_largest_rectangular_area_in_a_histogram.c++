#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(int arr[], int n)
{
    vector<int> ps(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ps[i] = -1;
        }
        else
        {
            ps[i] = s.top();
        }
        s.push(i);
    }
    return ps;
}

vector<int> nextSmaller(int arr[], int n)
{
    vector<int> ns(n);
    stack<int> s;
    int pseudoIndex = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ns[i] = pseudoIndex;
        }
        else
        {
            ns[i] = s.top();
        }
        s.push(i);
    }
    return ns;
}

int maxAreaHistogram(int arr[], int n)
{
    int maxAns = 0;
    vector<int> ps = prevSmaller(arr, n);
    vector<int> ns = nextSmaller(arr, n);

    for (int i = 0; i < n; i++)
    {
        int curr = (ns[i] - ps[i] - 1) * arr[i];
        maxAns = max(maxAns, curr);
    }
    return maxAns;
}

int main()
{
    int arr[] = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = maxAreaHistogram(arr, n);
    cout << "Largest rectangular rae in a histogram is: " << ans;

    return 0;
}