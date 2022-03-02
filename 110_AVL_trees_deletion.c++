#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
        this->height = 1;
    }
};

int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalance(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node *leftRotate(struct Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *rightRotate(struct Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    // normal bst operations
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }

    // Update height of this ancestor node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // If this node becomes unbalanced, then theere are 4 cases
    // Left Left Case
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // loop down to find the leftmost leaf
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node *deleteNode(struct Node *root, int data)
{

    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else // if data is same as root's data, then this is the node to be deleted
    {
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case Copy the contents of the non-empty child
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor(smallest in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's  data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
    {
        return root;
    }

    // Update height of this ancestor node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // If this node becomes unbalanced, then theere are 4 cases
    // Left Left Case
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 45);
    root = insert(root, 55);

    cout << "Before deletion the inorder traversal of the constructed AVL tree is: ";
    inOrder(root);

    root = deleteNode(root, 50);

    cout << "\nAfter deletion the inorder traversal of the constructed AVL tree is: ";
    inOrder(root);

    return 0;
}