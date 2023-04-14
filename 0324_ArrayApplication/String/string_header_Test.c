#include <stdio.h>
#include <string.h>

void strlenTest() {
    // size_t strlen(char *s)
    // size_t : unsigned int
    // 문자열 s의 길이를 구함.

    char string1[] = "asdf1";
    printf("%d\n", strlen(string1));
}

void strcpyTest() {
    // char *strcpy(char *s1, char *s2)
    // s2를 s1에 복사함.

    char string1[100];
    strcpy(string1, "asdfgt32");
    printf("%s\n", string1);
}

void strcatTest() {

    // char *strcat(char *s1, char *s2)
    // s2를 s1 끝에 붙여 넣음.

    char string1[] = "cate";
    char string2[] = "nate!";
    printf("%s\n", strcat(string1, string2));
}

void strcmpTest() {

    // int strcmp(char *s1, char *s2)
    // s1과 s2를 비교함.
    // 문자열 앞에서부터 아스키코드로 비교
    // s1 == s2 : 0,
    // s1 < s2 : -1
    // s1 > s2 : 1

    char s1[] = "strCpy";
    char s2[] = "strcpy";

    printf("%d\n", strcmp(s1, s2));
}

void strchrTest() {
    // char *strchr(char *s, int c)
    // s1에서 c가 등장하는 위치를 리턴함.

    char s1[] = "hello";
    printf("첫 l의 위치 : ");
    printf("%d\n", strchr(s1, 'l') - s1);
}

void strstrTest() {
    // char *strstr(char *s1, char *s2)
    // 문자열 s1에서 문자열 s2를 찾음

    char s1[] = "hellohello";
    char s2[] = "lloh";
    printf("hellohello에서 lloh의 위치 : ");
    printf("%d\n", strstr(s1, s2) - s1);
	printf("lloh 이후의 문자열 : ");
	printf("%s\n", strstr(s1, s2));

}

void strtokTest() {
	// char *strtok(char *s1, char *s2)
	// tokenize the string
	char str[] = "This is a test string";
	char *token = strtok(str, " ");
	// str에서 첫 " "을 찾고, 그 이전까지의 문자열을 token에 저장
	// 나머지 문자열을 str에 다시 저장.
	// 내부적으로는 문자열의 첫 " "(구분자)가 등장하는 자리에 '/0'을 넣어서 분리함.

	while (token != NULL){
		printf("%s\n", token);
		token = strtok(NULL, " ");
		// continue parsing the string
		// 만약 구분자(delimiter)가 문자열이면, 문자열 내에 존재하는 모든 문자들을 구분자로 사용함.
	}

	char str2[] = "This is a test sentence. It has multiple sentences! Can you handle it?";
    char *token2 = strtok(str2, ".!?");
    while (token2 != NULL) {
        printf("%s\n", token2);
        token2 = strtok(NULL, ".!?");
		// "This is a test sentence"
		// " It has multiple sentences"
		// " Can you handle it"
		// 이렇게 분리됨.
    }

}

int main(void) {
    strlenTest();
    strcpyTest();
    strcatTest();
    strcmpTest();
    strchrTest();
    strstrTest();
    strtokTest();
}