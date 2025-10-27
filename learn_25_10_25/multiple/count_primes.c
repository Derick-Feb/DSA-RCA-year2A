#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int is_prime_(int *n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 2) {
        printf("Number must be greater than 1.\n");
        return 1;
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        int i_copy = i; // Create a copy of i to pass to is_prime_
        if (is_prime_(&i_copy)) {
            count++;
        }
    }

    printf("Numbers of prime numbers up to %d: %d\n", n, count);
    return 0;
}