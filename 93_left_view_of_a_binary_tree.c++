#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

struct Node *createTree()
{
    struct Node *root = NULL;
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter left data for: " << data << endl;
    root->left = createTree();

    cout << "Enter right data for: " << data << endl;
    root->right = createTree();

    return root;
}

void printLeftViewUtil(struct Node *root, unordered_map<int, int> &mp, int level)
{
    if (root == NULL)
    {
        return;
    }

    /* if the level is visited for the first time, insert the current node and level information into the map */
    if (mp.find(level) == mp.end())
    {
        mp[level] = root->data;
    }
    printLeftViewUtil(root->left, mp, level + 1);
    printLeftViewUtil(root->right, mp, level + 1);
}

void printLeftView(struct Node *root)
{
    unordered_map<int, int> mp;
    printLeftViewUtil(root, mp, 0);
    for (int i = 0; i < mp.size(); i++)
    {
        cout << mp[i] << " ";
    }
}

int main()
{
    struct Node *root = createTree();
    printLeftView(root);

    return 0;
}