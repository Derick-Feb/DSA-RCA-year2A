#include <iostream>
using namespace std;

class AdjacencyMatrix {
private:
    int** matrix;
    int n;

public:
    AdjacencyMatrix(int n): n(n) {
        matrix = new int*[n];

        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    ~AdjacencyMatrix() {
        for(int i = n; i < n; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
};

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
