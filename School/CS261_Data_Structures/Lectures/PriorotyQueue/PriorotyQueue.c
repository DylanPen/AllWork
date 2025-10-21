#define TYPE double

typedef struct Data{
    TYPE val;
    int pr;
    struct Data *data;
};

typedef struct DynArr{
    struct Data *data;
    int size;
    int cap;
    struct DynArr *dynarr;
};

void addHeap();
TYPE getHeap();
void removeHeap();
void adjustHeap(struct DynArr *heap, int start, int size);

void addHeap(struct DynArr *heap, struct Data e){
    assert(heap);
    if(heap->size == heap->cap){
        _doubleCapacity(heap, 2*heap->cap);
    }
    int i = heap->size;
    int p = (i-1)/2;
    while(p >= 0 && e.pr < heap->data[p].pr){
        heap->data
    }
    heap->data[i] = e;
    heap->size++;
}

void removeHeap(struct DynArr *heap){
    assert(heap);
    if(heap->size){
        heap->data[0] = heap->data[heap->size-1];
        heap->size--;
    }
    adjustHeap(heap, 0, heap->size);

}

void adjustHeap(struct DynArr *heap, int start, int end){
    int c1 = start * 2 + 1;
    int c2 = start * 2 + 2;
    if(c2 < end){
        int c = _higherPriorotyIdx(heap, c1, c2);
        if(heap->data[c].pr < heap->data[start].pr){
            swap(heap, start, c);
            adjustHeap(heap, c, end);
        }
    }
    else if(c1 < end){

    }
    return;
}