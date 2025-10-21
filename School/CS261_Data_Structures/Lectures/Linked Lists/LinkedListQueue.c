#define TYPE double

struct Link{
    TYPE val; /*value of element*/
    struct Link *next; /*pointer to next link*/
};

struct List{
    struct Link *head;
    struct Link *tail;
};

void initQueue(struct List *q);
void addQueue(struct List *q, TYPE val);
void removeBag(struct List *b, TYPE val);

int main(){
    struct List *q;

}

void initQueue(struct List *q){
    assert(q);
    struct Link *senitnel = (struct Link *)malloc(sizeof(struct Link));
    assert(senitnel);
    sentinel->next = NULL;
    q->head = senitnel;
    q->tail = senitnel;
}

void addQueue(struct List *q, TYPE val){
    assert(q);
    /*allocate new link*/
    struct Link *new = (Lnk*)malloc(sizeof(Lnk));
    assert(new);
    new->val = val;
    new->next = NULL;
    /*link new element to top element*/
    q->tail->next = new
    q->tail = new;
    /*link sentinel to new top element*/
}

void removeQueue(struct List *q, TYPE val){
    assert(q);
    struct Link *lnk = q->head->next; /*first link in queue*/
    if(lnk){
        q->head->next = lnk->next; /*disconnect*/
        if(q->head->next == NULL){
            q->tail = q->head;
        }
        free(lnk);
    }
}

void removeAllBag(struct List *b, TYPE val){
    assert(b);
    struct Link *previous = b->senitnel;
    struct Link *current - b->senitnel->next;
    while(current != NULL){
        if(EQ(current->val, val)){
            previous->next = current->next;
            free(current);
            return;
            current = previous;
        }
        previous = current;
        current = current->next;
    }
}