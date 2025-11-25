#include <iostream>
using namespace std;

void selection(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }

        if(minIndex != i) swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[10] = {12, 45, 21, 56, 23, 66, 43, 12, 20, 49};
    selection(arr, 10);

    for(int i: arr) cout << i << ", ";
}
