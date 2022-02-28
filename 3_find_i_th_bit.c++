#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int k = 2; // index start from 1(LSB) bcoz of k-1 and position 3 par konsi bit hai 0(NOT SET) ya 1(SET)

    if (n & (1 << (k - 1)))
    {
        cout << "SET";
    }
    else
    {
        cout << "NOT SET";
    }

    return 0;
}