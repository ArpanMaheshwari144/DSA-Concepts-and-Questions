#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
public:
    struct TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *currNode = root;
    for (int i = 0; i < key.length(); i++)
    {
        int curr = key[i] - 'a';
        if (currNode->children[curr] == NULL)
        {
            TrieNode *newNode = new TrieNode();
            currNode->children[curr] = newNode;
        }
        currNode = currNode->children[curr];
    }
    currNode->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *currNode = root;
    for (int i = 0; i < key.length(); i++)
    {
        int curr = key[i] - 'a';
        if (currNode->children[curr] == NULL)
        {
            return false;
        }
        currNode = currNode->children[curr];
    }
    return currNode->isEndOfWord;
}

int main()
{
    struct TrieNode *root = new TrieNode();
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }

    if (search(root, "bye"))
    {
        cout << "Present";
    }
    else
    {
        cout << "Absent";
    }

    return 0;
}