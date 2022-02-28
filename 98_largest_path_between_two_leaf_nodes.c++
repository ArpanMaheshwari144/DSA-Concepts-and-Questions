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

// TC -> O(n^2)
/*
int getHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int diamterOfBinaryTree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int diameterOfLeft = diamterOfBinaryTree(root->left);
    int diameterOfRight = diamterOfBinaryTree(root->right);

    int currNode = getHeight(root->left) + getHeight(root->right) + 1;
    return max(currNode, max(diameterOfLeft, diameterOfRight));
}
*/

// TC -> O(n)
int heightOfBinaryTree(struct Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int diameterOfLeft = heightOfBinaryTree(root->left, ans);
    int diameterOfRight = heightOfBinaryTree(root->right, ans);

    ans = max(ans, 1 + diameterOfLeft + diameterOfRight);
    return 1 + max(diameterOfLeft, diameterOfRight);
}

int diamterOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = INT_MIN;
    heightOfBinaryTree(root, ans);
    return ans;
}

int main()
{
    struct Node *root = createTree();
    int ans = diamterOfBinaryTree(root);
    cout << "Longest path between two nodes is: " << ans << endl;

    return 0;
}