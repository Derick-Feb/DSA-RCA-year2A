#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

// 31. Reverse subarray between start and end index
void rangedReversal(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// 32. Nth prime number
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int nthPrime(int n) {
    int count = 0, num = 2;
    while (true) {
        if (isPrime(num)) count++;
        if (count == n) return num;
        num++;
    }
}

// 33. Minimum distance between factors
int minDistance(int n) {
    vector<int> factors;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) factors.push_back(i);

    int minDist = INT_MAX;
    for (int i = 1; i < factors.size(); i++)
        minDist = min(minDist, factors[i] - factors[i-1]);
    return minDist;
}

// 34. Rock-Paper-Scissors
string rps(const string &p1, const string &p2) {
    if (p1 == p2) return "TIE";
    if ((p1=="rock" && p2=="scissors") || (p1=="scissors" && p2=="paper") || (p1=="paper" && p2=="rock"))
        return "Player 1 wins";
    return "Player 2 wins";
}

// 35. Count digit in number
int countDigit(int n, int digit) {
    if (n < 0 || digit < 0 || digit > 9) return -1;
    int count = 0;
    while (n) {
        if (n % 10 == digit) count++;
        n /= 10;
    }
    return count;
}

// 36. Difference between square of sum and sum of squares
int squareSumDifference(int N) {
    int sum = N*(N+1)/2;
    int sumSq = N*(N+1)*(2*N+1)/6;
    return sum*sum - sumSq;
}

// 37. Centered array
int isCentered(const vector<int> &arr) {
    int n = arr.size();
    if (n % 2 == 0) return 0;
    int mid = arr[n/2];
    for (int i = 0; i < n; i++) {
        if (i == n/2) continue;
        if (arr[i] <= mid) return 0;
    }
    return 1;
}

// 38. Difference of sum of odd and even numbers
int differenceOddEven(const vector<int> &arr) {
    int sumOdd = 0, sumEven = 0;
    for (int num : arr) {
        if (num % 2 == 0) sumEven += num;
        else sumOdd += num;
    }
    return sumOdd - sumEven;
}

// 39. Reverse integer
int reverseInteger(int n) {
    int sign = (n < 0) ? -1 : 1;
    n = abs(n);
    int rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev * sign;
}

// 40. Raindrop sounds
string raindrops(int n) {
    string result;
    if (n % 3 == 0) result += "Pling";
    if (n % 5 == 0) result += "Plang";
    if (n % 7 == 0) result += "Plong";
    if (result.empty()) result = to_string(n);
    return result;
}

// -------------------- MAIN --------------------
int main() {
    // 31
    vector<int> arr31 = {1,2,3,4,5,6};
    rangedReversal(arr31,1,3);
    cout << "31. Ranged Reversal: ";
    for(int x: arr31) cout << x << " ";
    cout << endl;

    // 32
    cout << "32. 6th prime: " << nthPrime(6) << endl;

    // 33
    cout << "33. minDistance(13013): " << minDistance(13013) << endl;

    // 34
    cout << "34. rps('rock','paper'): " << rps("rock","paper") << endl;

    // 35
    cout << "35. countDigit(32121,1): " << countDigit(32121,1) << endl;

    // 36
    cout << "36. squareSumDifference(10): " << squareSumDifference(10) << endl;

    // 37
    vector<int> arr37 = {3,2,1,4,5};
    cout << "37. isCentered: " << isCentered(arr37) << endl;

    // 38
    vector<int> arr38 = {1,2,3,4};
    cout << "38. differenceOddEven: " << differenceOddEven(arr38) << endl;

    // 39
    cout << "39. reverseInteger(-12345): " << reverseInteger(-12345) << endl;

    // 40
    cout << "40. raindrops(28): " << raindrops(28) << endl;

    return 0;
}
