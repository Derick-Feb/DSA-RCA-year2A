#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

struct DSU
{
    vector<int> parent;
    DSU(int n, vector<int> v)
    {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = v[i];
    }

    int find(int i)
    {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j)
        {
            parent[root_i] = root_j;
            return true;
        }

        return false;
    }
};

class Graph
{
    vector<int> V;
    vector<vector<int>> adj_list;

public:
    Graph(vector<int> vertices) : V(vertices)
    {

        // resizing the adjacency list for number of vertices
        adj_list.resize(V.size());

        // Initialize the adjacency list with 0s to be V.size()^2 matrix
        for (int i = 0; i < V.size(); i++)
        {
            adj_list[i] = vector<int>(V.size(), 0);
        }
    }

    ~Graph()
    {
        cout << "Destructing the Graph" << endl;
    }

    bool add_edge(int origin, int destin, int weight)
    {
        if (origin < 0 || destin > V.size())
        {
            cout << "Invalid edge" << endl;
            return false;
        }

        adj_list[origin][destin] = weight;
        return true;
    }

    bool remove_edge(int origin, int destin)
    {
        if (origin < 0 || destin > V.size())
        {
            cout << "Invalid edge" << endl;
            return false;
        }

        // Remove the edge from the adjacency list
        // using the non-directed graph
        adj_list[origin][destin] = 0;
        adj_list[destin][origin] = 0;
        return true;
    }

    void display()
    {
        for (int i = 0; i < V.size(); i++)
        {
            for (int j = 0; j < V.size(); j++)
            {
                if(adj_list[i][j] == 0) continue;

                cout << V[i] << " - " << V[j] << " : " << adj_list[i][j] << " | ";
            }
            cout << endl;
        }
    }

    void bfs_traversel()
    {
        int size = V.size();
        vector<bool> visited(size, false);
        queue<int> q;

        for(int i = 0; i < size; i ++)
        {
            if(!visited[i])
            {
                int initial_vertex = i;
                q.push(initial_vertex);
                visited[initial_vertex] = true;

                while(!q.empty())
                {
                    int current_vertex = q.front();
                    q.pop();

                    cout << current_vertex << ", ";
                    for(int i = 0; i < size; i++)
                    {
                        if(adj_list[current_vertex][i] != 0 && !visited[i])
                        {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
        }
    }

    void kruskal_mst()
    {
        int size = V.size();
        vector<Edge> edges;

        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                if(adj_list[i][j] != 0)
                {
                    edges.push_back({i, j, adj_list[i][j]});
                }
            }
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DSU dsu(size, V);
        vector<Edge> mst;
        int total_weight = 0;

        for(Edge& e: edges)
        {
            if(dsu.unite(e.u, e.v))
            {
                total_weight += e.weight;
                cout << V[e.u] << "-" << V[e.v] << " : " << e.weight << endl;
            }
        }

        cout << "total weight: " << total_weight << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<int> test(n, 0);
    for(int i = 0; i < test.size(); i++)
    {
        cout << "Enter vertice " << i+1 << " out of " << test.size() << " : ";
        cin >> test[i];
    }
    cout << endl;

    Graph test_graph(test);

    int n_edges;
    cout << "Enter the number of edges: ";
    cin >> n_edges;
    for(int i = 0; i < n_edges; i++)
    {
        int origin, destin, weight;
        cout << "Enter origin and destination vertices, and weight: ";
        cin >> origin >> destin >> weight;
        test_graph.add_edge(origin, destin, weight);
    }

    cout << endl;

    test_graph.display();

    cout << endl << endl;

    // test_graph.bfs_traversel();

    test_graph.kruskal_mst();

    return 0;
}
