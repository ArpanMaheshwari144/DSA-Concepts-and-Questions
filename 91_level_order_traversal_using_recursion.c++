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

int getHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// TC -> O(n^2)
void currentLevelOrderRecursive(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        currentLevelOrderRecursive(root->left, level - 1);
        currentLevelOrderRecursive(root->right, level - 1);
    }
}

int main()
{
    struct Node *root = createTree();
    int heightOfTree = getHeight(root);

    for (int i = 1; i <= heightOfTree; i++)
    {
        currentLevelOrderRecursive(root, i); // i -> current level of the tree
    }

    return 0;
}