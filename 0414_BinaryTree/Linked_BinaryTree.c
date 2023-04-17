#include <stdio.h>

typedef struct node tp;
typedef struct node{
	int data;
	tp *lc;
	tp *rc;
};