#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 2, 2, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int INT_SIZE = 8 * sizeof(int);
    int count[INT_SIZE];
    memset(count, 0, sizeof(count));

    /* AND(bitwise) each element of the array with each set digit (one at a time) to get the count of set bits at each
    position */
    for (int i = 0; i < INT_SIZE; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] & (1 << i)) != 0)
            {
                count[i] += 1;
            }
        }
    }

    // Now consider all bits whose count is not multiple of k to form the required number.
    int res = 0;
    for (int i = 0; i < INT_SIZE; i++)
    {
        res += (count[i] % k) * (1 << i);
    }
    cout << res;

    return 0;
}