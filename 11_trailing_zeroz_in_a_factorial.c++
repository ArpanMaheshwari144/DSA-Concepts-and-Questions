#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        res = res + n / i;
    }
    cout << "Number of trailing zeros are: " << res;

    return 0;
}