#ifndef SWAP_H
#define SWAP_H

// Template function to swap two values of any type
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif
