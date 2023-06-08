#include <stdio.h>
#define MAX_CHAR 10
#define TABLE_SIZE 13 // prime number
#define IS_FULL(ptr) (!ptr)

typedef struct {
    int key;
} element;

typedef struct list listPtr;
typedef struct list {
    element item;
    listPtr *link;
};

element ht[TABLE_SIZE];
listPtr *hashTable[TABLE_SIZE];

unsigned int stringToInt(char *key) {
    int number = 0;
    while (*key) {
        number += *key++;
        /*
        if(*key)
            number += ((int) *key++) << 8;
        */
    }
    return number;
}

element *search(int k) {
    int i;
    int homeBucket = hash(k);
    for (i = homeBucket; ht[i] && ht[i]->key != k;) {
        i = (i + 1) % TABLE_SIZE;
        if (i == homeBucket)
            return NULL;
    }
    if (ht[i]->key == k)
        return ht[i];
    return NULL;
}