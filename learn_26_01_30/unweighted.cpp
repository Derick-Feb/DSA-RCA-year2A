#include <iostream>
using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;

public:
    // Constructor
    AdjacencyMatrix(int n) {
        this->n = n;
        adj = new int* [n];
        for(int i = 0; i < n; i++) { // Fixed: Initialized i = 0
            adj[i] = new int [n];
            for(int j = 0; j < n; j++) { // Fixed: Initialized j = 0
                adj[i][j] = 0;
            }
        }
    }

    // Destructor to prevent memory leaks
    ~AdjacencyMatrix() {
        for(int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void add_edge(int origin, int destin) {
        if(origin > n || destin > n || origin <= 0 || destin <= 0) {
            cout << "Invalid vertex index!" << endl; 
            return;
        }
        adj[origin-1][destin-1] = 1;
    }
    
    void delete_edge(int origin, int destin) {
        if(origin > n || destin > n || origin <= 0 || destin <= 0) {
            cout << "Invalid vertex index!" << endl; 
            return;
        }
        adj[origin-1][destin-1] = 0;
    }
    
    void display() {
        cout << "\nAdjacency Matrix:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, origin, destin;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    AdjacencyMatrix am(nodes);
    
    // Using a more flexible loop for user input
    cout << "Enter edges (origin destination). Enter -1 -1 to finish." << endl;
    while (true) {
        cout << "Edge: ";
        cin >> origin >> destin;

        if(origin == -1 || destin == -1) break;

        am.add_edge(origin, destin);
    }

    am.display();

    return 0;
}