#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++) {
        if(i == n-1) {
            cout << A[i];
        } else {
            cout << A[i] << ", ";
        }
    }

    cout << endl;
}


void insertionSort(int A[], int n){
    for(int i = 1; i < n; i++){
        int key = A[i];
        int j = i - 1;

        while(j >= 0 and A[j] > key){
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}


int main() {
    int arr[] = { 5, 32, 2, 9, 1, 23, 45, 50, 5, 6, 3, 4, 10, 5, 12, 16, 11, 18, 20, 12, 6, 17 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array:  ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "  Sorted array:  ";
    printArray(arr, n);

    return 0;
}
