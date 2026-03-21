#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> v, int sv)
{
    int n = v.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        cout << cv << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[cv][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            };
        };
    };
};

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    cout << "Reading " << n << " vertices numbered from 0 to " << n - 1 << endl;
    cout << "Enter first Vertex and second vertex" << endl;

    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    cout << "BFS Traversal: " << endl;
    bfs(matrix, 0);

    return 0;
}