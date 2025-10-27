#include <iostream>
#include <functional>

using namespace std;

function<bool(int, int, bool)> compare = [](int a, int b, bool or_equal) { 
    return or_equal ? (a <= b) : (a < b); 
};

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (compare(left, right, true)) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (compare(arr[mid], key, false))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
}
