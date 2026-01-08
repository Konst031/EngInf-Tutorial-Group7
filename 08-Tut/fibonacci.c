#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    // Fehler abfangen
    if (n < 0) {
        return -1;
    }
    // "doppelter" base case
    if (n == 0 || n == 1) {
        return n;
    }
    // recursion case
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[]) {
    for (int i = -5; i < 20; i++) {
        printf("fib(%d) returns: %d\n", i, fib(i));
    }

    return 0;
}
