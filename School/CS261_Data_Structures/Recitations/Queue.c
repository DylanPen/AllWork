/* TO COMPILE, USE THESE GCC OPTIONS:  
   gcc -Wall -ansi -o prog Queue.c 

   TO RUN, ENTER SIZE OF QUEUE IN THE COMMAND LINE 
   FOR EXAMPLE: 
   ./prog 10 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TYPE int

struct DLink {
   TYPE value;
   struct DLink *next;
   struct DLink *prev;
};

struct DList {
   int size;
   struct DLink *front;
   struct DLink *back;
};

void initDList (struct DList *dl);
void printDList(struct DList *dl);
void addQueue (struct DList *q, TYPE val);
void addDLink (struct DList *dl, struct DLink *lnk, TYPE val);
struct DList *flipQueue(struct DList *q);

/*----------------------------------------------*/
int main(int argc, char **argv)
{
   /* Allocate memory for a pointer to the queue */
   struct DList *q = (struct DList *) malloc(sizeof(struct DList)); 
   assert(q);

   int i;
   TYPE val;
   int  size = atoi(argv[1]); /* set the queue size in the command line */
   assert(size >= 0);

   initDList(q); /*initialize Queue*/

  srand(time(NULL)); /*initialize random generator*/
   for(i=0; i<size; i++){
      val = (TYPE) rand() % 100;
      addQueue(q, val); /*add val to the queue*/
   }
   printf("Original Queue:");
   printDList(q); /*print the queue from Front to Back*/

   q = flipQueue(q); 

   printf("Flipped Queue:");
   printDList(q); /*print the queue from Front to Back*/

   return 0;
}


/*----------------------------------------------*/
/*Initialize Deque implemented as a doubly linked list*/
void initDList (struct DList *dl) {
   assert(dl);
   dl->front = (struct DLink *) malloc(sizeof(struct DLink));
   assert(dl->front != 0);
   dl->back = (struct DLink *) malloc(sizeof(struct DLink));
   assert(dl->back);
   dl->front->next = dl->back;
   dl->back->prev = dl->front;
   dl->size = 0;
}


/*----------------------------------------------*/
/*Print elements of a doubly linked list from front to back*/
void printDList(struct DList *dl){ 
   assert(dl);
   printf("\nFRONT: ");
   struct DLink *current = dl->front->next;   
   while (current != dl->back){  
      printf("%d ", current->value);
      current = current->next;
   }
   printf(" :BACK\n");
}


/*----------------------------------------------*/
/*Add val to a queue implemented as a doubly linked list*/
/*Input:
    q -- pointer to the queue
    val -- value to be added to the queue
*/
void addQueue (struct DList *q, TYPE val)
{ 
   assert(q);
   struct DLink *lnk = (struct DLink*)malloc(sizeof(struct DLink));    
   addDLink(q, lnk, val); 
}



/*----------------------------------------------*/
/*Add val before the specified link in a doubly linked list*/
/*Input arguments: 
    dl -- pointer to the doubly linked list
    lnk -- pointer to the link where to insert val
    val -- new value to be added 
*/      
void addDLink(struct DList *dl, struct DLink *lnk, TYPE val) 
{
   assert(dl && lnk);
   lnk->value = val;
   lnk->prev = dl->back->prev;
   dl->back->prev->next = lnk;
   lnk->next = dl->back;
   dl->back->prev = lnk;
   dl->size++;
   /* FIX ME */


}


/*----------------------------------------------*/
/*Flip elements of a queue in reverse order,
  where the queue is implemented as a doubly linked list.
  After return, no new memory is occupied.
  Input: q -- pointer to the queue.
  Output: pointer to the flipped queue.
*/
struct DList *flipQueue(struct DList *q) {  
   assert(q);
   int i;
   struct DLink *swapf = q->front->next;
   struct DLink *swapb = q->back->prev;
   for(i = 0; i < q->size/2; i++){
	   int temp = swapf->value;
	   swapf->value = swapb->value;
	   swapb->value = temp;
	   swapf = swapf->next;
	   swapb = swapb->prev;
   } 
   /*FIX ME*/
   return q;

}












