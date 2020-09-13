#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ADTBst.h"

void initializeTree(pointerType *rootPointer) {
    *rootPointer = NULL;
}

int addInformation(pointerType *rootPointer, adtStudent student) {
    if (*rootPointer == NULL) {
        *rootPointer = (pointerType) malloc(sizeof(nodeType));
        (*rootPointer)->student = student;
        (*rootPointer)->left = NULL;
        (*rootPointer)->right = NULL;
        return 1;
    }
    if (student.score < (*rootPointer)->student.score) {
        return addInformation(&(*rootPointer)->left, student);
    }
    if (student.score > (*rootPointer)->student.score)
        return addInformation(&(*rootPointer)->right, student);
    else return 0;
}

void descendingOrder(pointerType rootPointer) {
    if (rootPointer == NULL) return;
    descendingOrder(rootPointer->right);
    printf("Student: %s\n", rootPointer->student.name);
    printf("Registration: %s\n", rootPointer->student.registration);
    printf("Group: %s\n", rootPointer->student.group);
    printf("Score: %.2f\n", rootPointer->student.score);
    descendingOrder(rootPointer->left);
}

int heightTree(pointerType rootPointer) {
    if (rootPointer == NULL) return -1;
    int heightLeft = heightTree(rootPointer->left);
    int heightRight = heightTree(rootPointer->right);
    if (heightLeft < heightRight) return heightRight++;
    else return heightLeft++;
}

int numberStudents(pointerType rootPointer) {
    if (rootPointer == NULL) return 0;
    int count = 1;
    count += numberStudents(rootPointer->left);
    count += numberStudents(rootPointer->right);
    return count;
}

float highestScore(pointerType rootPointer) {
    if (rootPointer == NULL) return 0;
    if (rootPointer->right != NULL) return highestScore(rootPointer->right);
    return rootPointer->student.score;
}

float lowestScore(pointerType rootPointer) {
    if (rootPointer == NULL) return 0;
    if (rootPointer->left != NULL) return lowestScore(rootPointer->left);
    return rootPointer->student.score;
}

void groupHighestScores(pointerType rootPointer, listType *list) {
    if (rootPointer == NULL) return;
    if (rootPointer->right == NULL) {
        insert(rootPointer->student, list);
        groupHighestScores(rootPointer->left, list);
        return;
    }
    groupHighestScores(rootPointer->right, list);
}

int studentsScoreAverage(pointerType rootPointer) {
    int count = 1;
    if (rootPointer == NULL || rootPointer->student.score < 6) return 0;
    count += studentsScoreAverage(rootPointer->left);
    count += studentsScoreAverage(rootPointer->right);
    return count;
}