#include <bits/stdc++.h>
#include <string>
using namespace std;

// void myswap(char *i, char *j)
// {
//     char temp;
//     temp = *i;
//     *i = *j;
//     *j = temp;
// }

void permute(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
        return;
    }
    for (int i = left; i <= right; i++)
    {
        // myswap(&s[left], &s[i]);
        // permute(s, left + 1, right);
        // myswap(&s[left], &s[i]); // backtrack

        swap(s[left], s[i]); // swapping
        permute(s, left + 1, right);
        swap(s[left], s[i]); // backtrack
    }
}

int main()
{
    string s = "abc";
    int n = s.size();
    cout << "All Permutations are\n";
    permute(s, 0, n - 1);

    return 0;
}