#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 51. Check if all digits are even
int isEvens(int n) {
    if (n == 0) return 1; // zero is even
    n = abs(n);
    while (n) {
        if ((n % 10) % 2 != 0) return 0;
        n /= 10;
    }
    return 1;
}

// Helper: check prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

// 52. Magic array
int isMagicArray(const vector<int> &a) {
    if (a.empty()) return 0;
    int sumPrimes = 0;
    for (int i = 1; i < a.size(); i++) {
        if (isPrime(a[i])) sumPrimes += a[i];
    }
    return sumPrimes == a[0] ? 1 : 0;
}

// 53. Complete array
int isComplete(const vector<int> &a) {
    vector<int> evens;
    for (int x : a)
        if (x % 2 == 0) evens.push_back(x);
    if (evens.empty()) return 0;
    int minEven = *min_element(evens.begin(), evens.end());
    int maxEven = *max_element(evens.begin(), evens.end());
    if (minEven == maxEven) return 0;
    for (int i = minEven + 1; i < maxEven; i++) {
        if (find(a.begin(), a.end(), i) == a.end()) return 0;
    }
    return 1;
}

// 54. Prime product
int isPrimeProduct(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && n % i == 0) {
            int other = n / i;
            if (isPrime(other)) return 1;
        }
    }
    return 0;
}

// 55. Fill array
vector<int> fillArray(const vector<int> &arr, int k, int n) {
    if (k <= 0 || n <= 0) return {};
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = arr[i % k];
    }
    return res;
}

// 56. Hollow array
int isHollow(const vector<int> &a) {
    int n = a.size();
    int left = 0, right = n - 1;
    while (left < n && a[left] != 0) left++;
    while (right >= 0 && a[right] != 0) right--;
    if (right - left + 1 < 3) return 0;
    int zeros = right - left + 1;
    if (left != n - 1 - right) return 0; // equal non-zero on both sides
    for (int i = left; i <= right; i++)
        if (a[i] != 0) return 0;
    return 1;
}

// 57. Bean array
int isBean(const vector<int> &a) {
    bool has9 = false, has13 = false;
    bool has7 = false, has16 = false;
    for (int x : a) {
        if (x == 9) has9 = true;
        if (x == 13) has13 = true;
        if (x == 7) has7 = true;
        if (x == 16) has16 = true;
    }
    if (has9 && !has13) return 0;
    if (has7 && has16) return 0;
    return 1;
}

// 58-60 are left as exercises but can be done similarly

int main() {
    // 51
    cout << "51. isEvens(2426): " << isEvens(2426) << endl;

    // 52
    vector<int> arr52 = {21,3,7,9,11,4,6};
    cout << "52. isMagicArray: " << isMagicArray(arr52) << endl;

    // 53
    vector<int> arr53 = {-5,6,2,3,2,4,5,11,8,7};
    cout << "53. isComplete: " << isComplete(arr53) << endl;

    // 54
    cout << "54. isPrimeProduct(22): " << isPrimeProduct(22) << endl;

    // 55
    vector<int> arr55 = {1,2,3,5,9,12,-2,-1};
    vector<int> filled = fillArray(arr55, 3, 10);
    cout << "55. fillArray: ";
    for (int x : filled) cout << x << " ";
    cout << endl;

    // 56
    vector<int> arr56 = {1,2,4,0,0,0,3,4,5};
    cout << "56. isHollow: " << isHollow(arr56) << endl;

    // 57
    vector<int> arr57 = {1,2,3,9,6,13};
    cout << "57. isBean: " << isBean(arr57) << endl;

    return 0;
}
