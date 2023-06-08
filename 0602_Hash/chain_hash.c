#include <stdio.h>

typedef struct {
    int key;
} element;

typedef struct list np;
typedef struct list{
	element item;
	np *link;
};

np *ht[13];

element* search(int k){
	np *cur;
	int homeBucket = hash(k);
	for(cur = ht[homeBucket]; cur; cur = cur->link){
		if(cur->link->item.key == k)
			return &cur->link->item;
	}
	return NULL;
}