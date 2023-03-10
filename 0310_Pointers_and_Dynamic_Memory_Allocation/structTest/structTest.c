#include <stdio.h>

struct STU{
    int age;
    char name[10];
};

int main(void)
{
    struct STU kim = {10, "dd"};
    struct STU kimp = {0,};
    
    kimp = kim;
    kimp.age = 100;
    printf("%d", kim.age); //not a shallow copy, deep copy.

    return 0;
}