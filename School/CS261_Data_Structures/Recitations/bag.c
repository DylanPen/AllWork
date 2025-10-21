/* TO COMPILE: gcc -Wall -ansi -o prog Bag.c */
/* TO RUN, SPECIFY THE PROGRAM ARGUMENTS: CAPACITY, SIZE */
/* FOR EXAMPLE: ./prog 10 4 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>

#define TYPE int
#define LT(a, b) (a<b)

struct DynArr {
	int size;
	int capacity;
	TYPE * data;
};
/*Interface for Dynamic Array*/
void initDynArr(struct DynArr * da, int capacity);
void addDynArr(struct DynArr * da, TYPE val);
void sortAscendBag(struct DynArr * da);
void _doubleCapacity (struct DynArr * da);
void _printDynArr(struct DynArr * da);

void _swap(TYPE *a, TYPE *b);


/* The main function */
int main(int argc, char **argv){
	struct DynArr bag;
	int i;
	TYPE val;
	int capacity = atoi(argv[1]);
	int size = atoi(argv[2]);
	initDynArr(&bag, capacity);

	/* Generate and add elements to bag */
	srand ( time(NULL) );
	for(i=0; i<size; i++){
		val = rand()%100;
		addDynArr(&bag, val);
	}
	sortAscendBag(&bag);
	printf("\nBag after sorting:\n");
	_printDynArr(&bag);
	return 0;
} /* end of the main function */

/* ADD ---------------------------------------------
input: da -- pointer to a dynamic array
val -- value to be added */
void addDynArr(struct DynArr * da, TYPE val) {
	assert(da);
	if (da->size == da->capacity) _doubleCapacity(da);
	da->data[da->size] = val;
	da->size ++;
}
/* DOUBLE CAPACITY ---------------------*/
void _doubleCapacity (struct DynArr * da) {
	int j;
	TYPE * oldData = da->data; /*memorize data*/
	int oldSize = da->size; /*memorize size*/
	/*new memory allocation*/
	initDynArr(da, 2 * da->capacity);
	for (j = 0 ; j < oldSize; j++)
	da->data[j] = oldData[j]; /*copy old data*/
	free(oldData);
	da->size = oldSize;
}
/* PRINT all elements of a dynamic array*/
void _printDynArr(struct DynArr * da) {
	assert (da);
	int i;
	for(i=0; i< da->size; i++)
	printf("%d \n", da->data[i]);
}
/* INITIALIZE a dynamic array
input: da -- pointer to a dynamic array
cap = capacity */
void initDynArr(struct DynArr * da, int cap)
{
	assert (da != NULL && cap >= 0);
	da->data = NULL;
	da->size = 0;
	da->capacity = cap;
	da->data = (TYPE *) malloc(cap * sizeof(TYPE));
	assert (da->data != NULL);

}
/* SORT -------------------------------*/
void sortAscendBag(struct DynArr* bag)
{
	assert(bag);
	int i,j;
	for(i = 0; i < bag->size-1; i++){
		for(j = i+1; j < bag->size; j++){
			if(LT(bag->data[j], bag->data[i])){
				_swap(bag->data+i, bag->data+j);
			}
		}
	}

}
void _swap(TYPE *a, TYPE *b){
	TYPE tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
