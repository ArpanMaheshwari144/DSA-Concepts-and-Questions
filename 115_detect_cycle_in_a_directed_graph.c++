#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack)
{
    vis[v] = true;
    recStack[v] = true;
    for (int neighbor : adj[v])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, adj, vis, recStack))
            {
                return true;
            }
        }
        else if (recStack[neighbor])
        {
            return true;
        }
    }
    recStack[v] = false; // backtrack
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> recstack(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, recstack))
            {
                return true;
            }
        }
    }
    return false;
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

    if (isCyclic(n, adj))
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }

    return 0;
}