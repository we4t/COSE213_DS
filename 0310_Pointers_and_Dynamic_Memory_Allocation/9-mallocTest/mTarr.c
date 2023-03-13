#include <stdio.h>
#include <stdlib.h> // malloc, free

int main(int argc, char *argv[]) {
    int i, size = 5;
    int *arr;

    arr = (int *)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        *(arr + i) = i;
    }

    for (i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }

	free(arr);

    return 0;
}