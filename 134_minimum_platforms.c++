#include <bits/stdc++.h>
using namespace std;

int findPlatform(string arr[], string dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int count = 0, ans = 0, i = 0, j = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            ans = max(ans, count);
            i++;
        }
        else if (arr[i] > dep[j])
        {
            count--;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    string arr[] = {"0900", "0940", "0950", "1100", "1500", "1800"};
    string dep[] = {"0910", "1200", "1120", "1130", "1900", "2000"};

    cout << "Minimum number of platforms required is: " << findPlatform(arr, dep, n);

    return 0;
}