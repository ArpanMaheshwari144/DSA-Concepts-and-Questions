#include <bits/stdc++.h>
using namespace std;

int matrixPath(int n, int m)
{
    if (n == 1 || m == 1)
    {
        return 1;
    }
    return matrixPath(n - 1, m) + matrixPath(n, m - 1);
}

int main()
{
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;
    cout << "Number of ways are: " << matrixPath(rows, cols);

    return 0;
}