#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void performRecursiveDFS(vector<vector<int>> adjacencyMatrix, int currentIndex, vector<bool>& visitedStatus) {

    cout << currentIndex << endl;

    int totalVertices = adjacencyMatrix.size();

    for(int neighborIndex = 0; neighborIndex < totalVertices; neighborIndex++) {
        if(adjacencyMatrix[currentIndex][neighborIndex] == 1 && visitedStatus[neighborIndex]) {
            performDFS(adjacencyMatrix, currentIndex, visitedStatus);
        }
    }
}

void permformIterativeDFS(vector<vector<int>> adjacencyMatrix, int startIndex, vector<bool>& visitedStatus) {
    int totalIndices = adjacencyMatrix.size();
    stack<int> stack;
    stack.push(startIndex);

    while(!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        if(!visitedStatus[currentVertex]) {
            cout << currentVertex << endl;
            visitedStatus[currentVertex] = true;
        }

        for(int i = 0; i < totalIndices; i++) {
            if(adjacencyMatrix[currentVertex][i] == 1 && !visitedStatus[currentVertex]) {
                stack.push(i);
                // visitedStatus[currentVertex] = true;
            }
        }
    }
}

void dfs(vector<vector<int>> matrix) {
    int n = matrix.size();
    vector<bool> visited(n, false):
    int count = 0;

    for(int i = 0; i < n; i++) {
        count++;
        permformIterativeDFS(matrix, i, visited);
    }
}

void performIterativeBFS(vector<vector<int>> adjacencyMatrix, int startIndex, vector<bool>& visited) {
    int totalIndices = adjacencyMatrix.size();
    queue<int> queue;

    visited[startIndex] = true;
    queue.push(startIndex);

    while(!queue.empty()) {
        int currentIndex = queue.front();
        queue.pop();

        cout << currentIndex << endl;

        for(int i = 0; i < n; i++) {
            count++;
            performIterativeBFS(matrix, i, visited);
        }
    }
}

void performExpending() {
    int* newArray = new int[capacity*2];
    for(int i = 0; i < capacity; i++) {
        newArray[i] = array[i];
    }

    delete array;
    array = newArray;
    capacity *= 2;
}

int main() {

    // populating the adjacency matrix

    return 0;
}
