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

vector<int> verticalOrder(Node *root)
{
    // nodes has 3 elements 1.horizontal distance 2.level 3.list nodes
    map<int, map<int, vector<int>>> nodes;

    // q has 3 elements 1.Nodes 2.horizontal distance 3.level
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontalDistance][level].push_back(frontNode->data);
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    struct Node *root = createTree();
    vector<int> ans = verticalOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}