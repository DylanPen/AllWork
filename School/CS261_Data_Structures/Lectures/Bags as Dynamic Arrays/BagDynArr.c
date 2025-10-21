#include "BagDynArr.h"

int main(){
    return 0;
}

void initBag(struct Bag *b){
    assert(Bag != NULL);
    Bag->size = 0;
    Bag->capacity = 0;
}

int containsBag(struct dyArr *bag, TYPE val){
    assert(bag && bag->size > 0); /*Ckeck args*/
    int i = 0;
    while (i < bag->size){ /*search for val*/
        /*if yes, return*/
        if(EQ(val, bag->data[i])){
            return i; /*val found in bag*/
        }
        i++;
    }
    /*if no, return*/
    return -1; /*not found*/
}

void removeBag(struct dyArr *bag, TYPE val){
    assert(bag && bag->size > 0);
    /*Step 1: search for val*/
    int i = containsBag(bag, val);

    /*step 2: if found, then remove val*/
    if(i >= 0){
        bag->data[i] = bag->data[bag->size - 1];
        bag->size--;
    }
}

void removeAllBag(struct dyArr *bag, TYPE val){
    assert(bag && bag->size > 0);
    int i;
    while(i < bag->size){
        if(EQ(val, bag->data[i])){
            bag->data[i] = bag->data[da->size - 1];
            bag->size--;
        }
        else{
            i++;
        }
    }
}