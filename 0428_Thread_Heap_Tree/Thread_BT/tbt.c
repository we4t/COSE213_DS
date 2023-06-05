#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct threadedTree tp;
typedef struct threadedTree {
    short int leftThread; // true if thread (no left child)
    tp *leftChild;
    char data;
    tp *rightChild;
    short int rightThread; // true if thread (no right child)
};

tp *insucc(tp *tree) {
    tp *temp;
    temp = tree->rightChild;
    if (!tree->rightThread) {
        while (!temp->leftThread)
            temp = temp->leftChild;
    }
    return temp;
}

tp *presucc(tp *tree) {
    tp *temp;
    temp = tree->leftChild;
    if (!tree->leftThread) {
        while (!temp->rightThread)
            temp = temp->rightChild;
    }
    return temp;
}

void tinorder(tp *tree) {
    tp *temp = tree;
    while (!temp->leftThread)
        temp = temp->leftChild;
    for (;;) {
        printf("%3c", temp->data);
        temp = insucc(temp);
        if (temp == tree)
            break;
    }
}

void insert_Right(tp *parent, tp *child) {
    tp *temp;
    child->rightChild = parent->rightChild;
    child->rightThread = parent->rightThread;
    child->leftChild = parent;
    child->leftThread = true;
    parent->rightChild = child;
    parent->rightThread = false;

    if (!child->rightThread) {
        temp = insucc(child);
        temp->leftChild = child;
    }
}

void insert_Left(tp *parent, tp *child) {
    tp *temp;
    if (!parent->leftThread) {
        temp = presucc(parent);
        temp->rightChild = child;
    }
    child->leftChild = parent->leftChild;
    child->leftThread = parent->leftThread;
    child->rightChild = parent;
    child->rightThread = true;
    parent->leftChild = child;
    parent->leftThread = false;
}

int main() {
    tp *header = malloc(sizeof(tp));
    header->leftThread = true;
    header->rightThread = true;
    header->rightChild = header;

    tp *tpArr[5];
    for (int i = 0; i < 5; i++) {
        tpArr[i] = malloc(sizeof(tp));
        tpArr[i]->data = (char)('a' + i);
    }

    insert_Left(header, tpArr[0]);
    insert_Left(tpArr[0], tpArr[1]);
    insert_Left(tpArr[1], tpArr[2]);
    insert_Right(tpArr[1], tpArr[3]);
    insert_Right(tpArr[0], tpArr[4]);

    tp *temp = insucc(tpArr[4]);
    temp->rightChild = header;
    temp->rightThread = true;

	tpArr[2]->leftChild = header;
	tpArr[2]->leftThread = true;

    tinorder(header);
    return 0;
}
