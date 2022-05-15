#include <bits/stdc++.h>
using namespace std;

class Edge
{
    int *parent;

public:
    Edge(int n)
    {
        parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }

    void doUnion(int x, int y)
    {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry)
        {
            return;
        }
        parent[ry] = rx;
    }
};

class Graph
{
    int n;
    vector<vector<int>> adj;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void addEdge(int u, int v, int wt)
    {
        // we have to add weight first bcoz we have to sort accoroding to weights
        adj.push_back({wt, u, v});
    }

    void MST()
    {
        Edge e(n);

        // sort according to weights bcoz weight is in adj[0]
        sort(adj.begin(), adj.end());
        int ans = 0;
        for (auto edge : adj)
        {
            int wt = edge[0];
            int src = edge[1];
            int dest = edge[2];

            // take that edge in MST if it does form a cycle
            if (e.find(src) != e.find(dest))
            {
                e.doUnion(src, dest);
                ans += wt;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.MST();

    return 0;
}
