#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << ", ";
    }

    cout << endl;
}

void bubbleSort(int A[], int n){
    int count = 0, check = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            count++;
            if(A[j] > A[j+1]){
                check++;
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
            cout << "=> Check: " << check << "\n";
        }
    }
    
    cout << "=>> Count: " << count << "\n";
}

int main() {
    int array[] = { 10, 20, 40, 30, 50, 60 };
    bubbleSort(array, 6);
    printArray(array, 6);

    return 0;
}