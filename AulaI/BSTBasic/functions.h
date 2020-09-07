#ifndef BSTBASIC_FUNCTIONS_H
#define BSTBASIC_FUNCTIONS_H
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int information;
    pointerType left, right;
} nodeType;

void initializeTree(pointerType *rootPointer);
int addInformation(pointerType *rootPointer, int information);
void order(pointerType rootPointer, int type);
#endif //BSTBASIC_FUNCTIONS_H
