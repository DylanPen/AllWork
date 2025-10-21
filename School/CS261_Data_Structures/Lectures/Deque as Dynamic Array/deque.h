
struct Deque {
    TYPE *data;
    int capacity;
    int size;
    int front; /*front index*/
};

void initDeque(struct deque *d, int cap);

void addBackDeque(struct deque *d, TYPE val);

void addFrontDeque(struct deque *d, TYPE val);

/*
initDeque()
addFront(newElem)
addBack(newElem)
front() -- returns first front element
back() -- returns first back element
removeFront() -- removes first front element
removeBack() -- removes first back element
isEmpty()
*/