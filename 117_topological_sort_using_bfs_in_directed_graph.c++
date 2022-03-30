#include <bits/stdc++.h>
using namespace std;

void topoSort(int n, vector<int> adj[])
{
    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            in_degree[*itr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto itr = adj[front].begin(); itr != adj[front].end(); itr++)
        {
            if (--in_degree[*itr] == 0)
            {
                q.push(*itr);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // declare the adjacent list
    vector<int> adj[n + 1];

    // take edges as input
    cout << "Enter the edges of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topoSort(n, adj);

    return 0;
}