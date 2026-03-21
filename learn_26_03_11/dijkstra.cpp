#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
typedef pair<int, int> pii; // {distance, vertex}

void dijkstra(int n, int start, vector<vector<pii>> &adj)
{
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << endl;
}

int main()
{

    return 0;
}