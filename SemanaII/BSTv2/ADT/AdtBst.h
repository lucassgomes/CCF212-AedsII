#ifndef BSTV2_ADTBST_H
#define BSTV2_ADTBST_H
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int information;
    pointerType left, right;
} nodeType;

void initializeTree(pointerType *nodePointer);
int search(pointerType nodePointer, int information);
int addInformation(pointerType *nodePointer, int information);
int numberNodesTree(pointerType nodePointer);
int highestInformation(pointerType nodePointer);
int heightInformation(pointerType nodePointer, int information);
#endif //BSTV2_ADTBST_H