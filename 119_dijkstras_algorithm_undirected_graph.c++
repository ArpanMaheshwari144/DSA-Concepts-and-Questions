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
        // sort in ascending order
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

vector<int> dijkstra(int v, vector<vector<int>> adj[], int source)
{
    vector<bool> visited(v, false);
    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push({source, 0});
    vector<int> ans(v, INT_MAX);
    ans[source] = 0;

    while (!pq.empty())
    {
        Pair curr = pq.top();
        pq.pop();

        int u = curr.v;
        if (visited[u] == true)
        {
            continue;
        }

        visited[u] = true;
        for (vector<int> list : adj[u])
        {
            int v = list[0];
            int weight = list[1];
            if (ans[v] > ans[u] + weight)
            {
                ans[v] = ans[u] + weight;
                pq.push({v, ans[v]});
            }
        }
    }
    return ans;
}

int main()
{
    int v = 3;
    vector<vector<int>> adj[v];

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 1, 0, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 0, 6);
    addEdge(adj, 2, 1, 3);

    int source;
    cout << "Enter source: ";
    cin >> source;

    vector<int> ans = dijkstra(v, adj, source);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
