#define TYPE double

struct dyArr {
    TYPE * data; /* Pointer to data array */
    int size; /* Number of elements */
    int capacity; /* number of elements a dynamic array can hold */
};

void initDynArr(struct dyArr *da, int cap);

void freeDynArr(struct dyArr *da);

void addDynArr(struct dyArr *da, TYPE val);

void removeDynArr(struct dyArr *da, TYPE val);

void _doubleCapacity(struct dyArr *da); /* Underscore is the naming convention for functions that should be "hidden" from the user*/

void _printDynArr(struct dyArr *da);