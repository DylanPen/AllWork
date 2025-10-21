# ifndef _Tree_
# define _Tree_

#define MAXVAL 10
#define NodeValType int
#define LnkValType Node
#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define GE(a,b) (a>=b)


typedef struct Node { 
   NodeValType val; 
   struct Node *left; 
   struct Node *right; 
} Node;

typedef struct BST{
   Node *root; 
   int size;
} BST;

/*----------------------------------------------*/
/*Interface of a Binary Search Tree*/
void initBST(BST *tree);
void addBST(BST *tree, NodeValType val);
void printBFS(BST *tree);
int eqBST(BST *tree1, BST *tree2);
Node *containsThresholdBST(BST *tree, NodeValType threshold);
void removeThresholdBST(BST *tree, NodeValType threshold);
void pruneBST(BST *tree, int threshold);



# endif