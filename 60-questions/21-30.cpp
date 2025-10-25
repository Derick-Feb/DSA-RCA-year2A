#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

// 21. Check if a string is a palindrome
bool isPalindrome(const string &s) {
    string str;
    for (char c : s) {
        if (!isspace(c)) str += tolower(c); // ignore spaces & case
    }
    int n = str.size();
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-1-i]) return false;
    }
    return true;
}

// 22. Convert seconds to years
double secondsToYears(long long seconds) {
    return seconds / (365.0 * 24 * 60 * 60);
}

// 23. Count number of spaces
int countSpaces(const string &s) {
    int count = 0;
    for (char c : s) if (c == ' ') count++;
    return count;
}

// 24. Check if character is digit or letter
void charType(char c) {
    if (isdigit(c)) cout << c << " is a digit.\n";
    else if (isalpha(c)) cout << c << " is an alphabet letter.\n";
    else cout << c << " is neither digit nor letter.\n";
}

// 25. Word count function
void wordCount(const string &s) {
    int charsWithSpaces = s.size();
    int charsWithoutSpaces = 0;
    int words = 0;
    bool inWord = false;

    for (char c : s) {
        if (!isspace(c)) charsWithoutSpaces++;
        if (!isspace(c) && !inWord) { words++; inWord = true; }
        if (isspace(c)) inWord = false;
    }

    cout << "Characters (with spaces): " << charsWithSpaces << endl;
    cout << "Characters (without spaces): " << charsWithoutSpaces << endl;
    cout << "Number of words: " << words << endl;
}

// 26. Reverse a string
string reverseString(const string &s) {
    string r = s;
    int n = r.size();
    for (int i = 0; i < n/2; i++) swap(r[i], r[n-1-i]);
    return r;
}

// 27. Length of string without built-in functions
int stringLength(const string &s) {
    int len = 0;
    int i = 0;
    while (s[i] != '\0') { len++; i++; }
    return len;
}

// 28. Check palindrome without built-in functions
bool isPalindromeNoBuiltin(const string &s) {
    int start = 0, end = stringLength(s)-1;
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++; end--;
    }
    return true;
}

// 29. Convert string to uppercase
string toUpperCase(const string &s) {
    string res = s;
    for (char &c : res) if (islower(c)) c = toupper(c);
    return res;
}

// 30. Remove all spaces from a string
string removeSpaces(const string &s) {
    string res;
    for (char c : s) if (!isspace(c)) res += c;
    return res;
}

int main() {
    string testStr = "I was able no on elba saw I";
    cout << "21. Palindrome check: " << (isPalindrome(testStr) ? "Yes" : "No") << endl;

    long long johnSeconds = 1000000000;
    cout << "22. John is " << secondsToYears(johnSeconds) << " years old." << endl;

    string strWithSpaces = "Count the number of spaces here";
    cout << "23. Number of spaces: " << countSpaces(strWithSpaces) << endl;

    char ch = 'A';
    cout << "24. Character type check:\n"; charType(ch);

    string sentence = "This is a sample sentence.";
    cout << "25. Word count:\n"; wordCount(sentence);

    string strRev = "Hello World";
    cout << "26. Reversed string: " << reverseString(strRev) << endl;

    cout << "27. Length of string: " << stringLength(strRev) << endl;

    string strPal = "radar";
    cout << "28. Palindrome without builtin: " << (isPalindromeNoBuiltin(strPal) ? "Yes" : "No") << endl;

    string strLower = "hello";
    cout << "29. Uppercase string: " << toUpperCase(strLower) << endl;

    string strSpaces = "Remove all spaces";
    cout << "30. String without spaces: " << removeSpaces(strSpaces) << endl;

    return 0;
}