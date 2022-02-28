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

bool isPairPresentUtil(struct Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
    {
        return false;
    }

    if (isPairPresentUtil(root->left, sum, s) == true)
    {
        return true;
    }

    if (s.find(sum - root->data) != s.end())
    {
        cout << "Pair is found (" << sum - root->data << ", " << root->data << ")";
        return true;
    }
    s.insert(root->data);

    return isPairPresentUtil(root->right, sum, s);
}

void isPairPresent(struct Node *root, int target)
{
    unordered_set<int> s;
    if (isPairPresentUtil(root, target, s) == false)
    {
        cout << "Pair does not exist";
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    isPairPresent(root, target);

    return 0;
}