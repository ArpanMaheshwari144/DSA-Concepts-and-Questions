#include <bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

bool isOpening(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isParenthesisMatching(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char curr = str[i];
        if (isOpening(curr))
        {
            st.push(curr);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else if (!isMatching(st.top(), curr))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "))((";
    bool ans = isParenthesisMatching(s);
    if (ans)
    {
        cout << "Parenthesis Matching";
    }
    else
    {
        cout << "Parenthesis not Matching";
    }
    return 0;
}