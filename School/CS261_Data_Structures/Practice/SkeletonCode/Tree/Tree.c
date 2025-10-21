/* TO COMPILE:  gcc -Wall -ansi tree.h Tree.c queue.h Queue.c -o prog */

/* TO RUN, ENTER: SIZE OF TREE1 AND SIZE OF TREE2 */
/* FOR EXAMPLE:  ./prog 10 20 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "tree.h"
#include "queue.h"


/*----------------------------------------------*/
int main(int argc, char **argv)
{
   if (argc < 3){ 
      printf("Specify the size of tree1 and size of tree2.\n");
      return 0;
   }
   if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0){ 
      printf("A tree size must be non-negative.\n");
      return 0;
   }
   int size1 = (int) atoi(argv[1]); 
   int size2 = (int) atoi(argv[2]); 
   
   
   /*-----------------------------------------*/
   /* TEST 1 */

   /* Initialize the BST1 and BST2 */
   BST *tree1 = (BST *) malloc(sizeof(BST));
   assert(tree1);
   initBST(tree1);
   BST *tree2 = (BST *) malloc(sizeof(BST));
   assert(tree2);
   initBST(tree2);

   /* Add random values to BST1 */
   srand(time(NULL)); /*initialize random generator*/
   NodeValType val;
   int i;
   for(i=0; i<size1; i++){
      val = (NodeValType) rand() % MAXVAL;
      addBST(tree1, val);
   }
   printf("BST1 contains %d nodes:\n", tree1->size);  
   printBFS(tree1);
   printf("\n");
   printf("\n");

   /* Add random values to BST2 */
   for(i=0; i<size2; i++){
      val = (NodeValType) rand() % MAXVAL;
      addBST(tree2, val);
   }
   printf("BST2 contains %d nodes:\n", tree2->size);
   printBFS(tree2);
   printf("\n");
   printf("\n");
  

   /*-----------------------------------------*/
   /* TEST 2 */
   NodeValType threshold = (NodeValType) rand() % MAXVAL;
   Node *node = containsThresholdBST(tree1, threshold);
   if (node)
      printf("In BST1, node %d is the highest less than %d.\n", node->val, threshold);
    else
       printf("In BST1, no node is less than %d.\n", threshold);


    removeThresholdBST(tree1, threshold);
    printf("BST1 after removing values less than %d:\n", threshold);
    printBFS(tree1);
    printf("\n");
    printf("\n");

    node = containsThresholdBST(tree2, threshold);
    if (node)
      printf("In BST2, node %d is the highest less than %d.\n", node->val, threshold);
    else
       printf("In BST2, no node is less than %d.\n", threshold);

    removeThresholdBST(tree2, threshold);
    printf("BST2 after removing values less than %d:\n", threshold);
    printBFS(tree2);
    printf("\n");
    printf("\n");


  /*-----------------------------------------*/
   /* TEST 3 */

    threshold = 2;
    pruneBST(tree1, threshold);
    printf("BST1 after pruning depths lower than %d:\n", threshold);
    printBFS(tree1);   
    printf("\n");
    printf("\n");
    
    threshold = 2; 
    pruneBST(tree2, threshold);
    printf("BST2 after pruning depths lower than %d:\n", threshold);
    printBFS(tree2);
    printf("\n");
    printf("\n");
    
    
   /*-----------------------------------------*/
   /* TEST 4 */
   printf("eq(tree1, tree2) = %d \n", eqBST(tree1, tree2));
   printf("eq(tree1, tree1) = %d \n", eqBST(tree1, tree1));
   printf("eq(tree2, tree2) = %d \n", eqBST(tree2, tree2));


   return 0;
}

/*----------------------------------------------*/
/* Print nodes of a BST in breadth-first order */
void printBFS(BST *tree){
   assert(tree);
   if(!tree->size) return;
   struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
   initQueue(q); 
   addQueue(q, *(tree->root)); 
   struct dLink *head = q->head->next; 
   while(head != q->tail){ 
        if (head->val.left)  addQueue(q, *(head->val.left));
        if (head->val.right) addQueue(q, *(head->val.right));
        printf("%d  ", head->val.val);
        removeQueue(q);
        head = q->head->next;
   }
   free(q->head); free(q->tail); free(q);
}



/*----------------------------------------------*/
/* Initialize a BST */
void initBST(BST *tree){
   assert(tree);
   tree->root = NULL;
   tree->size = 0;
   /* FIX ME */

}


/*----------------------------------------------*/
/* Adds a new value to a BST at the leaf level. 
Input: tree -- pointer to the BST
       val -- new value to be added to the BST
*/
void addBST(BST *tree, NodeValType val) {
  assert(tree);
  tree->root = addNode(tree->root, val);
  tree->size++;
   /* FIX ME */

}

Node *addNode(Node *node, NodeValType val){
    if(!node){
        Node *new = (Node*)malloc(sizeof(Node));
        assert(new);
        new->val = val;
        new->left = new->right = NULL;
    }
    else{
        if(LT(val, node->val)){
            node->left = addNode(node->left, val);
        }
        else{
            node->right = addNode(node->right, val);
        }
    }
    return node;
}


/*----------------------------------------------*/
/* Returns a pointer to the node with the highest value that is 
   still smaller than the specified threshold.
   Input:
      tree -- pointer to the BST
      threshold -- threshold 
*/
Node *containsThresholdBST(BST *tree, NodeValType threshold){
   assert(tree);
   
   /* FIX ME */
   

}



/*----------------------------------------------*/
/* Removes all nodes from a BST with values lower than the specified threshold.
   Input:
      tree -- pointer to the BST.
      threshold -- threshold.
*/
void removeThresholdBST(BST *tree, NodeValType threshold){
   assert(tree);

   /* FIX ME */

}

/*----------------------------------------------*/
/* Removes all nodes from a BST at depths lower than the specified threshold.
   Input:
      tree -- pointer to the BST.
      threshold -- depth threshold.
*/
void pruneBST(BST *tree, int threshold){
   assert(tree);
   
   /* FIX ME */
   
}

/*----------------------------------------------*/
/* Evaluate equivalence of two BSTs. Two BSTs are equivalent if their
   corresponding nodes and parent-child relationships are the same.
   Input: 
     tree1 -- pointer to BST1
     tree2 -- pointer to BST2
   Output:
     Return 1 if BST1 and BST2 are equivalent
     Return 0 if BST1 and BST2 are not equivalent
*/
int eqBST(BST *tree1, BST *tree2) { 
  assert(tree1 && tree2);

   /* FIX ME */

}