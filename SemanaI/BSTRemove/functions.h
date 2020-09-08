#ifndef BSTREMOVE_FUNCTIONS_H
#define BSTREMOVE_FUNCTIONS_H
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int information;
    pointerType left, right;
} nodeType;

/**
 * Initialize binary search tree with root node null
 * @param rootPointer
 */
void initializeTree(pointerType *rootPointer);

/**
 * Insert integer number in binary search tree based on root node
 * @param rootPointer
 * @param information
 * @return 1 - success | 0 - error
 */
int addInformation(pointerType *rootPointer, int information);

/**
 * Displays binary search tree information based on root node and
 * the view type pre-order
 * @param rootPointer
 */
void preOrder(pointerType rootPointer);

/**
 * Displays binary search tree information based on root node and
 * the view type post-order
 * @param rootPointer
 */
void postOrder(pointerType rootPointer);

/**
 * Displays binary search tree information based on root node and
 * the view type order
 * @param rootPointer
 */
void order(pointerType rootPointer);

/**
 * Procedure to find the rightmost node of the child to the left of the node containing the searched key
 * @param removePointer node to be removed
 * @param leftChild child to the left of the node
 */
void predecessor(pointerType removePointer, pointerType *leftChild);

/**
 * Removes information from the root node of the binary search tree
 * @param rootPointer
 * @param information value to be fetched and removed
 * @return 1 - success | 0 - error/not found
 */
int removeInformation(pointerType *rootPointer, int information);
#endif //BSTREMOVE_FUNCTIONS_H
