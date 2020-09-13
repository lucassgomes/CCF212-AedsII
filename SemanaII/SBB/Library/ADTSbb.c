#include <stdlib.h>
#include <stdio.h>

#include "ADTSbb.h"

void initializeTree(pointerType *node) {
    *node = NULL;
}

int insert(int key, pointerType *node) {
    short finish;
    slope nodeSlop;
    return insertSloped(key, node, &nodeSlop, &finish);
}

int insertSloped(int key, pointerType *node, slope *nodeSlop, short *finish) {
    if (*node == NULL) {
        *node = (pointerType) malloc(sizeof(nodeType));
        *nodeSlop = horizontal;
        (*node)->key = key;
        (*node)->slopeLeft = vertical;
        (*node)->slopeRight = vertical;
        (*node)->left = NULL;
        (*node)->right = NULL;
        *finish = FALSE;
        return TRUE;
    }
    if (key < (*node)->key) {
        return insertSloped(key, &(*node)->left, &(*node)->slopeLeft, finish);
    }
    if (key > (*node)->key) {
        return insertSloped(key, &(*node)->right, &(*node)->slopeRight, finish);
    }
    if (*finish) return TRUE;
    if ((*node)->slopeLeft != horizontal || (*node)->slopeRight != horizontal) {
        *finish = TRUE;
        return TRUE;
    }
    *nodeSlop = horizontal;
    if ((*node)->left->slopeLeft == horizontal) {
        return leftLeft(node);
    } else if ((*node)->left->slopeRight == horizontal) {
        return leftRight(node);
    }
    if ((*node)->right->slopeRight == horizontal) {
        return rightRight(node);
    } else if ((*node)->right->slopeLeft == horizontal) {
        return rightLeft(node);
    }
    return FALSE;
}

int leftLeft(pointerType *node) {
    pointerType auxiliary;
    auxiliary = (*node)->left;
    (*node)->left = auxiliary->right;
    auxiliary->right = *node;
    auxiliary->slopeLeft = vertical;
    (*node)->slopeLeft = vertical;
    *node = auxiliary;
    return TRUE;
}

int leftRight(pointerType *node) {
    pointerType auxiliary1, auxiliary2;
    auxiliary1 = (*node)->left;
    auxiliary2 = auxiliary1->right;
    auxiliary1->slopeRight = vertical;
    (*node)->slopeLeft = vertical;
    auxiliary1->right = auxiliary2->left;
    auxiliary2->left = auxiliary1;
    (*node)->left = auxiliary2->right;
    auxiliary2->right = *node;
    *node = auxiliary2;
    return TRUE;
}

int rightRight(pointerType *node) {
    pointerType auxiliary;
    auxiliary = (*node)->right;
    (*node)->right = auxiliary->left;
    auxiliary->left = *node;
    auxiliary->slopeRight = vertical;
    (*node)->slopeRight = vertical;
    *node = auxiliary;
    return TRUE;
}

int rightLeft(pointerType *node) {
    pointerType auxiliary1, auxiliary2;
    auxiliary1 = (*node)->right;
    auxiliary2 = auxiliary1->left;
    auxiliary1->slopeLeft = vertical;
    (*node)->slopeRight = vertical;
    auxiliary1->left = auxiliary2->right;
    auxiliary2->right = auxiliary1;
    (*node)->right = auxiliary2->left;
    auxiliary2->left = *node;
    *node = auxiliary2;
    return TRUE;
}

int search(pointerType nodePointer, int key) {
    if (nodePointer == NULL) return 0;
    if (key < nodePointer->key) return search(nodePointer->left, key);
    if (key > nodePointer->key) return search(nodePointer->right, key);
    return 1;
}

void order(pointerType node) {
    if (node == NULL) return;
    order(node->left);
    printf("%d ", node->key);
    order(node->right);
}

void preOrder(pointerType node) {
    if (node == NULL) return;
    printf("%d ", node->key);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(pointerType node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->key);
}