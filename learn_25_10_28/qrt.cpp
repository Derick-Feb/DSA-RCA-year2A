#include <iostream>
#include <iomanip>
using namespace std;

double my_abs(double num){
	if(num < 0) return -num;
	return num;
}

double nrm_sqrt(double num){
	if(num <= 0) return 0;

	double guess = num;
	double eps = 1e-9;

	while(true){
		double next_guess = guess - (guess*guess-num) / (guess+guess);
		if(my_abs(next_guess - guess) < eps) break;
		guess = next_guess;
	}

	return guess;
}

int main(){
	cout << "Enter a value: ";
	double num;
	cin >> num;

	cout << "The sqrt of " << num << " is " << setw(10) << fixed << setprecision(9) << nrm_sqrt(num); 
	
	return 0;
}
