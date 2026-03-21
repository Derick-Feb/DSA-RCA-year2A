#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

struct DSU
{
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
            parent[root_i] = root_j;
    }
};

void kruskal(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<Edge> mst;
    int cost = 0;

    for (Edge e : edges)
    {
        if (dsu.find(e.u) != dsu.find(e.v))
        {
            cost += e.weight;
            mst.push_back(e);
            dsu.unite(e.u, e.v);
        }
    }

    cout << "MST Cost: " << cost << "\nEdges in MST:\n";
    for (auto e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
}