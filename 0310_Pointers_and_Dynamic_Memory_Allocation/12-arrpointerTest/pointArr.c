#include <stdio.h>

int main(int argc, char *argv[]) {
    char *fruits[4] = {"apple", "blueberry", "orange", "melon"};

    int i;

    for (i = 0; i <= 3; i++) {
        printf("%c\n", fruits[i][0]);
    }
    return 0;
}