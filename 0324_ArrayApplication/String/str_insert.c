#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void strnins(char *s, char *t, int i) {
    // insert string t into string s at position i
    // position : index (starts from 0)

    char string[MAX_SIZE] = "";
    char *temp = string;
    if (i < 0 && i > strlen(s)) {
        fprintf(stderr, "Position is out of bounds\n");
        exit(1);
    }
    if (!strlen(s)) // s가 공백이면 t를 s에 복사.
        strcpy(s, t);
    
    else if (strlen(t)) {
        strncpy(temp, s, i);
        // strncpy(char* new, char* old, int num)
        // old의 앞에서부터 num개의 문자를 new에 넣음

        strcat(temp, t);
        strcat(temp, s + i);
        srcpy(s, temp);
    }
}

int main(void) {
    char string1[MAX_SIZE], *s = string1;
    char string2[MAX_SIZE], *t = string2;

    strcpy(string1, "amobile");
    strcpy(string2, "uto");

    strnins(string1, string2, 1);
    printf("%s \n %s ", string1, string2);

}