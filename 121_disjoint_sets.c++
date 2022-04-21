#include <bits/stdc++.h>
using namespace std;

class DisjointSets
{
    int *rank, *parent;
    int n;

public:
    DisjointSets(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void doUnion(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);
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

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
    }
};

int main()
{
    DisjointSets obj(7);
    obj.doUnion(0, 1);
    obj.doUnion(1, 2);
    obj.doUnion(2, 3);
    obj.doUnion(3, 4);
    obj.doUnion(4, 5);
    obj.doUnion(5, 6);
    obj.doUnion(6, 7);

    cout << "Parent array: ";
    obj.print();

    return 0;
}