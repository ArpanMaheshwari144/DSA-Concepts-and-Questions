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

// First Approach
/*
bool isBSTUtil(struct Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    // +1 && -1 is bcoz of the bst does not contains the same values
    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(struct Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
*/

// Second Approach
bool isBST(struct Node *root)
{
    // in every iteration it's value is changing
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        return isBST(root->right);
    }
    return true;
}

int main()
{
    struct Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(80);
    root->right->left = new Node(60);
    root->right->right = new Node(90);

    if (isBST(root) == true)
    {
        cout << "It is a binary search tree";
    }
    else
    {
        cout << "It is not a binary search tree";
    }

    return 0;
}