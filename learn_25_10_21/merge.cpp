#include <iostream>
using namespace std;

void mergeArrays(int x[], int y[], int a[], int s, int e, int n1, int n2) {
    int i = 0, j = 0, k = s;

    while (i < n1 && j < n2) {
        if (x[i] < y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }

    while (i < n1) a[k++] = x[i++];
    while (j < n2) a[k++] = y[j++];
}

void mergeSort(int A[], int s, int e) {
    if (s >= e) return;

    int mid = (s + e) / 2;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int x[n1], y[n2];
    for (int i = 0; i < n1; i++) x[i] = A[s + i];
    for (int i = 0; i < n2; i++) y[i] = A[mid + 1 + i];

    mergeSort(x, 0, n1 - 1);
    mergeSort(y, 0, n2 - 1);

    mergeArrays(x, y, A, s, e, n1, n2);
}

int main() {
    int marks[] = {
        187, 45, 232, 168, 73, 154, 199, 181, 160, 177,
        134, 188, 149, 191, 163, 179, 156, 184, 172, 166,
     // 195, 141, 158, 180, 167, 190, 139, 176, 153, 182,
     // 161, 144, 197, 170, 155, 185, 162, 178, 148, 193,
     // 169, 150, 183, 174, 165, 200, 142, 175, 159, 186,
     // 120, 210, 134, 198, 222, 143, 176, 204, 160, 199,
     // 132, 187, 148, 216, 171, 203, 138, 179, 165, 208,
     // 155, 182, 190, 147, 173, 200, 151, 196, 164, 211,
     // 180, 140, 202, 168, 159, 195, 170, 183, 152, 189,
     // 174, 199, 161, 207, 143, 188, 166, 201, 157, 192,
     // 100, 205, 130, 194, 215, 135, 178, 209, 145, 197
    };

    int n = sizeof(marks) / sizeof(int);
    mergeSort(marks, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if(n%10 == 9)
            cout << endl;
        else
            cout << ", ";
    }
    cout << endl;

    return 0;
}
