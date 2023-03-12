#include <stdio.h>

int main(int argc, char *argv[]) {

    int num[3] = {1, 2, 3};
    printf("%d\n", num);
    printf("%d, %d\n", num, *(num));
    printf("%d, %d\n", num + 1, *(num + 1));
    printf("%d, %d\n", num + 2, *(num + 2));

	int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for(int i = 0; i < 9; i++)
	printf("%d\n", arr+i); // 1 더하면 12가 추가되는데, 그 이유는 arr에는 int 형 길이 3 배열만큼 이동하기 때문.

	printf("%d\n", *(*(arr+1)+2)); // 6
    return 0;
}