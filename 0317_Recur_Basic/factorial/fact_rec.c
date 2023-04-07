#include <stdio.h>

int factorial(int);

int main(int argc, char *argv[]) {

    int number = 5, result;
    result = factorial(number);

    return 0;
}

int factorial(int n) {
    if (n == 1) {
        return 1; // base case
    } else {
        return (n * factorial(n - 1));
    }
}