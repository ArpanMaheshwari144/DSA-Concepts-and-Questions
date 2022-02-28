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

struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    struct Node *left = LCA(root->left, n1, n2);
    struct Node *right = LCA(root->right, n1, n2);

    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }
    return root;
}

int main()
{
    struct Node *root = createTree();
    int n1, n2;
    cout << "Enter the two nodes: ";
    cin >> n1 >> n2;
    struct Node *ans = LCA(root, n1, n2);
    cout << "LCA(" << n1 << ", " << n2 << ") = " << ans->data;

    return 0;
}