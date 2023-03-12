#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 1;
	double b = 4.66;
	char c = 'a';
	char d[10] = "andrew0112";
	void *p; // 참조하는 자료형에 관한 정보가 없는 포인터.

	p = &a;
	p = &b;
	p = &c;
	p = &d;

	// void 포인터는 바로 출력을 할 수 없기에, 타입캐스팅 (char *), (int *)로 형 변환을 해야 한다.

	printf("%s", (char *)p); // string은 참조 자료형이기 때문에, 캐릭터 포인터 형태로 형 변환하면 가능하다.

    printf("\n");
	return 0;
}