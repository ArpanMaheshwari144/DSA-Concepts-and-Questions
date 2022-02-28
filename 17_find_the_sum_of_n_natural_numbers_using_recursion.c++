#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n == 0)
    {
        cout << n << " is not a natural number";
        exit(0);
    }
    cout << "The sum of first " << n << " natural numbers are: " << sum(n);

    return 0;
}