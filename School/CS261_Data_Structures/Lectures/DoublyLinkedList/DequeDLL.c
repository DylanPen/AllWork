#define DLink (struct dLink)
#define DList (struct dList)


struct dLink{
    TYPE value;
    DLink *next;
    DLink *prev;
};

struct dList{
    int size; /*For fun, not needed*/
    DLink *front; /*Front Seninel*/
    DLink *back; /*Back Sentinel*/
}

/*Deque Interface*/
void initDeque(struct dList *dq);
int isEmptyDeque (struct dList *dq);
void addFrontDeque (struct dList *dq, TYPE val);
void addBackDeque (struct dList *dq, TYPE val);
void removeFrontDeque(struct dList *dq);
void removeBackDeque(struct dList *dq);
void addBeforeDLink(DList *dlst, DLink *lnk, TYPE val);
void removeDLink(DKist *dlst, DLink *lnk);

void initDeque(struct dList *dq){
    assert(dq);
      dq->front = (DLink*)malloc(sizeof(DLink));\
      assert(dq->front);

      dq->back = (DLink*)malloc(sizeof(DdLink));
      assert(dq->back);

      dq->front->next = dq->back;
      dq->back->prev = dq->front;
      dq->size = 0;
}

int isEmptyDeque (struct dList *dq){
    /*dq->front->next = dq->back and dq->back->prev = dq->front;*/
}

void addFrontDeque (struct dList *dq, TYPE val){
    assert(dq);
    addBeforeDLink(dq, dq->front->next, val);
}


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

void removeDLink(DKist *dlst, DLink *lnk){
    assert(dlst && lnk && (lnk != dlst->front) && (lnk != dlst->back));
    if(dlst->size){ /*check if empty*/
        lnk->prev->next = lnk->next;
        lnk->next->prev = lnk->prev;
        free(lnk);
        dlst->size--;
    }
}

void removeFrontDeque(struct dList *dq){
    assert(dq);
    if(dq->size){
        removeDLink(dq, dq->front->next);
    }
}

void removeBackDeque(struct dList *dq){
    assert(dq);
    if(dq->size){
        removeDLink(dq, dq->back->next);
    }
}

