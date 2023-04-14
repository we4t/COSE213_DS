#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main(void){
	char string[MAX_SIZE];
	char pattern[MAX_SIZE];
	char *t;

	strcpy(string, "ababbaabaa");
	strcpy(pattern, "aab");

	if(t = strstr(string, pattern)){
		// 존재하지 않으면 NULL값 리턴
		// 존재하면 문자열 시작하는 포인터 리턴
		printf("%s in $s\n", t, string);
	}
	else{
		prinf("The pattern was not found.\n");
	}
}