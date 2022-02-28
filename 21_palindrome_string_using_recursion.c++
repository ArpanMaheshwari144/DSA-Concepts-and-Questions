#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int left, int right)
{
    // for even characters and palindrome string
    if (left >= right)
    {
        return true;
    }
    if (s[left] != s[right])
    {
        return false;
    }
    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    string s = "racecar";
    int n = s.size();
    int left = 0;
    int right = n - 1;
    bool ans = isPalindrome(s, left, right);
    if (ans)
    {
        cout << "Palindromic string";
    }
    else
    {
        cout << "Not a Palindromic string";
    }

    return 0;
}