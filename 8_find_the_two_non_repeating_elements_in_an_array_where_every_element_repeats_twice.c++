#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }

    /* Get the rightmost set bit in set_bit_no */
    int set_bit_no = res & ~(res - 1);

    /* Now divide elements in two sets by comparing rightmost set bit of Xor with bit at same position in each element. */
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }

    cout << x << " " << y;

    return 0;
}