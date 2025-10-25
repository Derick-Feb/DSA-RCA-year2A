#include <bits/stdc++.h>
using namespace std;

void stringPrint(const string &str, int i = 0) {
	if(i == str.size()) return;
	cout << str[i];
	return stringPrint(str, i + 1);
}

void stringReversePrint(const string &str, int i = 0) {
	if(i == str.size()) return;
	stringPrint(str, i + 1);
	cout << str[i];
}

void stringRemoveChar(const string &str, char ch, int i = 0) {
	if(i == str.size()) return;
	if (str[i] != ch) cout << str[i];
	stringRemoveChar(str, ch, i + 1);
}

int main() {
	string test =  "abc";

	// stringPrint(test);
	stringReversePrint(test);

	cout << "\n";

	return 0;
}
