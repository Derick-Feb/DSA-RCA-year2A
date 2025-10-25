#include <iostream>
#include <sys/time.h>
using namespace std;

long getTimeInMicroSeconds() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

// Merge Sort helpers
int *x = new int[10000000];
int *y = new int[10000000];

void mergeArrays(int x[], int y[], int a[], int s, int e) {
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= e) {
        if (x[i] < y[j]) a[k++] = x[i++];
        else a[k++] = y[j++];
    }
    while (i <= mid) a[k++] = x[i++];
    while (j <= e) a[k++] = y[j++];
}

void mergeSort(int a[], int s, int e) {
    if (s >= e) return;
    int mid = (s + e) / 2;

    for (int i = s; i <= mid; i++) x[i] = a[i];
    for (int i = mid + 1; i <= e; i++) y[i] = a[i];

    mergeSort(x, s, mid);
    mergeSort(y, mid + 1, e);
    mergeArrays(x, y, a, s, e);
}

// Selection Sort (commented)
/*
void selectionSort(int a[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int smallest = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (a[j] < a[smallest]) smallest = j;
        }
        swap(a[i], a[smallest]);
    }
}
*/

// Bubble Sort (commented)
/*
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}
*/

int main() {

    for (int n = 10; n <= 10000000; n *= 10) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = n - i; // initialize descending

        long startTime = getTimeInMicroSeconds();

        mergeSort(arr, 0, n - 1);

        long endTime = getTimeInMicroSeconds();
        cout << "Merge sort n = " << n << " time = " << endTime - startTime << " microseconds" << endl;

        delete[] arr;
    }

    delete[] x;
    delete[] y;

    return 0;
}
