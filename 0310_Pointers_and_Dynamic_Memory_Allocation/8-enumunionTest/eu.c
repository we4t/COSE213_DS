#include <stdio.h>

enum levels { a, b, c }; // 0, 1, 2
// 초기값 설정 안 하면 앞에서부터 0, 1, 2 ...

typedef enum _car_color {
    red = 1,
    green = 2, // 세미콜론 아님.
    yellow = 3
} CAR_COLOR;
union student {
    int num;
    double gd;
};

int main(int argc, char *argv[]) {
    enum levels grade;
    grade = a;
    printf("%d\n", grade);

    CAR_COLOR myCarColor;
    myCarColor = red;
    printf("%d\n", myCarColor);

    union student s = {10};
    s.gd = 3.14;
    for (int i = 63; i >= 0; i--) {
        int mask = 1 << i;
        printf("%d", s.num & mask ? 1 : 0);

        if (i % 8 == 0)
            printf(" ");
    }
	printf("\n");
    printf("%f\n", s.gd);
    return 0;
}