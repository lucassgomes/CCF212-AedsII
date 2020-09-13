#ifndef BST_ADTLIST_H
#define BST_ADTLIST_H

#include "ADTStudent.h"

typedef struct cellType *pointerTypeList;
typedef struct cellType {
    float score;
    float numberStudents;
    char group[10];
    pointerTypeList next;
} cellType;

typedef struct listType {
    pointerTypeList first, last;
} listType;

void initializeList(listType *list);
int empty(listType list);
void insert(adtStudent student, listType *list);
cellType highestScoreList(listType list);
#endif //BST_ADTLIST_H
