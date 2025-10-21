
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct Customer {
    int ID;
    int time;
};

struct Deque {
    struct Customer *data;
    int size;
    int capacity;
    int front;
};

void initDeque(struct Deque *q, int cap);
void addBackDeque(struct Deque *q, struct Customer val);
void mergeQ(struct Deque *q1, struct Deque *q2, struct Deque *q3);
void _doubleCapacityDeque(struct Deque *q);
void printDeque(struct Deque *q);

int main() {
    struct Deque q1, q2, q3;
    int capacity = 5;

    // Initialize Deques
    initDeque(&q1, capacity);
    initDeque(&q2, capacity);

    // Test adding elements to q1 and q2
    printf("Adding customers to q1 and q2:\n");
    for (int i = 0; i < 3; i++) {
        struct Customer c1 = {i + 1, (i + 1) * 10};
        struct Customer c2 = {i + 4, (i + 1) * 15};
        addBackDeque(&q1, c1);
        addBackDeque(&q2, c2);
    }

    printf("Queue 1: ");
    printDeque(&q1);
    printf("Queue 2: ");
    printDeque(&q2);

    // Merge q1 and q2 into q3
    printf("Merging queues:\n");
    mergeQ(&q1, &q2, &q3);
    printf("Merged Queue: ");
    printDeque(&q3);

    // Test adding more customers and doubling capacity
    printf("Adding more customers to q3:\n");
    for (int i = 0; i < 6; i++) {
        struct Customer c = {i + 7, (i + 1) * 5};
        addBackDeque(&q3, c);
    }
    printf("Expanded Merged Queue: ");
    printDeque(&q3);

    free(q1.data);
    free(q2.data);
    free(q3.data);
    return 0;
}

void initDeque(struct Deque *q, int cap){
    assert(q && cap > 0);
    q->size = q->front = 0;
    q->capacity = cap;
    q->data = (struct Customer*)malloc(cap*sizeof(struct Customer));
    assert(q->data != NULL);
}

void _doubleCapacityDeque(struct Deque *q){
    assert(q);
    struct Customer* oldData = q->data;
    int oldFront = q->front;
    int oldSize = q->size;
    int oldCap = q->capacity;
    initDeque(d, 2*oldCap);
    q->size = oldSize;
    int i;
    for(i = 0; i < oldSize; i++){
        q->data[i] = oldData[(oldFront++) % oldCap];
    }
    free(oldData); 
}

void addBackDeque(struct Deque *q, struct Customer val){
    assert(q);
    if(q->size >= q->capacity){
        _doubleCapacityDeque(q);
    }
    int back = (q->front + q->size) % q->capacity;
    q->data[back] = val;
    q->size++;
}

void mergeQ(struct Deque *q1, struct Deque *q2, struct Deque *q3){
    assert(q1, q2, q3);
    initDeque(q3, q1->capacity);
    int i = 0, j = 0;
    int qi, qj;
    while(i < q1->size && j < q2->size){
        qi = (i + q1->front) % q1->capacity;
        qj = (j + q2->front) % q2->capacity;

        if(q1->data[qi].time > q2->data[qj].time){
            addBackDeque(q3, q1->data[qi]);
            i++;
        }
        else if(q1->data[qi].time < q2->data[qj].time){
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
    q1->size = q1->front = q1->capacity = 0;
    q2->size = q2->front = q2->capacity = 0;
    free(q1->data);
    free(q1->data);
}

void printDeque(struct Deque *q) {
    assert(q);
    if (q->size == 0) {
        printf("[empty]\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("(ID: %d, Time: %d) ", q->data[idx].ID, q->data[idx].time);
    }
    printf("\n");
}