/* Hash Functions:
1. Map larger values to smaller values.
2. Sholud be O(1), or O(len) for String keys.
3. Sholud uniformly dsitribute large keys into has table slots.

Example of Hash Functions:
1. for large integer values:- h(Key) = Key % m, where m is a smaller number.
2. for string keys:- weighted sum
"cat" => (s[o]*x^0 + s[1]*x^1 + s[2]*x^2), where x is a prime number.
3. for objects:- weighted sum of elements.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Elements order does not matter in the set
    // Duplicate elements does not contain by the set
    // unordered_set<int> s;
    // s.insert(5);
    // s.insert(10);

    // if (s.find(5) == s.end())
    // {
    //     cout << "Not Found" << endl;
    // }
    // else
    // {
    //     cout << "Found" << endl;
    // }

    // cout << "Elements are: ";
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << (*it) << " ";
    // }
    // s.clear();
    // cout << "\nSize is: " << s.size();

    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(7);

    cout << s.count(10) << endl;
    if (s.count(9) == 0)
    {
        cout << "Element is not present" << endl;
    }

    s.erase(10);

    cout << "Elements are: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }

    // s.begin() iterator is inclusive and s.end() iterator is exclusive
    s.erase(s.begin(), s.end());
    cout << "\nSize is: " << s.size();

    return 0;
}