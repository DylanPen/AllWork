#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "tree.h"
#include "queue.h"


/*----------------------------------------------*/
/*Initialize a queue implemented as a doubly linked list*/
void initQueue (struct Queue *q) {
   assert(q);
   q->head = (struct dLink *) malloc(sizeof(struct dLink));
   assert(q->head != 0);
   q->tail = (struct dLink *) malloc(sizeof(struct dLink));
   assert(q->tail);
   q->head->next = q->tail;
   q->tail->prev = q->head;
}


/*----------------------------------------------*/
/*Add val to a queue implemented as a doubly linked list*/
/*input:
    q -- pointer to Queue
    val -- value to be added to Queue
*/
void addQueue (struct Queue*q, LnkValType val){ 
   assert(q);

   /*add at the tail of the queue*/
   struct dLink * lnk = q->tail;

   /*allocate and assign value to a new link*/
   struct dLink * new = (struct dLink *) malloc(sizeof(struct dLink));
   assert(new != 0);
   new->val = val;

   /*connect the new link to queue*/
   new->prev = lnk->prev;
   new->next = lnk;
   lnk->prev->next = new;
   lnk->prev = new;
}

/*----------------------------------------------*/
/*Remove the head element from a queue implemented as a doubly linked list*/
/*input: q -- pointer to Queue */
void removeQueue(struct Queue *q){
   assert(q);
   /*remove from the head of the queue*/
   struct dLink *lnk = q->head->next;
   if(q->head->next != q->tail)
   {/* q is not empty*/
       q->head->next = lnk->next;
       lnk->next->prev = q->head;
       free(lnk);
  }
}