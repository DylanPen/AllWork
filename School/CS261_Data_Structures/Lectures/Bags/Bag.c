#include "Bag.h"

int main(){
    struct Bag bag1;

    initBag(&bag2);
    addBag(&bag2, 5.3);
    return 0;
}

void initBag(struct Bag *b);{
    assert(b != NULL);
    b->size = 0;
}

void addBag(struct Bag *b, TYPE val){
    assert(b != NULL);
    if(b->size >= MAX_SIZE){
        return;
    }
    b->data[b->size] = val;
    b->size++;
}

/*remove one element from a bag*/
void removeBag (struct Bag * b, TYPE val){
    assert(b != NULL);
    int i = b->size-1;
    while (i >= 0){
        if (b->data[i] == val){
            b->data[i] = b->data[b->size - 1];
            b->size--;
            return;
        }
        i--;
    }
}
