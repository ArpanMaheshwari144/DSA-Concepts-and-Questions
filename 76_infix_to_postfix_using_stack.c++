#include <bits/stdc++.h>
using namespace std;

bool IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

bool IsOperand(char c)
{
    if (c >= 'A' && c <= 'Z') /* Define the character in between A to Z. If not, it returns False.*/
        return true;
    if (c >= 'a' && c <= 'z') // Define the character in between a to z. If not, it returns False. */
        return true;
    if (c >= '0' && c <= '9') // Define the character in between 0 to 9. If not, it returns False. */
        return true;
    return false;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

/* The eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. */
bool eqlOrhigher(char op1, char op2)
{
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if (p1 == p2)
    {
        if (op1 == '^')
            return false;
        return true;
    }
    return (p1 > p2 ? true : false);
}

/* string convert() function is used to convert the infix expression to the postfix expression of the Stack */
string convert(string infix)
{
    stack<char> S;
    string postfix = "";
    char ch;

    S.push('(');
    infix += ')';

    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (ch == '(')
            S.push(ch);
        else if (IsOperand(ch))
            postfix += ch;
        else if (IsOperator(ch))
        {
            while (!S.empty() && eqlOrhigher(S.top(), ch))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(ch);
        }
        else if (ch == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    return postfix;
}

int main()
{
    string infix = "a + b * c";

    string postfix = convert(infix);
    cout << "Your Infix expression is: " << infix;
    cout << "\nPostfix expression is: " << postfix;

    return 0;
}
