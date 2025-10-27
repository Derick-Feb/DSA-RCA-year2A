#include <iostream>
#include <array>

using namespace std;

int main(){

    // 1 st way: each element
    int numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }; 
    int n = 0;
    for(auto x: numbers) n++;
    cout << n << endl;

    // 2 nd way: using size of
    int count = sizeof(numbers) / sizeof(int);
    cout << count << endl;
    
    // 3 rd way: begin and end
    int count2 = end(numbers) - begin(numbers);
    cout << count << endl;
    
    return 0;
}