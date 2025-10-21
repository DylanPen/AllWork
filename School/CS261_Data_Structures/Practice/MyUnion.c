



struct Deque *Union(struct Deque *q1, struct Deque *q2){
    struct Deque *q3;
    initDeque(&q3, q1->capacity + q2->capacity);

    int i, j;
    for(i = 0; i < q1->size; i++){
        for(j = 0; j < q3->size; j++){
            if(q3->data[j] == q1->data[i]){
                break;
            } 
        }
        if (j == q3->size){
            addBackDeque(q3, q1->data[i]);
        }
    }

    for(i = 0; i < q2->size; i++){
        for(j = 0; j < q3->size; j++){
            if(q3->data[j] == q2->data[i]){
                break;
            } 
        }
        if (j == q3->size){
            q3->data[q3->size++] = q2->data[i];
        }
    }
    return q3;
}