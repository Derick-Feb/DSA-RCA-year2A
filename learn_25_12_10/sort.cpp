#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << ", ";
    }

    cout << endl;
}

void bubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void selectionSort(int A[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[min]) min = j;
        }

        if(min != i) swap(A[i], A[min]);
    }
}

void insertionSort(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j = i-1;

        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j -= 1;
        }

        A[j+1] = key;
    }
}

// version 2
void bubbleSort2(int A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]) swap(A[j], A[j+1]);
        }
    }
}

void selectionSort2(int A[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[min]) min=j;
        }

        if(min != i) swap(A[i], A[min]);
    }
}

void insertionSort2(int A[], int n){
    for(int i=1; i<n; i++){
        int key = A[i];
        int j = i-1;

        while(j >= 0 && A[j]>key){
            A[j+1] = A[j];
            j -= 1;
        }

        A[j+1] = key;
    }
}

int main() {
    int array[] = { 20, 40, 60, 80, 10, 30 };

    insertionSort2(array, 6);

    printArray(array, 6);
    
    return 0;
}
