#define TYPE double
#define  h(node) (node==NULL) ? -1 : node->height

typedef struct AVLNode{
    TYPE val;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode* _rotateLeft(struct AVLNode *current);
AVLNode* _rotateRight(struct AVLNode *current);

AVLNode* _rotateLeft(struct AVLNode *current){
    struct AVLNode *newtop = current->right;
    current->right = newtop->left;
    newtop->left = current;
    current->height = setHeight(current);
    newtop->height = setHeight(newtop);
    return newtop;
}  

int setHeight(struct AVLNode *node){
    return (1+max(h(node->left), h(node->right)));
}

AVLNode* _rotateRight(struct AVLNode *current){
    struct AVLNode *newtop = current->left;
    current->left = newtop->right;
    newtop->right = current;
    current->height = setHeight(current);
    newtop->height = setHeight(newtop);
    return newtop;
}

struct AVLNode *rotateFullRight(struct AVLNode *current){
    struct AVLNode *leftchild = current->left;
    if(h(leftchild->right) > h(leftchild->left)){
        leftchild = _rotateLeft(leftchild);
    }
    return _rotateRight(current);
}

struct AVLNode *rotateFullLeft(struct AVLNode *current){
    struct AVLNode *rightchild = current->right;
    if(h(rightchild->left) > h(rightchild->right)){
        rightchild = _rotateRight(rightchild);
    }
    return _rotateLeft(current);
}

AVLNode *balanceNode(AVLNode *current){
    int flag = h(current->right)-h(current->left);
    if(flag < -1){
        current = rotateFullRight(current);
    }
    else if(flag > 1){
        current = rotateFullLeft(current);
    }
    return current;
}

