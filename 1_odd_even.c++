#include <bits/stdc++.h>
using namespace std;

int main()
{

    // By using modulo
    // int a;
    // cout << "Enter a number: ";
    // cin >> a;
    // if (a % 2 == 0)
    // {
    //     cout << "Number is even";
    // }
    // else
    // {
    //     cout << "Number is odd";
    // }

    // OR

    // By using Bit Masking
    int a;
    cout << "Enter a number: ";
    cin >> a;
    if (a & 1 != 0)
    {
        // 101 & 001 -> 001(Number is odd)
        cout << "Number is odd";
    }
    else
    {
        // 110 & 001 -> 000(Number is even)
        cout << "Number is even";
    }
    return 0;
}