#include <stdio.h>
#include <stdlib.h>

#include "AdtBst.h"

void initializeTree(pointerType *nodePointer) {
    *nodePointer = NULL;
}

int addInformation(pointerType *nodePointer, int information) {
    if (*nodePointer == NULL) {
        *nodePointer = (pointerType) malloc(sizeof(nodeType));
        (*nodePointer)->information = information;
        (*nodePointer)->left = NULL;
        (*nodePointer)->right = NULL;
        return 1;
    }
    if (information < (*nodePointer)->information) {
        return addInformation(&(*nodePointer)->left, information);
    }
    if (information > (*nodePointer)->information) {
        return addInformation(&(*nodePointer)->right, information);
    }
    return 0;
}

int search(pointerType nodePointer, int information) {
    if (nodePointer == NULL) return 0;
    if (information < nodePointer->information) return search(nodePointer->left, information);
    if (information > nodePointer->information) return search(nodePointer->right, information);
    return 1;
}

int numberNodesTree(pointerType nodePointer) {
    if (nodePointer == NULL) return 0;
    int count = 1;
    count += numberNodesTree(nodePointer->left);
    count += numberNodesTree(nodePointer->right);
    return count;
}

int highestInformation(pointerType nodePointer) {
    if (nodePointer == NULL) return 0;
    if (nodePointer->right != NULL) return highestInformation(nodePointer->right);
    return nodePointer->information;
}

int heightInformation(pointerType nodePointer, int information) {
    if (nodePointer == NULL) return -2;
    int count = 1;
    if (information < nodePointer->information) {
        return count += heightInformation(nodePointer->left, information);
    }
    if (information > nodePointer->information) {
        return count += heightInformation(nodePointer->right, information);
    }
    return count - 1;
}