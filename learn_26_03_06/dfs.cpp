#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    int n = v.size();
    stack<int> st;

    while (!st.empty())
    {
        int cv = st.top();
        visited[cv] = true;
        st.pop();

        cout << cv << endl;

        for (int i = 0; i < n; i++)
        {
            if (v[cv][i] == 1 && !visited[i])
            {
                st.push(i);
            }
        }
    }
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

    vector<bool> visited(n, false);
    cout << "DFS Traversal: " << endl;
    dfs(matrix, 0, visited);

    return 0;
}
