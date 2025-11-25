#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int target) {
    int low = 0; int high = n-1;
    while(low <= high){
        int mid=(low+high)/2;
        if(mid == target) return mid;
        else if(arr[mid] < target) mid++;
        else mid--;
    }

    return -1;
}

int main() {
    
}
