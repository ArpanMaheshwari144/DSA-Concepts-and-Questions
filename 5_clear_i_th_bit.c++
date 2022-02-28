#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int k = 1; // index start from 1(LSB) bcoz of k-1 and position 1 par clear a bit means updating it to 0.
    cout << (n & (~(1 << (k - 1))));

    return 0;
}