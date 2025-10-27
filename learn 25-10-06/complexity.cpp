#include <iostream>
using namespace std;

int fun5(int n) {
   int i, j, m = 0;
   for (i = 1; i <= n; i *= 2) {
      for (j = 0; j <= i; j++) {
         cout << "(i: " << i << ", j: " << j << ")" << endl;
         m += 1;
      }
   }
    return m;
}

int main() {
   cout << "N = 100, Number of instructions: \n: " << fun5(100) << endl;
   return 0;
}
