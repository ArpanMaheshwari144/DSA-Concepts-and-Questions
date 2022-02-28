#include <bits/stdc++.h>
using namespace std;

// (a + b) % n = (a % n + b % n) % n;
// (a * b) % n = (a % n * b % n) % n;

long long fastPow(long long a, long long b, long long n)
{
    long long res = 1;
    while (b > 0)
    {
        // b & 1 means b % 2
        if ((b & 1) != 0)
        {
            res = (res % n * a % n) % n;
        }
        a = (a % n * a % n) % n;
        b = b >> 1; // b >> 1 means b / 2
    }
    return res;
}

int main()
{
    cout << fastPow(3978432, 5, 1000000007); // (3978432 ^ 5) % 10^9+7

    return 0;
}