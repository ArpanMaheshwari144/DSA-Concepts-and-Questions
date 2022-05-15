#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, wt;
    Edge(int src, int dest, int wt)
    {
        this->src = src;
        this->dest = dest;
        this->wt = wt;
    }
};
class Solution
{
    int find(int x, vector<int> &parent)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void doUnion(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int xRoot = find(x, parent), yRoot = find(y, parent);
        if (xRoot == yRoot)
        {
            return;
        }

        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else if (rank[yRoot] < rank[xRoot])
        {
            parent[yRoot] = xRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    static bool cmp(Edge &a, Edge &b)
    {
        return a.wt < b.wt;
    }

public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<Edge> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto vec : adj[i])
            {
                edges.push_back(Edge(i, vec[0], vec[1]));
            }
        }

        int cost = 0;
        vector<int> rank(V, 0);
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        sort(edges.begin(), edges.end(), cmp);

        for (auto it : edges)
        {
            if (find(it.src, parent) != find(it.dest, parent))
            {
                doUnion(it.src, it.dest, parent, rank);
                cost += it.wt;
            }
        }
        return cost;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }

    Solution obj;
    cout << "The MST is: " << obj.spanningTree(V, adj);

    return 0;
}