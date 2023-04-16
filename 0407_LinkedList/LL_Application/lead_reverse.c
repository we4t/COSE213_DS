#include <stdio.h>

typedef struct listNode LP;
typedef struct listNode {
    int data;
    LP *link
};

LP* invert(LP *lead){
	LP *middle, *trail;
	middle = NULL;

	while(lead){
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}