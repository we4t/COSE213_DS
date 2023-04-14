#include <stdio.h>
#define MAX_SIZE 100

int simple_find(char *string, char *pat) {
    // 순차 검색
    int i, j, k, lasts, lastp;
    lasts = strlen(string) - 1;
    lastp = strlen(pat) - 1;

    for (i = 0; i <= lasts; i++) {
        if (string[i] == pat[0]) {
            for (j = i + 1, k = 1; k <= lastp; k++, j++) {
                if (string[j] != pat[k])
                    break;
            }
            if (k > lastp)
                return i;
        }
    }
	return -1;
}

int main(void) {}