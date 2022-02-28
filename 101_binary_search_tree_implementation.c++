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

bool search(struct Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
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

    int searchElement;
    cout << "Enter a element to be searched: ";
    cin >> searchElement;
    if (search(root, searchElement))
    {
        cout << "Element is found";
    }
    else
    {
        cout << "Element is not found";
    }

    return 0;
}