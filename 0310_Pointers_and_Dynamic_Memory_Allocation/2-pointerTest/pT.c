#include <stdio.h>

typedef struct {
    int age;
    char name;
} STU;

int main(int argc, char *argv[]) {
    int *ptss = NULL; // 기본적인 포인터 초기화 방법
	int i = 1;
	ptss = &i;
	printf("%d\n", ptss);
	ptss++;
	printf("%d\n", ptss);
	// 위의 출력과 4 차이나는데, 그 이유는 int가 4바이트이고 포인터의 기본 움직이는 사이즈는 데이터타입에 관련됨
	
	
	STU pt = {
        1, 'a'
    };
    printf("size of pt : %d\n", pt);
    printf("value of pt.age : %d\n", pt.age);
    printf("value of pt.name : %c\n", pt.name);
    // printf("size of pt.name : %d\n", sizeof(pt.name));
    // error occurs since char[] is an incomplete type.
    return 0;
}