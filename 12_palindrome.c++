#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, digit, rev = 0;
    cout << "Enter a number: ";
    cin >> n;
    int copy_n = n;
    while (n != 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    if (copy_n == rev)
    {
        cout << "Number is palindrome";
    }
    else
    {
        cout << "Number is not palindrome";
    }

    return 0;
}