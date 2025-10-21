#define TYPE double

struct Link{
    TYPE val; /*value of element*/
    struct Link *next; /*pointer to next link*/
};

struct List{
    struct Link *senitnel;
};

void initStack(struct List *stk);
void pushStack(struct List *stk, TYPE val);
void popStack(struct List *stk);

int main(){
    struct List *list;
}

void initStack(struct List *stk){
    assert(stk);
    struct Link *senitnel = (struct Link *)malloc(sizeof(struct Link));
    sentinel->next = NULL;
    stk->senitnel = senitnel;
}

void pushStack(struct List *stk, TYPE val){
    assert(stk);
    /*allocate new link*/
    struct Link *new = (struct Link*)malloc(sizeof(struct Link));
    assert(new);
    new->val = val;
    /*link new element to top element*/
    new->next = stk->senitnel->next;
    /*link sentinel to new top element*/
    stk->senitnel->next = new;
}

void popStack(struct List *stk){
    assert(stk);
    struct Link *lnk = stk->senitnel->next;
    if(lnk != NULL && lnk->next != NULL){
        stk->senitnel->next = lnk->next;
        free(lnk);
    }
}