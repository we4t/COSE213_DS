#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // malloc 함수 정의 :
    // void *malloc(size_t size);
    int *p;
    p = (int *)malloc(sizeof(int));
    // malloc은 보이드 포인터를 리턴하고,
    // 이 때 함수의 인자는 바이트 수 이다.
    // 즉, sizeof(int)를 하면 4이고,
    // (int *)malloc(4)를 하면
    // 처음에 4 byte를 관리하는 void 포인터를 만들고,
    // 이 때 형 변환을 int 형 포인터로 제작함.

    // free 함수 정의 :
    // void free(void *ptr)
    // 여기서 ptr은 동적으로 할당된 메모리를 가리키는 포인터여야 함
    free(p);

    // realloc 함수 정의:
    // void *realloc(void *memblock, size_t size)
    int *pp;
    pp = (int *)malloc(sizeof(int) * 5);
    pp = (int *)realloc(pp, 7 * sizeof(int));

    // calloc 함수 정의 :
    // void *calloc(size_t n, size_t size)
	// n은 항목 수, size는 항목 당 사이즈

    int *ppp;
    ppp = (int *)calloc(5, sizeof(int));
    return 0;
}