#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct threadedTree threadedPointer;
typedef struct threadedTree {
    short int leftThread;
    threadedPointer *leftChild;
    int data;
    threadedPointer *rightChild;
    short int rightThread;
} threadedTree;

threadedPointer *insucc(threadedPointer *tree) {
    threadedPointer *temp;
    temp = tree->rightChild;
    if (!tree->rightThread) {
        while (!temp->leftThread) {
            temp = temp->leftChild;
        }
    }
    return temp;
}

void tinorder(threadedPointer *tree) {
    threadedPointer *temp = tree;
    for (;;) {
        temp = insucc(temp);
        if (temp == tree)
            break;
        printf("%3d", temp->data);
    }
}

void insert_Right(threadedPointer *parent, threadedPointer *child) {

    threadedPointer *temp;
    child->rightChild = parent->rightChild;
    child->rightThread = parent->rightThread;
    child->leftChild = parent;
    child->leftThread = TRUE;
    parent->rightChild = child;
    parent->rightThread = FALSE;
    if (!child->rightThread) {
        temp = insucc(child);
        temp->leftChild = child;
    }
}

int main() {

    threadedPointer *header = malloc(sizeof(threadedPointer));
    header->leftChild = header;
    header->data = 0;
    header->leftThread = FALSE;
    header->rightThread = FALSE;
    threadedPointer *nodes[8];
    for (int i = 0; i < 8; i++) {
        nodes[i] = malloc(sizeof(threadedPointer));
    }
    header->rightChild = nodes[1];

    for (int i = 1; i < 8; i++) {
        nodes[i]->data = i;
        nodes[i]->leftThread = i <= 3 ? FALSE : TRUE;
        nodes[i]->rightThread = i <= 3 ? FALSE : TRUE;
        if (2 * i <= 7) {
            nodes[i]->leftChild = nodes[2 * i];
        }
        if (2 * i + 1 <= 7) {
            nodes[i]->rightChild = nodes[2 * i + 1];
        }
    }
    nodes[4]->leftChild = header;
    nodes[4]->rightChild = nodes[2];
    nodes[5]->leftChild = nodes[2];
    nodes[5]->rightChild = nodes[1];
    nodes[6]->leftChild = nodes[1];
    nodes[6]->rightChild = nodes[3];
    nodes[7]->leftChild = nodes[3];
    nodes[7]->rightChild = header;

    threadedPointer *h = malloc(sizeof(threadedPointer));
    h->data = 8;
    h->leftThread = FALSE;
    h->rightThread = FALSE;

    printf("1. Inorder successor : \n");
    tinorder(header);
    printf("\n");
    insert_Right(nodes[1], h);
    printf("2. Inserting <node 8> : \n");
    tinorder(header);
    printf("\n");

    return 0;
}