// Subsequence or Powerset both are same

#include <bits/stdc++.h>
using namespace std;

void powerSet(string s, int i, string curr)
{
    if (i == s.length())
    {
        cout << curr << endl;
        return;
    }
    powerSet(s, i + 1, curr + s[i]); // include the character
    powerSet(s, i + 1, curr);        // not include the character
}

int main()
{
    string s = "abc";
    string curr = "";

    cout << "Subsequences are\n";
    powerSet(s, 0, curr);

    return 0;
}