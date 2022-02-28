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

// TC -> O(n)
void currentLevelOrder(struct Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        struct Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// TC -> O(n)
void printLevelWiseInCurrentLevelOrder(struct Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        struct Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            q.push(NULL);
            cout << endl;
        }
        else
        {
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            cout << curr->data << " ";
        }
    }
}

int main()
{
    struct Node *root = createTree();
    // currentLevelOrder(root);
    printLevelWiseInCurrentLevelOrder(root);

    return 0;
}