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

// TC -> O(n) n is number of nodes in a tree
// SC -> O(height of binary tree)
int getMax(struct Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(getMax(root->left), getMax(root->right)));
}

// TC -> O(n) n is number of nodes in a tree
// SC -> O(height of binary tree)
int getMin(struct Node *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data, min(getMin(root->left), getMin(root->right)));
}

int main()
{
    struct Node *root = createTree();
    int ans1 = getMax(root);
    int ans2 = getMin(root);
    cout << "Maximum value --> " << ans1 << endl;
    cout << "Minimum value --> " << ans2 << endl;

    return 0;
}