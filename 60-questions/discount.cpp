#include <iostream>
using namespace std;

double discount(int originalPrice, int discountPercent) {
    return originalPrice * (1.0 - discountPercent / 100.0);
}

int main() {
    int price, percent;
    cout << "Enter original price and discount percentage: ";
    cin >> price >> percent;
    printf("dis( %d, %d ) -> %.2f\n", price, percent, discount(price, percent));

    return 0;
}
