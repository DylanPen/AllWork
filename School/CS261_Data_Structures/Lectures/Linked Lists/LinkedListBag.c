#define TYPE double

struct Link{
    TYPE val; /*value of element*/
    struct Link *next; /*pointer to next link*/
};

struct List{
    struct Link *senitnel;
};

void initBag(struct List *b);
void addBag(struct List *b, TYPE val);
void removeBag(struct List *b, TYPE val);
void removeAllBag(struct List *b, TYPE val);


int main(){
    struct List *b;
    initBag(&b);
    addBag(&b, 3);
    addBag(&b, 8);
    addBag(&b, 5);

}

void initBag(struct List *b){
    assert(b);
    struct Link *senitnel = (struct Link *)malloc(sizeof(struct Link));
    sentinel->next = NULL;
    b->senitnel = senitnel;
}

void addBag(struct List *b, TYPE val){
    assert(b);
    /*allocate new link*/
    struct Link *new = (Link*)malloc(sizeof(Lnk));
    assert(new);
    new->val = val;
    /*link new element to top element*/
    new->next = b->senitnel->next;
    /*link sentinel to new top element*/
    b->senitnel->next = new;
}

void removeBag(struct List *b, TYPE val){
    assert(b);
    struct Link *previous = b->senitnel;
    struct Link *current - b->senitnel->next;
    while(current != NULL){
        if(EQ(current->val, val)){
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
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