#include <stdio.h>

int getLen(char* str){
	int len = 0;
	for(; *(str+len); len++);
	return len;
}

void printReverse(char* str, int index, int len){
	if(index < len){
		printReverse(str, index + 1, len);
	}
	printf("%c", *(str + index));
}

int main(int argc, char *argv[]) {
    
	char* str = "helloWorld!";
	int len = getLen(str);
	printReverse(str, 0, len);

    return 0;
}