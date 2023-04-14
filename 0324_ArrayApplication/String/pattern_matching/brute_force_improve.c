#include <stdio.h>
#define MAX_SIZE 100

int simple_find(char *string, char *pat) {
    // 순차 검색, 뒷 글자부터.

    int i, j, start = 0, lastp, lasts, endmatch;
    lastp = strlen(pat) - 1;
    lasts = strlen(string) - 1;
	endmatch = lastp;
	for(; endmatch <= lasts; endmatch++, start++){
		if(string[endmatch] == pat[lastp]){
			for(j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++);
			if (j == lastp) return start;
		}
	}
	return -1;
}

int main(void) {}