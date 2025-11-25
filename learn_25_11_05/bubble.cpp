#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void bubbleSort2(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {

    int arr[10] = {12, 45, 21, 56, 23, 66, 43, 12, 20, 49};
    bubbleSort(arr, 10);

    for(int i: arr){
        cout << i << ", ";
    }

    return 0;
}