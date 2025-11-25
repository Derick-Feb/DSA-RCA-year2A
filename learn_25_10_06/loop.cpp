#include <iostream>
using namespace std;

int main() {
	//algorithm analysis

	int count = 0;
	for(int i = 0; i < 1000000; i++) {
		for(int j = 0; j < 1000000;  j++) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}