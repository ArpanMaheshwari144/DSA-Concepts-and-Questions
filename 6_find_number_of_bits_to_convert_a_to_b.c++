#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 22;
    int b = 27;
    int n = a ^ b;
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n - 1);
    }
    cout << count;

    return 0;
}