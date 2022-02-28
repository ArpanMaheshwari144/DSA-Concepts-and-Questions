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

struct Node *createTree(struct Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = createTree(root->left, data);
    }
    else
    {
        root->right = createTree(root->right, data);
    }
    return root;
}

struct Node *insert(struct Node *root, int key)
{
    struct Node *newNode = new Node(key);
    struct Node *curr = root;
    struct Node *parent = NULL;

    while (curr != NULL)
    {
        parent = curr;
        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    if (parent == NULL)
    {
        return newNode;
    }
    else if (key < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    struct Node *root = NULL;
    int n;
    cout << "Enter how many elements you want to enter in the binary search tree: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int elementToBeInserted;
        cout << "Enter the element: ";
        cin >> elementToBeInserted;
        root = createTree(root, elementToBeInserted);
    }

    cout << "Before insertion: ";
    inOrder(root);

    root = insert(root, 22);

    cout << "\nAfter insertion: ";
    inOrder(root);

    return 0;
}