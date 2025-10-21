#include "tree.h"

# ifndef _Queue_
# define _Queue_


struct dLink {
   LnkValType val;
   struct dLink *next;
   struct dLink *prev;
};

struct Queue {
   struct dLink *head;
   struct dLink *tail;
};


/*----------------------------------------------*/
/*Interface of a queue implemented as a doubly linked list*/
void initQueue (struct Queue *q);
void addQueue (struct Queue *q, LnkValType val);
void removeQueue (struct Queue *q);

# endif