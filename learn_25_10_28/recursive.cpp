#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// int factorial(int n){
//     if (n == 0) return 1;
//     return n * factorial(n -1);
// }

// int sum(int n){
//     if (n == 0) return  0;
//     return n + sum(n - 1);
// }

// int fibonnaci(int n){
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     return fibonnaci(n-1) + fibonnaci(n-2);
// }

// string reverse_string(string word, int start = 0){
//     size_t n = word.size();
//     if (start >= n) return "";
//     return reverse_string(word, start+1) + word[start];
// }

// int count_digits(int num) {
//     if(num < 10) return 1;
//     return 1 + count_digits(num/10);
// }

// int sum_digits(int num) {
//     if(num < 10) return num;
//     return sum_digits(num / 10) + (num % 10);
// }

// int reverse_number(int num, int rev = 0) {
//     if(num == 0) return num;
//     return reverse_number(num / 10, (rev * 10) + (num % 10));
// }

// double nrm_sqrt_recursive(double num, double guess = -1) {
//     if (num < 0) throw invalid_argument("Cannot take sqrt of negative number");
//     if (num == 0) return 0;

//     if (guess < 0) guess = num;
//     // double next_guess = guess - (guess*guess-num) / (guess+guess);
//     double next_guess = guess - (guess*guess*guess - num) / (3 * (guess*guess));

//     if(abs(next_guess - guess) < 1e-9) return next_guess;
    
//     return nrm_sqrt_recursive(num, next_guess);
// }

// double pow_recursive(double num, int n){
//     if(n == 0) return 1;
//     if(n == 1) return num;
//     return num * pow_recursive(num, n-1);
// }

// template <typename T>
// bool array_sorted(T Arr[], int n, int start = 0){
//     if(start >= n-1) return true;
//     if (Arr[start] > Arr[start + 1]) return false;

//     return array_sorted(Arr, n, start + 1);
// }

int count_zero(int num) {
    if(num == 0) return 1;
    if(num < 10) return 0;

    int last = num % 10;
    
    if (last == 0) return 1 + count_zero(num / 10);
    else return count_zero(num / 10);
}

int main() {
    // cout << "sqrt(27) is: " << nrm_sqrt_recursive(27);
    return 0;
}
