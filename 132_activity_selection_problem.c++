#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
    int pos;
    int start;
    int end;
};

static bool cmp(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
    {
        // sort according to ending time in ascending order
        return true;
    }
    else if (m1.end > m2.end)
    {
        return false;
    }
    else if (m1.pos < m2.pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<int> ans;
    struct Meeting a[N];
    for (int i = 0; i < N; i++)
    {
        a[i].pos = i + 1;
        a[i].start = S[i];
        a[i].end = F[i];
    }
    sort(a, a + N, cmp);
    // for (int i = 0; i < N; i++)
    // {
    //     cout << a[i].pos << endl;
    //     cout << a[i].start << endl;
    //     cout << a[i].end << endl;
    // }

    int r = a[0].end;
    ans.push_back(a[0].pos);
    for (int i = 1; i < N; i++)
    {
        if (a[i].start > r)
        {
            ans.push_back(a[i].pos);
            r = a[i].end;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};

    vector<int> ans = maxMeetings(N, S, F);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}