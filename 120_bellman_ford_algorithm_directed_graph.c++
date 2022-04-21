#include <bits/stdc++.h>
using namespace std;

int BellmanFord(int n, vector<vector<int>> edges)
{
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    for (int count = 1; count < n; count++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int src = edges[j][0];
            int dest = edges[j][1];
            int weight = edges[j][2];
            if (dist[src] != INT_MAX && dist[src] + weight < dist[dest])
            {
                dist[dest] = dist[src] + weight;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        int src = edges[j][0];
        int dest = edges[j][1];
        int weight = edges[j][2];
        if (dist[src] != INT_MAX && dist[src] + weight < dist[dest])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, 3}};

    cout << "The graph contains negative cycle: " << BellmanFord(n, edges);

    return 0;
}