#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> adj[], bool vis[], vector<int> &ans)
{
    vis[v] = true;
    ans.push_back(v);
    for (int neighbor : adj[v])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, adj, vis, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    bool vis[V];
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }

    return ans;
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
        adj[v].push_back(u);
    }

    vector<int> ans = dfsOfGraph(n, adj);

    cout << "DFS path of this graph is: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}