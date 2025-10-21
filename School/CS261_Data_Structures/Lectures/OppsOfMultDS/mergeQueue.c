#define TYPE (struct Customer)

struct Customer{
    int ID;
    int time;
};

struct Deque{
    TYPE *data;
    int size;
    int capacity;
    int front;
};

void initDeque(struct Deque *q, int cap);
void addBackDeque(struct Deque *q, int cus);
void mergeQ(struct Deque *q1, struct Deque *q2, struct Deque *q3);
void _doubleCapacityDeque(struct Deque *q)

void mergeQ(struct Deque *q1, struct Deque *q2, struct Deque *q3){
    assert(q1 && q2 && q3);
    int cap = q1->capacity;
    initDeque(q3, cap);

    int i = 0, j = 0;
    int qi, qj; /*actual queue index*/
    while (i < q1->size && j < q2->size){
        qi = (i + q1->front) % q1->capacity;
        qj = (j + q1->front) % q1->capacity;

        if(q1->data[qi].time < q2->data[qj].time){
            addBackDeque(q3, q1->data[qi]);
            i++;
        }
        else if(q1->data[qi].time > q2->data[qj].time){
            addBackDeque(q3, q2->data[qj]);
            j++;
        }
        else{
            addBackDeque(q3, q1->data[qi]); 
            i++;
            addBackDeque(q3, q2->data[qj]); 
            j++;
        }
    }
    while(i < q1->size){
        qi = (i + q1->front) % q1->capacity;
        addBackDeque(q3, q1->data[qi]);
        i++;
    }
    while(j < q2->size){
        qj = (j + q2->front) % q2->capacity;
        addBackDeque(q3, q2->data[qj]);
        j++;
    }
    free(q1->data);
    free(q2->data);
    q1->capacity = q1->size = q1->front = 0;
    q2->capacity = q2->size = q2->front = 0;

}