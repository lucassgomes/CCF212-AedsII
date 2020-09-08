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

/**
 * Procedure to find the rightmost node of the child to the left of the node containing the searched key
 * @param removePointer node to be removed
 * @param leftChild child to the left of the node
 */
void predecessor(pointerType removePointer, pointerType *leftChild) {
    pointerType auxiliary;
    if((*leftChild)->right != NULL) {
        predecessor(removePointer, &(*leftChild)->right);
        return;
    }
    removePointer->information = (*leftChild)->information;
    auxiliary = *leftChild;
    *leftChild = (*leftChild)->left;
    free(auxiliary);
}

/**
 * Removes information from the root node of the binary search tree
 * @param rootPointer
 * @param information value to be fetched and removed
 * @return 1 - success | 0 - error/not found
 */
int removeInformation(pointerType *rootPointer, int information) {
    if (*rootPointer == NULL) {
        return 0;
    }
    if(information < (*rootPointer)->information) {
        return removeInformation(&(*rootPointer)->left, information);
    }
    if(information > (*rootPointer)->information) {
        return removeInformation(&(*rootPointer)->right, information);
    }
    if ((*rootPointer)->left != NULL && (*rootPointer)->right != NULL) {
        predecessor(*rootPointer, &(*rootPointer)->left);
    } else {
        pointerType auxiliary;
        if ((*rootPointer)->right == NULL) {
            auxiliary = *rootPointer;
            *rootPointer = (*rootPointer)->left;
        } else if ((*rootPointer)->left == NULL) {
            auxiliary = *rootPointer;
            *rootPointer = (*rootPointer)->right;
        } else {
            return 0;
        }
        free(auxiliary);
    }
    return 1;
}