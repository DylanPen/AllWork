#define TYPE double
#define MAX_SIZE 100

struct Bag {
    TYPE data[MAX_SIZE]; /* Static Array */
    int size;
};

void initBag(struct Bag *b);

void addBag(struct Bag *b);

int containsBag(struct Bag *b, TYPE val);

void removeBag(struct Bag *b, TYPE val); 

int sizeBag(struct Bag *b);