#include <iostream>
using namespace std;

void insertion(int arr[], int n) {
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key= arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main() {
    int arr[10] = {12, 45, 21, 56, 23, 66, 43, 12, 20, 49};
    insertion(arr, 10);

    for(int i: arr) cout << i << ", ";
}
