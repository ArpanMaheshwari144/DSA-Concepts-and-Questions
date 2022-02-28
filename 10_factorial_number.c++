#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i;
    }
    cout << res;

    return 0;
}