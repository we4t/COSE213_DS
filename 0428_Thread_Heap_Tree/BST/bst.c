#include <stdio.h>

/*
binary search 트리 :
1) 노드의 값들이 모두 다르다.
2) 왼쪽 서브트리는 루트보다 작다.
3) 오른쪽 서브트리는 루트보다 크다.
4) 왼쪽, 오른쪽 서브트리도 binary search tree이다.

search 방법 :
키 = 현재 : 성공
키 < 현재 : 왼쪽으로 이동
키 > 현재 : 오른쪽으로 이동
*/

typedef struct element {
    int key;
} element;
typedef struct node tp;
typedef struct node {
    element data;
    tp *lc;
    tp *rc;
};

element *search(tp *root, int k) {
    if (!root)
        return NULL;
    if (k == root->data.key)
        return &(root->data);
    if (k < root->data.key)
        return search(root->lc, k);
    return search(root->rc, k);
}

element *iterSearch(tp *tree, int k) {
    while (tree) {
        if (k == tree->data.key)
            return &(tree->data);
        if (k < tree->data.key)
            tree = tree->lc;
        else
            tree = tree->rc;
    }
    return NULL;
}

element *modifiedSearch(tp *tree, int k) {
    if (!tree)
        return NULL;
    while (tree) {
        if (k == tree->data.key)
            return NULL;
        else if (k < tree->data.key) {
            if (tree->lc)
                tree = tree->lc;
            else
                return tree;
        } else {
            if (tree->rc)
                tree = tree->rc;
            else
                return tree;
        }
    }
}

void insert(tp *node, int k) {
    tp *ptr, *temp;
    temp = modifiedSearch(node, k);
    if (temp || !(node)) {
        ptr = (tp *)malloc(sizeof(node));
        ptr->data.key = k;
        ptr->lc = ptr->rc = NULL;

        if (node) {
            if (k < temp->data.key) {
                temp->lc = ptr;
            } else
                temp->rc = ptr;
        } else
            node = ptr;
    }
}

// 삭제 : 
// 자식 없으면 그냥 제거
// 자식 하나만 있으면 위로 올라옴
// 자식 둘 다 있으면 
// 왼쪽 서브트리 중 가장 큰 노드 혹은
// 오른쪽 서브트리 중 가장 작은 노드로 대체

int main() {}