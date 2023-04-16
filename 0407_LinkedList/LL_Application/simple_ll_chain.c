#include <stdio.h>

typedef struct listNode LP;
typedef struct listNode {
    int data;
    LP *link
};

LP *concatenate(LP *ptr1, LP *ptr2) {
    LP *temp;
    if (!ptr1) {
        return ptr2;
    }
    if (!ptr2) {
        return ptr1;
    }
    for (temp = ptr1; temp->link; temp = temp->link)
        ;
		//move to end of ptr1 chain

    temp->link = ptr2;

    return ptr1;
}