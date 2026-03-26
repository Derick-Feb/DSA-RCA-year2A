#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(int arr[], int n) {
    for(int i=0; i < n-1; i++) {
        for(int j=0; j < n-1-j; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    for(int i=0; i < n-1; i++) {
        int minIndex = i;

        for(int j= i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    for(int i=1; i<n-1; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = arr[j];
    }
}

struct Node {
    int data;
    Node* next;
};

void bubble_sort_ll(Node* head) {
    bool swapped;
    Node* ptr;
    Node* last = nullptr;

    do {
        swapped = false;
        ptr = head;

        while(ptr->next != last) {
            if(ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;

                swapped = true;
            }

            ptr = ptr->next;
        }

        last = ptr;
    } while(swapped);
}

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    vector<int> temp;

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid)
        temp.push_back(arr[i++]);

    while(j <= right)
        temp.push_back(arr[j++]);

    for(int i = 0; i < temp.size(); i++) {
        arr[left+1] = temp.at(i);
    }
}

void merge_sort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size-1;

    while(left <= right) {
        int mid = (right + left) / 2;

        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
