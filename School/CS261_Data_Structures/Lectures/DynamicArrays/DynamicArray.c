#include "DynamicArray.h"
#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char **argv){
    struct dyArr Dynamo;
    initDynArr(&Dynamo, 10);
    addDynArr(&Dynamo, 6);
    addDynArr(&Dynamo, 32);
    addDynArr(&Dynamo, 453);
    addDynArr(&Dynamo, 56);
    addDynArr(&Dynamo, 89);
    addDynArr(&Dynamo, 9);
    addDynArr(&Dynamo, 0);
    addDynArr(&Dynamo, 8);
    addDynArr(&Dynamo, 1);
    addDynArr(&Dynamo, 12);
    addDynArr(&Dynamo, 8);
    addDynArr(&Dynamo, 4);

    _printDynArr(&Dynamo);

    removeDynArr(&Dynamo, 8);

    _printDynArr(&Dynamo);

}

void _printDynArr(struct dyArr *da){
    int i;
    for(i = 0; i < da->size; i++){
        printf("%d \n", da->data[i]);
    }
    printf("%d", da->size);
    printf("%d", da->capacity);

}

void initDynArr(struct dyArr *da, int cap){ /*~~~QUIZ PROBLEM~~~*/
    assert(da != NULL && cap >= 0); /* Check all arguments*/
    da->data = NULL;
    da->size = 0;
    da->capacity = cap;
    da->data = (TYPE*) malloc(cap * sizeof(TYPE));
    assert(da->data != NULL); /* Check the status*/
}

void addDynArr(struct dyArr *da, TYPE val){
    /* Must assert ON EVERY FUNCTION */
    assert(da != NULL); /* No point checking val becasue it can be any value*/
    /* Step 1: 
        Make sure there is enough memory */
    if(da->size >= da->capacity){
        _doubleCapacity(da);
    }

    /* Step 2:
        if there is enough memory, add to the end */
    da->data[da->size] = val;
    da->size++; /* Increase the size */
}

void _doubleCapacity(struct dyArr *da){
    assert(da != NULL);
    /* Step 1: memorize old*/
    TYPE * oldData = da->data;
    int oldsize = da->size;

    /* Step 2: allocate new memory */
    initDynArr(da, 2 * da->capacity);
    /* After initDynArr, da->data points to a new memory location */
    /* Step 3: Copy from the old location */
    int j;
    for(j = 0;  j < oldsize; j++){
        da->data[j] = oldData[j];
    }
    da->size = oldsize;
    /* Step 4: free old memory */
    free(oldData);
}

void removeDynArr(struct dyArr *da, TYPE val){
    assert(da != NULL);
    int i;
    for(i = 0; i < da->size; i++){
        if(da->data[i] == val){
            da->data[i] = da->data[da->size - 1];
            da->size--;
        }
    }
}