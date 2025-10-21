#include "stack.h"

int main(){
    return 0;
}

void initStack(struct dyArr *stack, int cap){
    assert(stack != NULL && cap >= 0)
    /*IF PROVED USE: initDynArr(stack, cap);*/
    /*ELSE: */
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = cap;
    stack->data = (TYPE*)malloc(cap*sizeof(TYPE));
    assert(stack->data);
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

void _doubleCapacity(struct syArray *da){
    assert(da != NULL);
    /* Step 1: memorize old*/
    TYPE * oldData = da->data;
    int oldsize = da->size;

    /* Step 2: allocate new memory */
    initDynArr(da, 2 * da->capacity)
    /* After initDynArr, da->data points to a new memory location */
    /* Step 3: Copy from the old location */
    int i;
    for(i = 0; i < oldsize; i++){
        da->data[i] = oldData[i];
    }
    da->size = oldsize;
    /* Step 4: free old memory */
    free(oldData);
}