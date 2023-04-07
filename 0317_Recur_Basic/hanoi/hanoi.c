#include <stdio.h>

int move = 0;
int hanoi_num = 3;

// hanoi_algorithm :
// 1. n개의 원판을 옮긴다. source : 현위치, auxiliary : 들러리, destination :
// 목적지
// 2. n-1개의 원판을 source에서 auxiliary로 옮긴다.
// 3. 마지막 원판을 destination으로 옮긴다.
// 4. auxiliary에 위치한 n-1개의 원판을 destination으로 옮긴다. -> 무한 반복.
// base case : n == 1일 때

void hanoi(char source, char auxiliary, char destination, int to_move_num) {
    move++;
    if (to_move_num - 1) {
        hanoi(source, destination, auxiliary, to_move_num - 1);
    }
    printf("move %d from %c to %c \n", to_move_num, source, destination);
    if (to_move_num - 1) {
        hanoi(auxiliary, source, destination, to_move_num - 1);
    }
}

int main(int argc, char *argv[]) {
    hanoi('A', 'B', 'C', hanoi_num);
    printf("%d\n", move);
    return 0;
}