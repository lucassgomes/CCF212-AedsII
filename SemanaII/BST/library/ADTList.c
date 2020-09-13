#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADTList.h"

void initializeList(listType *list) {
    list->first = (pointerTypeList) malloc(sizeof(cellType));
    list->last = list->first;
    list->last->score = 0;
    list->last->numberStudents = 0;
    list->first->next = NULL;
}

int empty(listType list) {
    return (list.first == list.last);
}

void insert(adtStudent student, listType *list) {
    int exist = 0;
    pointerTypeList auxiliary;
    auxiliary = (*list).first->next;
    while (auxiliary != NULL) {
        if (strcmp(auxiliary->group, student.group) == 0) {
            exist = 1;
            printf("Group Student: %s\n", student.group);
            printf("Score Student: %.2f\n", student.score);
            auxiliary->numberStudents += 1;
            auxiliary->score += student.score;
            break;
        }
        auxiliary = auxiliary->next;
    }
    if (!exist) {
        list->last->next = (pointerTypeList) malloc(sizeof(cellType));
        list->last = list->last->next;
        list->last->score = student.score;
        list->last->numberStudents = 1;
        strcpy(list->last->group, student.group);
        list->last->next = NULL;
    }
}

cellType highestScoreList(listType list) {
    pointerTypeList auxiliary;
    cellType groupHighest;
    auxiliary = list.first->next;
    groupHighest = (*list.first->next);
    float avgHighest = (groupHighest.score / groupHighest.numberStudents);
    while (auxiliary != NULL) {
        float avg = auxiliary->score / auxiliary->numberStudents;
        printf("%.2f - %.2f\n", avgHighest, avg);
        if (avg > avgHighest) {
            groupHighest = (*auxiliary);
        }
        auxiliary = auxiliary->next;
    }
    return groupHighest;
}