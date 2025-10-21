struct DynArr *bagToSet(struct DynArr *bag){
    assert(bag);
    struct DynArr set;
    initDynArr(&set, bag->capacity);
    int i = 0;
    while(bag->size){
        set.data[i++] = bag->data[0];
        removeAllBag(bag, bag->data[0]);
    }
    bag->size = i;
    for(i = 0; i < bag->size; i++){
        bag->data[i] = set.data[i];
    }
    return bag;
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