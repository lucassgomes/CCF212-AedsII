#ifndef BSTREMOVE_FUNCTIONS_H
#define BSTREMOVE_FUNCTIONS_H
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int information;
    pointerType left, right;
} nodeType;

void initializeTree(pointerType *rootPointer);
int addInformation(pointerType *rootPointer, int information);
void order(pointerType rootPointer, int type);
void predecessor(pointerType removePointer, pointerType *leftChild);
int removeInformation(pointerType *rootPointer, int information);
#endif //BSTREMOVE_FUNCTIONS_H
