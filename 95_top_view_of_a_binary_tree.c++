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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // topNode has 1. horizontalDistance 2. top nodes(ans)
    map<int, int> topNode;

    // topNode has 1. Nodes 2. horizontalDistance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontalDistance = temp.second;

        // if one value is present for a horizontalDistance, then do nothing
        if (topNode.find(horizontalDistance) == topNode.end())
        {
            topNode[horizontalDistance] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, horizontalDistance - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, horizontalDistance + 1));
        }
    }
    for (auto it : topNode)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    struct Node *root = createTree();
    vector<int> ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}