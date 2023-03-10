#include <stdio.h>

typedef struct {
    int age;
    char name[];
} STU;

int main(int argc, char* argv[])
{
    STU pt = {0,};
    printf("size of pt : %d\n", sizeof(pt));
    printf("value of pt.age : %d\n", pt.age);
    printf("value of pt.name : %n\n", pt.name);
    // printf("size of pt.name : %d\n", sizeof(pt.name)); 
    // error occurs since char[] is an incomplete type.
    return 0;
}