#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int marks[] = {10, 90, 34, 100, 95};
    bubbleSort(marks, 5);

    char prices[] = {'K', 'A', 'N', 's'};
    bubbleSort(prices, 4);

    for(auto i: marks) cout << i << " ";
    cout << endl;

    for(auto i: prices) cout << i << " ";
    cout << endl;

    return 0;
}
