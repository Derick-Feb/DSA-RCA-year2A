#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void performRecursiveDFS(vector<vector<int>> v, int currentVertex, vector<bool>& visitedStatus) {
    int totalIndices = v.size();

    cout << currentVertex << endl;

    visitedStatus[currentVertex] = true;

    for(int neighborIndex = 0; neighborIndex < totalIndices; neighborIndex++) {
        if(!visitedStatus[neighborIndex] && v[currentVertex][neighborIndex] == 1) {
            performDFS(v, currentVertex, visitedStatus);
        }
    }
}

void performIterativeDFS(vector<vector<int>> v, int startVertex, vector<bool>& visitedStatus) {
    int totalIndices = v.size();

    stack<int> stack;
    stack.push(startVertex);

    while(!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        if(!visitedStatus[currentVertex]) {
            cout << currentVertex << endl;
            visitedStatus[currentVertex] = true;
        }

        for(int neighborIndex = 0; neighborIndex < totalIndices; neighborIndex++) {
            if(!visitedStatus[neighborIndex] && v[currentVertex][neighborIndex] == 1) {
                stack.push(neighborIndex);
            }
        }
    }
}

void performIterativeBFS(vector<vector<int>> v, int startVertex, vector<bool>& visitedStatus) {
    int totalIndices = v.size();

    Queue<int> stack;
    stack.push(startVertex);

    while(!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        if(!visitedStatus[currentVertex]) {
            cout << currentVertex << endl;
            visitedStatus[currentVertex] = true;
        }

        for(int neighborIndex = 0; neighborIndex < totalIndices; neighborIndex++) {
            if(!visitedStatus[neighborIndex] && v[currentVertex][neighborIndex] == 1) {
                stack.push(neighborIndex);
            }
        }
    }
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
