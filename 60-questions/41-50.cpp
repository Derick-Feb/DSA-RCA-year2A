#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

// 41. Common elements of two arrays
vector<int> commonElements(const vector<int> &a, const vector<int> &b) {
    vector<int> res;
    for (int x : a) {
        for (int y : b) {
            if (x == y) {
                res.push_back(x);
                break;
            }
        }
    }
    return res;
}

// 42. Count ones in binary representation
int countOnes(int n) {
    int count = 0;
    while (n) {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    return count;
}

// 43. Daphne array check
int isDaphne(const vector<int> &a) {
    if (a.empty()) return 0;
    bool even = a[0] % 2 == 0;
    for (int x : a) {
        if ((x % 2 == 0) != even) return 0;
    }
    return 1;
}

// 44. Odd-valent array
int isOddValent(const vector<int> &a) {
    bool hasOdd = false;
    bool hasDuplicate = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 != 0) hasOdd = true;
        for (int j = i+1; j < a.size(); j++) {
            if (a[i] == a[j]) hasDuplicate = true;
        }
    }
    return (hasOdd && hasDuplicate) ? 1 : 0;
}

// 45. Normal number
int isNormal(int n) {
    if (n <= 0) return 0;
    for (int i = 3; i <= n/2; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

// 46. All possibilities array
int isAllPossibilities(const vector<int> &a) {
    int n = a.size();
    if (n == 0) return 0;
    vector<int> check(n, 0);
    for (int x : a) {
        if (x < 0 || x >= n) return 0;
        check[x] = 1;
    }
    for (int i = 0; i < n; i++)
        if (!check[i]) return 0;
    return 1;
}

// 47. Filter array
int isFilter(const vector<int> &a) {
    bool has9 = false, has11 = false;
    bool has7 = false, has13 = false;
    for (int x : a) {
        if (x == 9) has9 = true;
        if (x == 11) has11 = true;
        if (x == 7) has7 = true;
        if (x == 13) has13 = true;
    }
    if (has9 && !has11) return 0;
    if (has7 && has13) return 0;
    return 1;
}

// 48. Digit sum check
int isDigitSum(int n, int m) {
    if (n < 0 || m < 0) return -1;
    int sum = 0;
    int temp = n;
    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum < m ? 1 : 0;
}

// 49. Fine array (twin primes)
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int isFineArray(const vector<int> &a) {
    for (int x : a) {
        if (isPrime(x)) {
            if (!((isPrime(x-2) && find(a.begin(), a.end(), x-2)!=a.end()) ||
                  (isPrime(x+2) && find(a.begin(), a.end(), x+2)!=a.end())))
                return 0;
        }
    }
    return 1;
}

// 50. Balanced array
int isBalanced(const vector<int> &a) {
    for (int x : a) {
        if (find(a.begin(), a.end(), -x) == a.end()) return 0;
    }
    return 1;
}

// -------------------- MAIN --------------------
int main() {
    // 41
    vector<int> arrA = {1,8,3,2}, arrB = {4,2,6,1};
    vector<int> res41 = commonElements(arrA, arrB);
    cout << "41. Common elements: ";
    for(int x : res41) cout << x << " ";
    cout << endl;

    // 42
    cout << "42. countOnes(9): " << countOnes(9) << endl;

    // 43
    vector<int> arr43 = {2,4,6};
    cout << "43. isDaphne: " << isDaphne(arr43) << endl;

    // 44
    vector<int> arr44 = {9,3,4,9,1};
    cout << "44. isOddValent: " << isOddValent(arr44) << endl;

    // 45
    cout << "45. isNormal(9): " << isNormal(9) << endl;

    // 46
    vector<int> arr46 = {1,2,0,3};
    cout << "46. isAllPossibilities: " << isAllPossibilities(arr46) << endl;

    // 47
    vector<int> arr47 = {1,2,3,9,6,11};
    cout << "47. isFilter: " << isFilter(arr47) << endl;

    // 48
    cout << "48. isDigitSum(32121,10): " << isDigitSum(32121,10) << endl;

    // 49
    vector<int> arr49 = {4,7,9,6,5};
    cout << "49. isFineArray: " << isFineArray(arr49) << endl;

    // 50
    vector<int> arr50 = {-2,3,2,-3};
    cout << "50. isBalanced: " << isBalanced(arr50) << endl;

    return 0;
}