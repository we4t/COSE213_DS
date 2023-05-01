#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX_STACK_SIZE 100

typedef struct 
{
	int row, col, dir;
} element;

element stack[MAX_STACK_SIZE];

int mark[9][9];
int maze[9][9];
int top;

void path(void){
	int i, row, col, nr, nc, dir;
	int found = FALSE;
	element position;
	mark[1][1] = 1;
	top = 0;

	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	while(top > -1 && !found){
		position = delete(&top);
		row = position.row;
		col = position.col;
		dir = position.dir;

		while(dir < 8 && !found){
			nr = row + move[dir].vert;
			nc = row + move[dir].horiz;

			if(nr == exit_row && nc == exit_col)
				found = true;
			else if(!maze[nr][nc] && !mark[nr][nc]){
				mark[nr][nc] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				add(&top, position);
				row = nr;
				col = nc;
				dir = 0;
			}
			else ++dir;
		}
	}
	if (found){
		printf("< PATH > \n");
		printf("row col \n");
		for(i = 0; i <= top; i++){
			printf("%2d %5d", stack[i].row, stack[i].col);
		}
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", exit_row, exit_col);
	}
	else printf("경로 없음\n");
}