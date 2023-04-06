#include <stdio.h>
#define MAX_TERMS 101

typedef struct {
    int row;
    int col;
    int value;
} term;

int main(int argc, char *argv[]) {
    term a[MAX_TERMS] = {3, 3, 3, {{0, 1, 3}, {1, 0, 8}, {2, 2, 5}}};
    return 0;
}