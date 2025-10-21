/* TO COMPILE, ENTER:  gcc -Wall -ansi -o prog yourONID.c */

/* TO RUN, ENTER PROGRAM ARGUMENTS: CAPACITY SIZE  */
/* FOR EXAMPLE:  ./prog 10 5  */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>

#define TYPE int
#define LT(a, b) (a<b)
#define GT(a, b) (a>b)
#define EQ(a, b) (a == b)

struct DynArr {
   TYPE * data;
   int size;
   int capacity;
};

/*----------------------------------------------*/
/*Interface for Sorted Bag*/
void initBag(struct DynArr * bag, int capacity);
void addSortedBag(struct DynArr * bag, TYPE val);
void removeSortedBag(struct DynArr * bag, TYPE val);

/*----------------------------------------------*/
/*Auxiliary functions*/
void _increaseCapacity (struct DynArr * bag);
void _printBag(struct DynArr * bag);

/*----------------------------------------------*/
int main(int argc, char **argv){
   struct DynArr bag;
   int i;
   TYPE val;

   if (argc < 3){ 
      printf("In the command line, enter: capacity size\n");
      return 0;
   }

   int  capacity = atoi(argv[1]); /*read capacity from the command line*/
   int  size = atoi(argv[2]); /*read size from the command line*/

   assert((capacity > 0) && (size >= 0));  

   initBag(&bag, capacity);


   /*Add random numbers to the sorted bag while maintaining ascending order*/
   srand ( time(NULL) );
   for(i=0; i<size; i++) addSortedBag(&bag, rand()%101);

   printf("Sorted bag after adding %d elements:\n", size);
   _printBag(&bag);

   addSortedBag(&bag, 200);

   printf("Sorted bag after adding %d:\n", 200);
   _printBag(&bag);

   addSortedBag(&bag, -1);

   printf("Sorted bag after adding %d:\n", -1);
   _printBag(&bag);

   val = rand()%101;
   addSortedBag(&bag, val);

   printf("Sorted bag after adding %d:\n", val);
   _printBag(&bag);

   val = bag.data[0];
   removeSortedBag(&bag, val);

   printf("Sorted bag after removing %d:\n", val);
   _printBag(&bag);

   val = bag.data[bag.size-1];
   removeSortedBag(&bag, val);

   printf("Sorted bag after removing %d:\n", val);
   _printBag(&bag);

   val = bag.data[rand()%bag.size];
   removeSortedBag(&bag, val);
   printf("Sorted bag after removing %d:\n", val);
   _printBag(&bag);

   removeSortedBag(&bag, 500);
   printf("Sorted bag after attempting to remove %d:\n", 500);
   _printBag(&bag);

   return 0;
}

/*----------------------------------------------*/
/* Prints all elements of a bag */
/*  Input: bag -- pointer to a bag */
void _printBag(struct DynArr * bag) {
   assert (bag);
   int i;
   if(bag->size == 0) printf("Bag is empty!");
   for(i=0; i< bag->size; i++) printf("%d, ", bag->data[i]);
   printf("\n");
}

/*----------------------------------------------*/
/* Increases capacity of memory allocated to a bag */
/*  Input: bag -- pointer to a bag */
void _increaseCapacity (struct DynArr * bag) {
  assert (bag);
  int j;
  TYPE * olddata = bag->data; /*memorize old data*/
  int oldSize = bag->size; /*memorize old size*/
  initBag(bag, 2 * bag->capacity); /*new memory allocation*/
  for (j = 0; j<oldSize; j++) bag->data[j] = olddata[j]; /*copy old data*/
  free(olddata);
  bag->size = oldSize;
}

/*----------------------------------------------*/
/* Initializes a bag 
   Input arguments:
      bag -- pointer to a bag implemented as a dynamic array 
      cap -- capacity of the memory block for allocation
*/
void initBag(struct DynArr * bag, int cap) {
   assert (bag!=0 && cap>0);
   bag->size = 0;
   bag->capacity = cap;
   bag->data = (TYPE*)malloc(cap*sizeof(TYPE));
   assert(bag->data != NULL);



}


/*----------------------------------------------*/
/* Adds a new element to the sorted bag, while maintaining 
   the ascending order of all elements in the bag.
   Input arguments:
      bag -- pointer to a bag implemented as a dynamic array 
      val -- value to be added
   After returning from the function the bag must remain
   sorted in the ascending order.
*/
void addSortedBag(struct DynArr * bag, TYPE val) {
   assert(bag);
   if(bag->size >= bag->capacity){
      _increaseCapacity(bag);
   }
   int i;
   for(i = bag->size-1; i >= 0 && bag->data[i] > val; i--){
      bag->data[i+1] = bag->data[i];
   }
   bag->data[i+1] = val;
   bag->size++;
  /* FIX ME */

}

/*----------------------------------------------*/
/* Removes a single instance of a given element from
   the sorted bag, while maintaining the ascending order 
   of all elements in the bag.
   Input arguments:
     bag -- pointer to a bag implemented as a dynamic array
     val -- value to be removed
   After returning from the function the bag must remain
   sorted in the ascending order.
*/
void removeSortedBag(struct DynArr * bag, TYPE val) {
   assert(bag);
   int i = 0;
   while(bag->data[i] != val){
      i++;
      if(i > bag->size-1){
         return;
      }
   }
   for(i = i; i < bag->size - 1; i++){
      bag->data[i] = bag->data[i+1];
   }
   bag->size--;



  /* FIX ME */

}

