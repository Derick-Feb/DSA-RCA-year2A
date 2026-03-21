#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

void prim(int n, vector<vector<pii>> &adj)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(n, 1e9);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << endl;
}