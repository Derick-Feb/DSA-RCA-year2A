#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize a vector with some values
    vector<int> numbers = {10, 20, 30, 40, 50};

    // 1 & 2. begin() and end()
    // Standard forward iteration
    cout << "Forward (begin to end): ";
    for(int* it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it < " ";
    }
    cout << endl;

    // 3 & 4. rbegin() and rend()
    // Reverse iteration (starts at 50, ends at 10)
    cout << "Reverse (rbegin to rend): ";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // 5 & 6. cbegin() and cend()
    // Constant forward iteration (cannot modify the values)
    cout << "Constant Forward (cbegin): ";
    for (auto cit = numbers.cbegin(); cit != numbers.cend(); ++cit) {
        // *cit = 100; // This would cause a compiler error
        cout << *cit << " ";
    }
    cout << endl;

    // 7 & 8. crbegin() and crend()
    // Constant reverse iteration
    cout << "Constant Reverse (crbegin): ";
    for (auto crit = numbers.crbegin(); crit != numbers.crend(); ++crit) {
        cout << *crit << " ";
    }
    cout << endl;

    return 0;
}

// crend(): returns a constant iterator pointing to the theoritical element that preceeds the first element of the vector
