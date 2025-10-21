#define KTYPE char*
#define VTYPE int

struct Map{
    struct Link **table; /*array of pointers (These are the sentinels of the linked lists)*/
    int size;
    int length;
};

struct Link{
    struct Link *next;
    struct Data e;
};

struct Data{
    KTYPE key;
    VTYPE val;
};

unsigned int hash(KTYPE key);
/*idx = hash(key) % length;*/
/*ensure 0 <= idx < length of the array*/

void initMap(struct Map *map, int length);
void addMap(struct Map *map, struct Data e);
int containsMap(struct Map *map, struct Data e);
void removeMap();

void initMap(struct Map *map, int length){
    assert(map && length >= 0);
    /*allocate memory for the table of pointers*/
    map->table = (struct Link **)malloc(length * sizeof(struct Link *));
    assert(map->table);
    map->size = 0;
    map->length = length;
    /*allocate memory for the sentinels*/
    int i;
    for(i = 0; i < map->length; i++){
        map->table[i] = (struct Link *)malloc(sizeof(struct Link));
        assert(map->table[i]);
        map->table[i]->next = NULL;
    }
}

void addMap(struct Map *map, struct Data e){
    assert(map);
    /*Step 1: compute the index of e in the table from the key (Hash)*/
    int idx = (int) abs(hash(e.key)) % map->length;
    /*Step 2: allocate memory for a new link that stores e*/
    struct Link *new = (struct Link*)malloc(sizeof(struct Link));
    assert(new);
    /*Step 3: Insert the new link in the table at the index*/
    new->next = map->table[idx]->next;
    map->table[idx]->next = new;
    /*Step 4: Increment the total number of elements*/
    map->size++;
    /*Step 5: Check if necessary to resize the table for efficiency*/
    double load = map->size / map->length;
    if(load > MAX_LOAD){
        _resizeTable(map);
    }

}

void _resizeTable(struct Map *map){
    assert(map);
    /*Step 1: copy old table*/
    int oldLength = map->length;
    struct Link **oldTable = map->table;
    /*Step 2: Allocate new memory*/
    initMap(map, 2*oldLength);
    /*Step 3: copy over old data to new map*/
    struct Link *current, *previous;
    int i;
    for(i = 0; i < oldLength; i++){
        current = oldTable[i]->next;
        while(current != NULL){
            addMap(map, current->e);
            previous = current;
            current = current->next;
            free(previous);
        }
    }
    free(oldTable);
}

int containsMap(struct Map *map, struct Data e){
    assert(map);
    int idx = (int)abs(hash(e.key)) % map->length;
    struct Link *current = map->table[idx]->next;
    while(current != NULL){
        if(EQ(current->e.key, e.key)){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void removeMap(struct Map *map, struct Data e){
    assert(map);
    int idx = (int)abs(hash(e.key)) % map->length;
    struct Link *current, *previous;
    previous = map->table[idx];
    current = previous->next;
    while(current != NULL){
        if(EQ(current->e.key == e.key)){
            previous->next = current->next;
            free(current);
            map->size--;
            return;
        }
        else{
            previous = current;
            current = current->next;
        }
    }
    
}