#define TYPE double

struct dyArr{
    TYPE *data;
    int size;
    int capacity;
}

/* Function Prototypes */

void initStack(struct dyArr *stack, int cap);

void freeStack(struct dyArr *stack);

void pushStack(struct dyArr *stack, TYPE d);

TYPE topStack(struct dyArr *stack);

void popStack(struct dyArr *stack);

int isEmptyStack(struct dyArr *stack);

/*Dynamic array prototypes*/

void initDynArr(struct dyArr *da, int cap);

void freeDynArr(struct dyArr *da);

void addDynArr(struct dyArr *da, TYPE val);

void removeDynArr(struct dyArr *da, TYPE val);

void _doubleCapacity(struct dyArr *da);