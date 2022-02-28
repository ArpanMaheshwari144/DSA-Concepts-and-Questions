#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int k = 1; // index start from 0(LSB) bcoz of k and position 1 par set a bit means updating it to 1.
    cout << ((1 << k) | n);

    return 0;
}