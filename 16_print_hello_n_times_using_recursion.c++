#include <bits/stdc++.h>
using namespace std;

int printHello(int n)
{
    if (n == 0)
    {
        return n;
    }

    cout << "Hello\n";
    printHello(n - 1);
    return 0;
}

int main()
{
    printHello(6);

    return 0;
}