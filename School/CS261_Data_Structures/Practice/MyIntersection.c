





struct Deque intersection(struct Deque *q1, struct Deque *q2, struct Deque *q3){
    int i, j;
    for(i = 0; i < q1->size; i++){
        if (i > 0 && q1->data[i - 1] == q1->data[i])
            continue;
        for(j = 0; j < q2->size; j++){
            if(q1->data[i] == q2->data[j]){
                addBackDeque(q3, q1->data[i]);
                break;
            }
        }
    }
}