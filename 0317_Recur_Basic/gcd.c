#include <stdio.h>

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

int main(int argc, char *argv[]) {
    int a = 18, b = 8;

    printf("%d", gcd(a, b));
    return 0;
}