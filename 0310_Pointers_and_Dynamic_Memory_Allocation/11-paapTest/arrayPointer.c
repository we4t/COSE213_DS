#include <stdio.h>

int main(void){
	int arr[2][4] = {1, 2};
	int (*ap)[4];
	ap = arr;
	printf("%d", *ap[2]);
}