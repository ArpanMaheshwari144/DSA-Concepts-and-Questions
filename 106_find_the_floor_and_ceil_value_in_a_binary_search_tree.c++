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

int floorValue(struct Node *root, int key)
{
    int ans = -1;
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root->data;
        }

        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

int ceilValue(struct Node *root, int key)
{
    int ans = -1;
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root->data;
        }

        if (root->data > key)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
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

    int key;
    cout << "Enter the value for which you have to find it's floor and ceil values: ";
    cin >> key;

    int ans1 = floorValue(root, key);
    int ans2 = ceilValue(root, key);
    cout << "For " << key << " Floor value => " << ans1 << " and "
         << "Ceil Value => " << ans2;

    return 0;
}