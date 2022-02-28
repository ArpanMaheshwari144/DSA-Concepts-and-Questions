#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> arr, int n)
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

vector<int> nextSmaller(vector<int> arr, int n)
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

int maxAreaHistogram(vector<int> arr, int n)
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

int maxAreaRectangleInBinaryMatrix(vector<vector<int>> arr)
{
    vector<int> currRow = arr[0];
    int maxAns = maxAreaHistogram(currRow, arr.size());
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                currRow[j] += 1;
            }
            else
            {
                currRow[j] = 0;
            }
        }

        int currAns = maxAreaHistogram(currRow, arr.size());
        maxAns = max(maxAns, currAns);
    }
    return maxAns;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0},
    };

    int ans = maxAreaRectangleInBinaryMatrix(arr);
    cout << ans;

    return 0;
}