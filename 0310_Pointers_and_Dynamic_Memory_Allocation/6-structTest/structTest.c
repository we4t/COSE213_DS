#include <stdio.h>

struct student {
	int number;
	char name[10];
	double grade;
};

struct pstudent{
	int number;
	char name[10];
	double grade;
} s = {24, "kim", 4.3}; // 전역변수로 선언 가능.

int main(int argc, char *argv[]) {
    // struct student s;
	// s = {24, "Kim", 4.3};
	// 이렇게 선언, 정의할 수 없음.
	struct student s = {25, "123", 3.5};
	// name[10] : "1|2|3|\0"
	struct student scopy = {0,};
	scopy = s; // deep copy;
	scopy.grade = 4.0/11;
	printf("scopy.grade was modified, and its grade : %lf\n", scopy.grade);
	printf("s.grade : %lf\n", s.grade);
	//객체끼리 shallow copy 가능.
	
	return 0;
}