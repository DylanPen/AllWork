/* TO COMPILE, ENTER:  gcc -Wall -ansi -o prog yourONID.c */
/* TO RUN, ENTER PROGRAM ARGUMENTS: CAPACITY SIZE */
/* FOR EXAMPLE:  ./prog 10 4  */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TYPE int
#define EQ(a,b) (a == b) 
#define NUMBER 10 

struct Deque{
    TYPE *data; 
    int size; /* number of elements in data */
    int capacity; /* memory capacity of the deque */
    int front; /* index of the front of deque  */
};

void initStack(struct Deque *stack, int cap);
void pushStack(struct Deque *stack, TYPE val);
void printStack(struct Deque *stack);
void popStack(struct Deque *stack);
void popConsecStack(struct Deque *stack);
void _doubleCapacityStack(struct Deque *stack);


/*----------------------------------------------*/
int main(int argc, char **argv){
   struct Deque stack;
   int i;
   TYPE val;
   if (argc < 3){ 
      printf("In the command line, enter: capacity size\n");
      return 0;
   }

   int  capacity = atoi(argv[1]); /*read capacity from the command line*/
   int  size = atoi(argv[2]); /*read size from the command line*/
 
   srand(time(NULL)); /*initialize random generator*/

   initStack(&stack, capacity); /*initialize Stack*/
  
   /* Add elements to Stack */
   for(i=1; i<=size; i++){
      val = (TYPE) rand() % 100;
      pushStack(&stack, val); /*add val to Stack*/
   }

   printf("Stack:\n");
   printStack(&stack); /*print all elements*/

   popStack(&stack);/*remove the top element from Stack*/
   printf("Stack after pop:\n");
   printStack(&stack); /*print all elements*/


   val = (TYPE) rand() % 100;
   pushStack(&stack, val); /*add val to Stack*/
   printf("Stack after pushing %d:\n",val);
   printStack(&stack); /*print all elements*/

   popStack(&stack);/*remove the top element from Stack*/
   printf("Stack after pop:\n");
   printStack(&stack); /*print all elements*/


  /* Removing multiple elements from Stack */
   for(i=0; i<NUMBER; i++) popStack(&stack);
  
   printf("Stack after popping %d elements:\n", NUMBER);
   printStack(&stack); /*print all elements*/


   /* Push duplicate elements to Stack */
   while(stack.size) popStack(&stack);
   /* Add other elements to Stack */
   for(i=0; i<NUMBER; i++){
      val = (TYPE) rand() % 100;
      pushStack(&stack, val); /*push val to Stack*/
   }
   pushStack(&stack, val); /*push duplicate to Stack*/
   pushStack(&stack, val); /*push duplicate to Stack*/
   pushStack(&stack, val); /*push duplicate to Stack*/

   printf("New stack:\n");
   printStack(&stack); /*print all elements*/

   /* Removing consecutive duplicates of the top from Stack */
   popConsecStack(&stack);
  
   printf("Stack after removing consecutive duplicates of the top:\n");
   printStack(&stack); /*print all elements*/

   while(stack.size) popStack(&stack);
   /* Removing consecutive duplicates of the top from Stack */
   popConsecStack(&stack);
   printf("Empty stack:\n");
   printStack(&stack); /*print all elements*/


   return 0;
}


/*----------------------------------------------*/
/* Print out all elements of Stack starting from front */
void printStack(struct Deque *stack) {
   assert (stack);
   int i;

   printf("TOP: ");
   for(i=0; i< stack->size; i++)
      printf("%d ", stack->data[(stack->front + i) % stack->capacity]);
 
   printf(" :BOTTOM\n");
}

/*----------------------------------------------*/
/* Double the memory capacity of Stack */
void _doubleCapacityStack(struct Deque *stack) {
  assert (stack);
  int j;
  TYPE * oldData = stack->data; /*memorize old data*/
  int oldFront = stack->front; /*memorize old index of the front end of deque*/
  int oldSize = stack->size; /*memorize old size*/
  int oldCapacity = stack->capacity; /*memorize old capacity*/
  initStack(stack, 2 * oldCapacity); /*new memory allocation*/
  for (j = 0 ; j < oldSize; j++) {/*copy back old data*/
    stack->data[j] = oldData[oldFront++];
    if (oldFront >= oldCapacity) oldFront = 0;
  }
  free(oldData);
  stack->size = oldSize;
}

/*----------------------------------------------*/
/* Initialize Stack */
/* input arguments: 
    stack -- pointer to Stack
    cap -- capacity of memory to allocate to the stack 
*/
void initStack(struct Deque *stack, int cap) {
   assert (stack);
   stack->data = NULL;
   stack->size = 0;
   stack->capacity = cap;
   stack->front = 0;
   stack->data = (TYPE*)malloc(cap*sizeof(TYPE));
   assert(stack->data != NULL);

  /* FIX ME */

  
}

/*----------------------------------------------*/
/* Push a new element to Stack */
/* input arguments: 
    stack -- pointer to Stack
    val -- value of the data element to be added 
*/
void pushStack(struct Deque *stack, TYPE val) {  
   assert(stack);
   if(stack->size >= stack->capacity){
      _doubleCapacityStack(stack);
   }
   stack->front--;
   if(stack->front < 0){
      stack->front += stack->capacity;
   }
   stack->data[stack->front] = val;
   stack->size++;


  /* FIX ME */

}


/*----------------------------------------------*/
/* Pop the top element from Stack */
/* input: stack -- pointer to Stack */
void popStack(struct Deque *stack){ 
   assert(stack); 
   if(stack->size){
      stack->front++;
      if(stack->front >= stack->capacity){
         stack->front = 0;
      }
      stack->size--;
   }

  /* FIX ME */

}

/*----------------------------------------------*/
/* Pop consecutive duplicates of the top element from Stack */
/* input : stack -- pointer to Stack */
void popConsecStack(struct Deque *stack){ 
   assert(stack);
   TYPE val;
   if(stack->size){ 
      val = stack->data[stack->front];
      while( EQ(val, stack->data[stack->front])){
         popStack(stack);
      }
   }


  


  /* FIX ME */
 
}



