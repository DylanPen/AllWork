#define TYPE double

struct Deque{
    TYPE *data;
    int size;
    int capacity;
    int front;
};

struct Link{
    struct Deque *data;
    struct Link *next;
    struct Link *prev;
};

struct List{
    struct Link *front;
    struct Link *back;
};

void initDeque(struct Deque *d, int cap);
void addFrontDeque(struct Deque *d, TYPE val);
void addBackDeque(struct Deque *d, TYPE val);
void removeFrontDeque(struct Deque *d);
void removeBackDeque(struct Deque *d);
void sortDequeAscending(struct Deque *d);
int getTotal(struct Deque *d);
void _doubleCapacity(struct Deque *d);
void _swap(TYPE *a, TYPE *b);

void initList(struct List *list);
void addLinkFront(struct List *list, struct Deque *d);
void addLinkBack(struct List *list, struct Deque *d);
void removeFrontLink(struct List *list);
void removeBackLink(struct List *list);
void sortList(struct List *list);

void initDeque(struct Deque *d, int cap){
    assert(d && cap > 0);
    d->size = d->front = 0;
    d->capacity = cap;
    d->data = (TYPE*)malloc(cap * sizeof(TYPE));
    assert(d->data != NULL);
}

void addFrontDeque(struct Deque *d, TYPE val){
    assert(d);
    if(d->size >= d->capacity){
        _doubleCapacity(d);
    }
    d->front--;
    if(d->front < 0){
        d->front += d->capacity;
    }
    d->data[d->front] = val;
    d->size++;
}

void addBackDeque(struct Deque *d, TYPE val){
    assert(d);
    if(d->size >= d->capacity){
        _doubleCapacity(d);
    }
    int back = (d->front + d->size) % d->capacity;
    d->data[back] = val;
    d->size++;
}

void removeFrontDeque(struct Deque *d){
    assert(d);
    if(d->size){
        d->front = (d->front + 1) % d->capacity;
        d->size--;
    }
}

void removeBackDeque(struct Deque *d){
    assert(d);
    if(d->size){
        d->size--;
    }
}

void sortDequeAscending(struct Deque *d){
    assert(d);
    int i,j
    if(d->size >= 2){
        for(i = 0, i < d->size; i++){
            for(j = 0; j < d->size; j++){
                if(d->data[i] > d->data[j]){
                    _swap(d->data[i], d->data[j]);
                }
            }
        }
    }
}

int getTotal(struct Deque *d){
    assert(d);
    int i;
    int total = 0;
    for(i = 0; i < d->size; i++){
        total += d->data[i];
    }
    return total;
}

void _doubleCapacity(struct Deque *d){
    assert(d);
    TYPE oldData = d->data;
    int oldCapacity = d->capacity;
    int oldFront = d->front;
    int oldSize = d->size;
    initDeque(d, 2 * oldCapacity);
    d->size = oldSize;
    int i;
    for(i = 0; i < oldSize; i++){
        d->data[i] = oldData[i];
    }
    free(oldData);
}

void _swap(TYPE *a, TYPE *b){
    TYPE *temp = a;
    a = b;
    b = temp;
}

void initList(struct List *list){
    assert(list);
    link->front = (struct Link*)malloc(sizeof(struct Link*));
    assert(link->front);
    link->back = (struct Link*)malloc(sizeof(struct Link*));
    assert(link->back);
    link->front->next = link->back;
    link->back->prev = link->front;
}

void addLinkFront(struct List *list, struct Deque *d){
    assert(list && d);
    struct Link *new = (struct Link*)malloc(sizeof(struct Link));
    new->data = d;
    new->next = front->next
    front->next->prev = new;
    new->prev = front;
    front->next = new;
}

void addLinkBack(struct List *list, struct Deque *d){
    assert(list && d);
    struct Link *new = (struct Link*)malloc(sizeof(struct Link));
    new->data = d;
    new->prev = back->prev;
    back->prev->next = new;
    new->next = back;
    back->prev = new;
}

void removeFrontLink(struct List *list){
    assert(list);
    struct link *lnk = list->front->next;
    if(lnk){
        list->front->next = lnk->next;
        list->front->next->next->prev = lnk->prev;
    }
    free(lnk);
}

void removeBackLink(struct List *list){
    struct link *lnk = list->back->prev;
    if(lnk){
        list->back->prev = lnk->prev;
        list->back->prev->prev->next = lnk->next;
    }
    free(lnk);
}

void sortList(struct List *list){
    assert(list);
    struct Link *lnk = link->front;
    while(lnk->next->next != NULL){
        lnk = lnk->next;
        int a = getTotal(lnk->data);
        int b = getTotal(lnk->next->data);
        if(a > b){
            
        }
    }
}