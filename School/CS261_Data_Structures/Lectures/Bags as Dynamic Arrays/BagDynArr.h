#define TYPE double
#define MAX_SIZE 100

struct dyArr {
    TYPE *data;
    int side;
    int capacity;
};

struct Bag{
    TYPE *data[MAX_SIZE];
    int size;
}

void initBag(struct Bag *b);

void addBag(struct Bag *b);

int containsBag(struct Bag *b, TYPE val);

void removeBag(struct Bag *b, TYPE val); 

void removeAllBag(struct dyArr *bag, TYPE val);

void _doubleCapacity(struct dyArr *bag);