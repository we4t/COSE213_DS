#include <stdio.h>

typedef struct {
	int age;
	char name[10];
	int grade;
} STU;

int main(int argc, char *argv[]) {
    STU s = {10, "정승우", 3.7}; // 
	STU *p;
	p = &s;
	printf("%d\n", (*p).grade);
	printf("%s\n", (*p).name);
	// *p.grade -> p.grade 먼저 연산 -> 에러.
	
	return 0;
}