#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void initializeTree(pointerType *rootPointer) {
    *rootPointer = NULL;
}

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

void order(pointerType rootPointer) {
    if (rootPointer == NULL) return;
    order(rootPointer->left);
    printf("%d ", rootPointer->information);
    order(rootPointer->right);
}

void preOrder(pointerType rootPointer) {
    if (rootPointer == NULL) return;
    printf("%d ", rootPointer->information);
    order(rootPointer->left);
    order(rootPointer->right);
}

void postOrder(pointerType rootPointer) {
    if (rootPointer == NULL) return;
    order(rootPointer->left);
    order(rootPointer->right);
    printf("%d ", rootPointer->information);
}