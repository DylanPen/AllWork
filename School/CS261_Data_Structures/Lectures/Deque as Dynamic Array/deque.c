#include "deque.h"


int main(){
    struct Deque d;
    int i; /*relative index*/
    int di; /*deque index*/
    return 0;
}



void initDeque(struct Deque *d, int cap){
    assert(d && cap > 0);
    d->size = d->front = 0;
    d->capacity = cap;

    d->data = (TYPE*) malloc(cap * sizeof(TYPE));
    assert(d->data);
}

void addBackDeque(struct Deque *d, TYPE val){
    assert(d);
    int back;
    if(d->size == d->capacity){
        _doubleCapDeque(d);
    }
    back = (d->front + d->size) % d->capacity;
    d->data[back] = val;
    d->size++;
}

void addFrontDeque(struct Deque *d, TYPE val){
    assert(d);
    if (d->size >= d->capacity){
        _doubleCapDeque(d);
    }
    d->front--;
    if(d->front < 0){
        d->front += d->capacity;
    }
    d->data[d->front] = val;
    d->size++;
}

void removeFrontDeque(struct Deque *d){
    assert(d && d->size > 0);
    /*FINISH THIS*/
    d->front = (d->front + 1) % d->capacity;
    d->size--;
}

void removeBackDeque(struct Deque *d){
    assert(d && d->size > 0);
    d->size--;

}

void _doubleCapDeque(struct Deque *d){
    assert(d != NULL);
    /*STEP 1: SAVE THE OLD DEQUE*/
    TYPE *oldData = d->data; /*save old data*/
    int oldFront = d->front; /*save old front*/
    int oldSize = d->size; /*save old size*/
    int oldCap = d->capacity; /*save old capacity*/
    /*STEP 2: ALLOCATE NEW MEMORY TO DEQUE*/
    initDeque(d, 2*oldCap);
    /*STEP 3: COPY THE OLD DEQUE TO NEW MEMORY*/
    d->size = oldSize;
    int j;
    for(j = 0; j < oldSize; j++){
        d->data[j] = oldData[(oldFront++) % oldCap];
    }
    /*STEP 4: FREE THE OLD DEQUE*/
    free(oldData);
}