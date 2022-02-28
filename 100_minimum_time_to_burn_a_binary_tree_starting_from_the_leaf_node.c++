/* Given a binary tree and a leaf node from this tree. It is known that in 1s all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on. The task is to find the minimum time required to burn the complete binary tree.

Examples:
Input: 
            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     8         9
                      \
                       10
Leaf = 8
Output : 7

Initially 8 is set to fire at 0th sec.

            1
       /       \
      2          3
    /  \          \
   4    5          6
      /   \         \
     7     F         9
                      \
                       10

After 1s: 5 is set to fire.

            1
       /       \
      2          3
    /  \          \
   4    F          6
      /   \         \
     7     F         9
                      \
                       10

After 2s: 2, 7 are set to fire.

            1
       /       \
      F          3
    /  \          \
   4    F          6
      /   \         \
     F     F         9
                      \
                       10

After 3s: 4, 1 are set to fire.

            F
       /       \
      F          3
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10

After 4s: 3 is set to fire.

            F
       /       \
      F          F
    /  \          \
   F    F          6
      /   \         \
     F     F         9
                      \
                       10

After 5s: 6 is set to fire.

            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         9
                      \
                       10

After 6s: 9 is set to fire.

            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       10

After 7s: 10 is set to fire.

            F
       /       \
      F          F
    /  \          \
   F    F          F
      /   \         \
     F     F         F
                      \
                       F
It takes 7s to burn the complete tree.

The maximum depth of a binary tree is the number of nodes from the root down to the furthest leaf node.*/

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

int ans = -1;
int burn(struct Node *root, int target, int &depth)
{
    if (root == NULL)
        return 0;

    if (root->data == target)
    {
        depth = 1;
        return 1;
    }

    int leftDepth = -1;
    int rightDepth = -1;

    int leftHeight = burn(root->left, target, leftDepth);
    int rightHeight = burn(root->right, target, rightDepth);

    if (leftDepth != -1)
    {
        ans = max(ans, leftDepth + rightHeight);
        depth = leftDepth + 1;
    }
    else if (rightDepth != -1)
    {
        ans = max(ans, rightDepth + leftHeight);
        depth = rightDepth + 1;
    }
    return max(leftHeight, rightHeight) + 1;
}

int minTime(struct Node *root, int target)
{
    int depth = -1;
    burn(root, target, depth);
    return ans;
}

int main()
{
    struct Node *root = createTree();

    int target;
    cout << "Enter the target leaf node: ";
    cin >> target;
    cout << minTime(root, target);

    return 0;
}