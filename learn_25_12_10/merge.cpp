#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = arr[low+i];
    for(int j=0; j<n2; j++) R[j] = arr[mid+1+j];

    int i=0, j=0, k=low;
    while(i<n1 && j<n2){
        if(L[i] >= R[j])
            arr[k++] = R[j++];
        else
            arr[k++] = L[i++];
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

    int arr[10] = {7, 9, 5, 4, 3, 6, 2, 8, 1};
    int arrSize = 10;

    mergeSort(arr, 0, arrSize-1);

    for(int i: arr) cout << i << ", ";

    return 0;
}
