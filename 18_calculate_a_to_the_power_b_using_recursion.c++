#include <bits/stdc++.h>
using namespace std;

long long toPower(long long a, long long b)
{
    if (a == 0 && b == 0)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    return toPower(a, b - 1) * a;
}

int main()
{
    long long a, b;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter exponent: ";
    cin >> b;
    cout << a << " to the power " << b << " is: " << toPower(a, b);

    return 0;
}