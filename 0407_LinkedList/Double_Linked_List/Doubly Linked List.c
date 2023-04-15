#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

typedef struct node NP;
typedef struct node {
    NP *llink;
    element item;
    NP *rlink;
};

void dinsert(NP *node, NP *newNode) {
    // node 뒤에 newNode
    newNode->llink = node;
    newNode->rlink = node->rlink;
	node->rlink->llink = newNode; 
	// 이거 조금 신박하달까..
	// rlink를 수정하기 전에 미리 rlink의 llink부터 수정하기.
	node->rlink = newNode;
}

void ddelete(NP *headNode, NP *deleted){
	if( headNode == deleted ){
		printf("Head 노드 삭제 불가.\n");
	}
	else{
		deleted->rlink->llink = deleted->rlink;
		deleted->llink->rlink = deleted->llink;
		free(deleted);
	}
}