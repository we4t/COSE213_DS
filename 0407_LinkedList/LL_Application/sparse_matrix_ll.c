#include <stdio.h>
#include <stdlib.h>
typedef enum {head, entry} tagfield;

typedef struct{
	int row;
	int col;
	int value;
} entryNode;

typedef struct matrixNode mp;
typedef struct
{
	mp *down;
	mp *right;
	tagfield tag;
	union{
		mp *next;
		entryNode entry;
	} u;
}matrixNode;

mp* mread(void){
	int numRows, numCols, numTerms, numHeads, i;
	int row, col, value, curRow;
	mp *temp, *last, *node;

	scanf("%d %d", &numRows, &numCols);
	scanf("%d", &numTerms);

	numHeads = numCols > numRows ? numCols : numRows;

	node = (mp*)malloc(sizeof(mp));
	node->tag = entry;
	node->u.entry.row = numRows;
	node->u.entry.col = numCols;

	if(!numHeads) node -> right = node;
	else{
		for(i = 0; i < numHeads; i++){
			temp = (mp*)malloc(sizeof(mp));
			hdnode[i] = temp;
			hdnode[i] -> tag = head;
			hdnode[i] -> right = temp;
			hdnode[i] -> u.next = temp;
		}
		curRow = 0;
		last = hdNode[0];
		for(i = 0; i < numTerms; i++){
			scanf("%d %d %d", row, col, value);
			
			if(row > curRow){
				last->right = hdNode[curRow];
				curRow = row;
				last = hdNode[row];
			}

			temp = (mp*) malloc(sizeof(mp));
			temp->tag = entry;
			temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;

			last->right = temp;
			last = temp;

			hdnode[col]->u.next->down = temp;
			hdnode[col]->u.next = temp;
		}
		last->right = node[curRow];

		for(i = 0; i < numCols; i++){
			hdnode[i]->u.next->down = hdnode[i];
		}
		for(i = 0; i < numHeads-1; i++){
			hdnode[i]->u.next = hdnode[i+1];
		}
		hdnode[numHeads - 1]->u.next = node;
		node->right = hdnode[0];
	}
	return node;
}

void mwrite(mp *node){
	int i;
	mp *temp, *head;

	head = node -> right;
	printf("%d %d\n", node->u.entry.row, node->u.entry.col);
	printf("row col val\n");

	for(i = 0; i < node->u.entry.row; i++){
		for(temp = head->right; temp != head; temp = temp ->right){
			printf("%3d %3d %3d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
		}
		head = head -> u.next;
	}
}


void merase(mp *node){
	int i, num, heads;
	mp *x, *y, *head = (node)->right;
	for(i = 0; i < node->u.entry.row; i++){
		y = head -> right;
		while(y != head){
			x = y;
			y = y->right;
			free(x);
		}
		x = head;
		head = head->u.next;
		free(x);
	}
	y = head;
	while(y!=node){
		x = y;
		y = y ->u.next;
		free(x);
	}
	free(node);
	node = NULL;
}