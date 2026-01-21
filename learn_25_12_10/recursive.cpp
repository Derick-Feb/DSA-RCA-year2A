#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/*
The recursive function:
return_datatype function_name(parameters){
    if(base_case_condition){
        return base_case_value;
    }
    // recursive case
    return combine(function_name(modified_parameters));

    //combine could be any operation like +, *, -, etc.
    //
}
*/

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// sum of n and number less than it
int sum_digits(int n){
    if(n < 10) return n;
    return sum_digits(n / 10) + n % 10;
}


// count digits in number
int count_digits(int n){
    if(n <= 10) return 1;
    return 1 + count_digits(n / 10);
}

string reverse_string(string &word, int start = 0){
    int n = word.size();
    if(n <= start) return "";
    return reverse_string(word, start+1) + word[start];
}

int reverse_number(int num, int rev = 0){
    if(num == 0 ) return rev;
    return reverse_number(num/10, rev*10 + num%10);
}

double nrm_sqrt_recursive(double num, double guess){
    if(num < 0) cerr << "Error: Negative input" << endl;
    if(num == 0 || num == 1) return num;

    double next_guess = guess - (guess * guess - num) / (2 * guess);
    if(abs(next_guess-guess) < 1e-7) return next_guess;
    return nrm_sqrt_recursive(num, next_guess);
}

int pow(int a, int b){
    if(b == 1) return a;
    return pow(a, b-1) * a;
}

template <typename T>
bool is_array_sorted(T arr[], int n, int start=0){
    if(start >= n-1) return true;
    if(arr[start] > arr[start+1]) return false;
    return is_array_sorted(arr, n, start+1);
}

int count_occurence(int num, int n){
    if(num == n) return 1;
    if(num < 10) return 0;

    if(num%10 == n)
        return count_occurence(num/10, n) + 1;
    else
        return count_occurence(num/10, n);
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
