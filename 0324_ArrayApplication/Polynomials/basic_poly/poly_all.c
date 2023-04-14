#include <stdio.h>
#define MAX_DEGREE 101

typedef struct{
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

int main(int argc, char *argv[]) {
    polynomial a = { 5, {10, 0, 0, 0, 6, 3}};
    polynomial b = { 3, {5, 3, 1, 0}};
    return 0;
}