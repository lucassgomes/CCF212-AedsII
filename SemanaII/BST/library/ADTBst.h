#include "ADTStudent.h"
#include "ADTList.h"

#ifndef BST_ADTBST_H
#define BST_ADTBST_H
typedef struct nodeType *pointerType;
typedef struct nodeType{
    adtStudent student;
    pointerType left, right;
} nodeType;
/**
 * Initialize binary search tree with root node null
 * @param rootPointer
 */
void initializeTree(pointerType *rootPointer);

/**
 * Insert student information in binary search tree based on root node
 * @param rootPointer
 * @param student
 * @return 1 - success | 0 - error
 */
int addInformation(pointerType *rootPointer, adtStudent student);

/**
 * Displays binary search tree information based on root node and
 * the view type descending order
 * @param rootPointer
 */
void descendingOrder(pointerType rootPointer);

int heightTree(pointerType rootPointer);

int numberStudents(pointerType rootPointer);

float highestScore(pointerType rootPointer);

float lowestScore(pointerType rootPointer);

void groupHighestScores(pointerType rootPointer, listType *list);

int studentsScoreAverage(pointerType rootPointer);
#endif //BST_ADTBST_H
