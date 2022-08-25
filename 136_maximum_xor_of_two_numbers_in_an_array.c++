#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *zero = NULL;
    TrieNode *one = NULL;
};

void insert(TrieNode *root, int value)
{
    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (value >> i) & 1; // right sift
        if (bit == 0)
        {
            if (curr->zero == NULL)
            {
                TrieNode *newNode = new TrieNode();
                curr->zero = newNode;
            }
            curr = curr->zero;
        }
        else
        {
            if (curr->one == NULL)
            {
                TrieNode *newNode = new TrieNode();
                curr->one = newNode;
            }
            curr = curr->one;
        }
    }
}

int findMaxXor(TrieNode *root, int value)
{
    TrieNode *curr = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (value >> i) & 1;
        if (bit == 1)
        {
            if (curr->zero != NULL)
            {
                ans += (1 << i);
                curr = curr->zero;
            }
            else
            {
                curr = curr->one;
            }
        }
        else
        {
            if (curr->one != NULL)
            {
                ans += (1 << i);
                curr = curr->one;
            }
            else
            {
                curr = curr->zero;
            }
        }
    }
    return ans;
}

int max_xor(int a[], int n)
{
    TrieNode *root = new TrieNode();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        insert(root, a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        ans = max(ans, findMaxXor(root, a[i]));
    }
    return ans;
}

int main()
{
    int n = 6;
    int arr[] = {25, 10, 2, 8, 5, 3};

    cout << max_xor(arr, n) << endl;

    return 0;
}