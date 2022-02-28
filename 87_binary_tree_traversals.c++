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

// InOrder Traversal -> Left Root Right
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// PreOrder Traversal -> Root Left Right
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// PostOrder Traversal -> Left Right Root
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct Node *root = createTree();

    cout << "InOrder is: ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder is: ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder is: ";
    postOrder(root);

    return 0;
}