#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = arr[low+i];
    for(int j=0; j<n2; j++) R[j] = arr[mid+1+j];

    int i=0, j=0, k=low;
    while(i<n1 && j<n2)
        if(L[i] >= R[j])
            arr[k++] = R[j++];
        else
            arr[k++] = L[i++];

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

    return;
}

int main() {
    int arr[10] = {12, 45, 21, 56, 23, 66, 43, 12, 20, 49};
    int arrSize = 10;

    int low = 0;
    int high = arrSize-1;

    mergeSort(arr, low, high);

    for(int i: arr) cout << i << ", ";
}
