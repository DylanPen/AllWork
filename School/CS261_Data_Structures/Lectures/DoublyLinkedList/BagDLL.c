#define DLink (struct dLink)
#define DList (struct dList)

struct dLink{
    TYPE val;
    struct dLink *next;
    struct dList *prev;
};

struct dList{
    int size;
    DLink *front;
    DLink *back;
}

void initBag();
int isEmptyBag();
void addBag();
void removeBag();
void containsBag();
void addBeforeDLink(DList *dlst, DLink *lnk, TYPE val);
void removeDLink(DList *dlst, DLink *lnk);

void initBag(struct dList *bag){
    assert(bag);
    addBeforeDLink(bag, bag->front->next, val);
}

int containsBag(struct dList *bag, TYPE val){
    assert(bag);
    struct dLink *lnk = containsDList(bag,val);
    if(lnk) return 1;
    return 0;
}

struct dLink* containsDList(struct dList *bag, TYPE val){
    assert(bag);
    struct dLink *current = bag->front->next;
    while(current != bag->back){
        if(EQ(current->val, val)) return current;
        current = current->next; /*Itteration*/
    }
    return NULL;
}

void removeBag(struct dList *bag, TYPE val){

}

void removeAllBag(struct dList *bag, TYPE val){
    assert(bag);
    struct dLink *lnk = containsDList(bag, val);
}

/*Change these to fit bag*/
void addBeforeDLink(DList *dlst, DLink *lnk, TYPE val){
    assert(dlst && lnk);
    DLink *new = (DLink*)malloc(sizeof(DLink));
    assert(new != NULL);
    new->val = val;
    new->prev = lnk->prev;
    new->next = lnk;
    lnk->prev->next = new;
    lnk->prev = new;
    dlst->size++;
}

void removeDLink(DList *dlst, DLink *lnk){
    assert(dlst && lnk && (lnk != dlst->front) && (lnk != dlst->back));
    if(dlst->size){ /*check if empty*/
        lnk->prev->next = lnk->next;
        lnk->next->prev = lnk->prev;
        free(lnk);
        dlst->size--;
    }
}