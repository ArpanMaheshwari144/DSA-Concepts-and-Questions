#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int a = 5;
    // int b = 7;
    // cout << "Before swapping " << a << " and " << b;
    // int temp = a;
    // a = b;
    // b = temp;
    // cout << "\nAfter swapping " << a << " and " << b;

    // OR

    // By using ^(XOR) operator and without using third variable
    int a = 5;
    int b = 7;
    cout << "Before swapping " << a << " and " << b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "\nAfter swapping " << a << " and " << b;

    return 0;
}