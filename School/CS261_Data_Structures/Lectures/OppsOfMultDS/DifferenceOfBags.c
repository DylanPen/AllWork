#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct Customer {
    int ID;
    int time;
};

struct DynArr {
    int *data;
    int size;
    int capacity;
};

void initBag(struct DynArr *b, int capacity);
void removeAllBag(struct DynArr *b, int val);
void printBag(struct DynArr *b);
void DiffBags(struct DynArr *b1, struct DynArr *b2);

int main() {
    struct DynArr bag1;
    struct DynArr bag2;
    int values1[] = {1, 3, 5, 7, 9};
    int values2[] = {2, 4, 6, 8, 9};
    int size = 5;

    initBag(&bag1, size);
    int i;
    for(i = 0; i < size; i++) {
        bag1.data[i] = values1[i];
    }
    bag1.size = size;

    initBag(&bag2, size);
    for(i = 0; i < size; i++) {
        bag2.data[i] = values2[i];
    }
    bag2.size = size;

    printf("Original Bag 1: \n");
    printBag(&bag1);

    printf("Original Bag 2: \n");
    printBag(&bag2);

/*
    int valToRemove = 1;
    printf("Removing all instances of %d:\n", valToRemove);
    removeAllBag(&bag, valToRemove);
*/
    DiffBags(&bag1, &bag2);
    printBag(&bag1);
    printBag(&bag2);

    free(bag1.data);
    free(bag2.data);
    return 0;
}

void initBag(struct DynArr *b, int capacity) {
    assert(b && capacity > 0);
    b->data = (int *)malloc(capacity * sizeof(int));
    assert(b->data != NULL);
    b->size = 0;
    b->capacity = capacity;
}

void DiffBags(struct DynArr *b1, struct DynArr *b2){
    assert(b1 && b2);
    if(b1->size){
        int i;
        for(i = 0; i < b2->size; i++){
            removeAllBag(b1, b2->data[i]);
        }
    }
}

void removeAllBag(struct DynArr *b, int val){
    assert(b);
    int i;
    for(i = 0; i < b->size; i++){
        while(b->data[i] == val){
            int j;
            for(j = i; j < b->size; j++){
                b->data[j] = b->data[j+1];
            }
            b->size--;
        }
    }
}

void printBag(struct DynArr *b) {
    assert(b);
    if (b->size == 0) {
        printf("[empty]\n");
        return;
    }
    int i;
    for (i = 0; i < b->size; i++) {
        printf("%d ", b->data[i]);
    }
    printf("\n");
}
