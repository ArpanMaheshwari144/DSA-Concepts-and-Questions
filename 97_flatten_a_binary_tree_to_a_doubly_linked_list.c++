#include <bits/stdc++.h>
using namespace std;

struct Node *prevv = NULL;
struct Node *head = NULL;

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

void convertToDLL(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    convertToDLL(root->left);
    if (prevv == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prevv;
        prevv->right = root;
    }
    prevv = root;
    convertToDLL(root->right);
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

int main()
{
    struct Node *root = createTree();
    convertToDLL(root);
    display(head);

    return 0;
}