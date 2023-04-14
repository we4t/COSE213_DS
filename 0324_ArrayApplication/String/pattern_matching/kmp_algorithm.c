#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
int failure[MAX_SIZE];

/*
        kmp 알고리즘의 주된 아이디어 :
        패턴을 찾기 전에
        패턴을 찾을 문자열의
        반복되는 부분을 기록해놔서
        패턴을 찾을 때 겹치는 부분을 다시 검사하지 말자!

        failure[j]의 의미 :
        뒤에서 부터 failure[j] + 1만큼의 부분 문자열과
        앞에서부터의 failure[j] + 1만큼의 부분 문자열이 일치함.
        즉, -1이면 0개, 없다는 거고
        failure[j] == 3이면 앞에서 4개, 뒤에 4개가 겹친다는거.
*/

void fail(char *pat) {
    int i, j, n = strlen(pat);
    failure[0] = -1; // 초기값 : -1
    for (j = 1; j < n; j++) {
        i = failure[j - 1];
        // j의 iteration은 failure의 j index를 채우기 위함이다.
        // failure 배열에서 -1이란 접두사랑 접미사가 같은 부분이 없다는 것을
        // 뜻함. 즉, i는 failure[j]를 계산하기 위해 사용되며, j-1번째까지의
        // 문자열에서 접미사랑 접두사가 같을 때와 다를 때 모두 j-1번째의 기록을
        // 이용해서 손쉽게 구할 수 있음..

        while ((pat[i + 1] != pat[j]) && i >= 0) {
            // i는 j-1값을 기준으로 했기 때문에,
            // i+1과 j를 비교한다.
            // 이 때, while 안의 값이 참인 경우는
            // j-1까지에서의 패턴 이후의 부분패턴이 맞지 않거나, i가 음수인
            // 경우. (즉, 겹치는게 없을 때 까지..) i = failure[i]의 의미는, 0 ~
            // i + 1까지는 겹치지 않기 때문에, failure[i]의 값으로 축소해서
            // 해석하겠다는 뜻임. 즉,
            i = failure[i];
        }
        if (pat[i + 1] == pat[j])
            failure[j] = i + 1;
        else
            failure[j] = -1;
    }
}

int pmatch(char *string, char *pat) {
    int i = 0, j = 0;
    int lens = strlen(string), lenp = strlen(pat);
    while (i < lens && j < lenp) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        } else if (j == 0)
            i++;
        else
            j = failure[j - 1] + 1;
    }
    return ((j == lenp) ? i - lenp : -1);
    // j 가 len가 되기 위해선 패턴 매칭이 성공해야 함.
    // 이 때의 i는 string에 존재하는 패턴 이후의 문자를 가르키고 있음.
    // 그러므로, 패턴이 첫 등장하는 인덱스는
    // i - 1 (패턴의 끝 인덱스) 에서 (lenp - 1)칸 (패턴의 길이) 뒤로 가야 하므로
    // i - lenp이다.
}

int main(void) {
    char string[MAX_SIZE] = "abcabcabcabc";
    char pattern[MAX_SIZE] = "cabcab";
    int i;
    fail(pattern);
    for (i = 0; i < 10; i++)
        printf("%d ", failure[i]);
    printf("\n");
    printf("검색 위치 : %d\n", pmatch(string, pattern));
}