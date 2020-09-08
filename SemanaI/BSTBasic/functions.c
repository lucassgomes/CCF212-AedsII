#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

/**
 * Initialize binary search tree with root node null
 * @param rootPointer
 */
void initializeTree(pointerType *rootPointer) {
    *rootPointer = NULL;
}

/**
 * Insert integer number in binary search tree based on root node
 * @param rootPointer
 * @param information
 * @return 1 - success | 0 - error
 */
int addInformation(pointerType *rootPointer, int information) {
    if (*rootPointer == NULL) {
        *rootPointer = (pointerType) malloc(sizeof(nodeType));
        (*rootPointer)->information = information;
        (*rootPointer)->left = NULL;
        (*rootPointer)->right = NULL;
        return 1;
    }
    if (information < (*rootPointer)->information) {
        return addInformation(&(*rootPointer)->left, information);
    }
    if (information > (*rootPointer)->information)
        return addInformation(&(*rootPointer)->right, information);
    else return 0;
}

/**
 * Displays binary search tree information based on root node and
 * the view type
 * @param rootPointer
 * @param type 1 - view in pre-order | 2 - view in post-order | 3 - view in order
 */
void order(pointerType rootPointer, int type) {
    if (rootPointer == NULL) return;
    switch (type) {
        case 1:
            printf("%d ", rootPointer->information);
            order(rootPointer->left, type);
            order(rootPointer->right, type);
            break;
        case 2:
            order(rootPointer->left, type);
            order(rootPointer->right, type);
            printf("%d ", rootPointer->information);
            break;
        default:
            order(rootPointer->left, type);
            printf("%d ", rootPointer->information);
            order(rootPointer->right, type);
    }
}


