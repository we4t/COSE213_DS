#include <stdio.h>

typedef struct {
	int age;
	char name[10];
} STU;

typedef struct{
	STU dex[10];
} sDEX;

int main(int argc, char *argv[]) {
	sDEX s = {{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"},{10, "13"} };
    
	
	
	return 0;
}