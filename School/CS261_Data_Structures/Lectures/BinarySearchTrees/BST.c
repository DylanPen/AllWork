#define TYPE double
#define NODE struct Node
#define y(x) (x<0) ? -1 : (1+x)

struct Node{
    TYPE val;
    struct Node *left;
    struct Node *right;
};

struct BST{
    struct Node *root;
    int size;
};

void initBST(struct BST *tree);
int containsBST(struct BST *tree, TYPE val);
void addBST(struct BST *tree, TYPE val);
void removeBST(struct BST *tree, TYPE val);


/* STOPPING CRITERION FOR RECURSION
TYPE recursive_f(input1){
    if(stop){
        process_stop;
    }
    else{
        process(input1);
        recursive_f(input2);
    }
    return sone_result;
}
*/

void preorder(struct Node *node){
    if(node != NULL){
        process(node->val);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct Node *node){
    if(node != NULL){
        inorder(node->left);
        process(node->val);
        inorder(node->right);
    }
}

void initBST(struct BST *tree){
    assert(tree);
    tree->root = NULL;
    tree->size = 0;
}

int containsBST(struct BST *tree, TYPE val){
    assert(tree);
    if(tree->root){
        return containsNode(tree->root, val);
    }
    else{
        return 0;
    }
}

int containsNode(struct Node *node, TYPE val){
    if(!node) return 0;
    if(EQ(val, node->val)) return 1;
    else if(LT(val, node->val)) return containsNode(node->left, val);
    else return containsNode(node->right, val);
}

void addBST(struct BST *tree, TYPE val){
    assert(tree);
    tree->root = addNode(tree->root, val);
    tree->size++;
}

NODE *addNode(NODE *node, TYPE val){
    if(!node){/*stoppiing criterion*/
        /*insert new node*/
        NODE *new = (NODE*)malloc(sizeof(NODE));
        assert(new);
        new->val = val;
        new->left = new->right = NULL;
    }
    else{ /*recirsion left or right*/
        if(LT(val, node->val)){
            node->left = addNode(node->left, val);
        }
        else{
            node->right = addNode(node->right, val);
        }
    }
    return node;
}

TYPE _leftmostVal(struct Node *node){
    while(node->left != NULL){
        node = node->left;
    }
    return node->val;
}

struct Node *_removeLeftmost(struct Node *node){
    if(node->left != NULL){
        node->left = _removeLeftmost(node->left);
        return node;
    }
    struct Node *temp = node->right;
    free(node);
    return temp;
}

void removeBST(struct BST *tree, TYPE e){
    if(containsBST(tree, e)){
        tree->root = removeNode(tree->root, e);
        tree->size--;
    }
}

NODE *removeNode(NODE *node, TYPE e){
    if(EQ(e, node->val)){
        if(node->right == NULL){
            NODE *temp = node->left;
            free(node);
            return temp;
        }
        else{
            node->val = _leftmostVal(node->right);
            node->right = _removeLeftmost(node->right);
        }
    }
    else{
        if(LT(e, node->val)){
            node->left = removeNode(node->left, e);
        }
        else{
            node->right = removeNode(node->right, e);
        }
    }
}

int height(struct Node *node){
    if(node == 0){
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int depthValBST(struct BST *tree, TYPE val){
    assert(tree);
    if(tree->root){
        return depthNode(tree->root, val);
    }
    else{
        return -1;
    }
}

int depthNode(struct Node *node, TYPE val){
    if(!node) return -1;
    if(EQ(val, node->val)){
        return 0;
    }
    elseif(LT(val, node->val)){
        return y(depthNode(node->left, val));
    }
    else{
        return y(depthNode(node->right, val));
    }
}

int EQ(struct BST *tree1, struct BST *tree2){

}

void removeAllBST(struct BST *tree, TYPE e){
    assert(tree);
    while(containsBST(tree, e)){
        tree->root = removeNode(tree->root, e);
        tree->size--;
    }
}
/*another example*/
void removeAllBST(struct BST *tree, TYPE e){
    assert(tree);
    if(tree->root){
        tree->root = removeAllNode(tree->root, e, &(tree->size));
    }
}

struct Node *removeAllNode(struct Node *node, TYPE e, int *treesize){
    if(node == NULL) return NULL;

    while(node != NULL && EQ(e, node->val)){

    }
    /*...*/
    return node;
}

void lobut(struct BST *tree){
    int h = tree->height;
}

void printLevel(struct Node *node, int level){
    if(node == NULL) return;
    if(level > 0){
        printLevel(node->left, level-1);
        printLevel(node->right, level-1);
    }
    else if(level == 0){
        printf("%d", node->value);
    }
}