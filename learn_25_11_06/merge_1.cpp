#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main() {

    int arr[] = {42, 24, 61, 12, 50, 34, 34};
    int arrSize = 7;

    int low = 0;
    int high = arrSize-1;

    mergeSort(arr, low, high);

    for(int i: arr) cout << i << ", ";

    return 0;
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i]=arr[low+i];
    for(int j=0; j<n2; j++)
        R[j]=arr[mid+1+j];
    
    int i=0, k=low, j=0;
    while(i<n1 && j<n2)
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}