#ifndef SBB_ADTSBB_H
#define SBB_ADTSBB_H
#define FALSE 0
#define TRUE 1

typedef enum {
    vertical, horizontal
} slope;
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int key;
    pointerType left, right;
    slope slopeLeft, slopeRight;
} nodeType;

void initializeTree(pointerType *node);
int insert(int key, pointerType *node);
int insertSloped(int key, pointerType *node, slope *nodeSlop, short *finish);
int leftLeft(pointerType *node);
int leftRight(pointerType *node);
int rightRight(pointerType *node);
int rightLeft(pointerType *node);
int search(pointerType nodePointer, int key);
void order(pointerType node);
void preOrder(pointerType node);
void postOrder(pointerType node);
#endif //SBB_ADTSBB_H
