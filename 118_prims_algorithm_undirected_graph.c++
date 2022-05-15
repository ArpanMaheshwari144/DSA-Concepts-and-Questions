#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int v;
    int wt;
    Pair(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

class Compare
{
public:
    bool operator()(Pair &a, Pair &b)
    {
        return (a.wt > b.wt);
    }
};

void addEdge(vector<vector<int>> adj[], int u, int v, int wt)
{
    // undirected-graph
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(wt);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(wt);
    adj[v].push_back(t2);
}

int primMST(int v, vector<vector<int>> adj[])
{
    vector<bool> visited(v, false);
    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push({0, 0});
    int ans = 0;

    while (!pq.empty())
    {
        Pair curr = pq.top();
        pq.pop();

        int u = curr.v;
        if (visited[u] == true)
        {
            continue;
        }

        ans += curr.wt;
        visited[u] = true;
        for (vector<int> list : adj[u])
        {
            int v = list[0];
            int weight = list[1];
            if (visited[v] == false)
            {
                pq.push({v, weight});
            }
        }
    }
    return ans;
}

int main()
{
    int v = 3;
    vector<vector<int>> adj[v];

    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 2, 3);

    cout << primMST(v, adj);

    return 0;
}
