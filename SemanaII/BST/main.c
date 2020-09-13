#include <stdio.h>
#include <stdlib.h>

#include "library/ADTBst.h"

int main() {
    int option, height, avg;
    float highest, lowest;
    cellType groupHighest;
    adtStudent student;
    nodeType *rootBST;
    listType list;
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        system("PAUSE");
        exit(1);
    }
    initializeTree(&rootBST);
    while (fscanf(file, " %29[^-] - %9[^-] - %9[^-] - %f[^\n]", student.name, student.registration, student.group,
                  &student.score) == 4) {
        if (addInformation(&rootBST, student)) {
            printf("Student successfully inserted with the values:\n");
            printf("Name: %s\n", student.name);
            printf("Registration: %s\n", student.registration);
            printf("Group: %s\n", student.group);
            printf("Score: %.2f\n", student.score);
        } else {
            printf("Error!\n");
            system("PAUSE");
            exit(1);
        }
    }
    do {
        printf("SELECT OPTION:\n");
        printf("1 - View in descending order\n2 - Number of students\n3 - Highest and lowest scores\n");
        printf("4 - Group with higher scores\n5 - Number of students with average\n0 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                exit(1);
            case 1:
                descendingOrder(rootBST);
                printf("\n");
                break;
            case 2:
                height = numberStudents(rootBST);
                if (!height) printf("Empty!\n");
                printf("Number of students: %d\n", height);
                break;
            case 3:
                highest = highestScore(rootBST);
                lowest = lowestScore(rootBST);
                if (!highest || !lowest) printf("Empty!");
                printf("Highest score: %.2f\nLowest score: %.2f\n", highest, lowest);
                break;
            case 4:
                initializeList(&list);
                /**
                 * TODO: groupHighestScore function
                 */
//                if (empty(list)) {
//                    groupHighestScores(rootBST, &list);
//                    if (!empty(list)) {
//                        groupHighest = highestScoreList(list);
//                        printf("Group: %s\n", groupHighest.group);
//                        printf("AVG: %.2f\n", (groupHighest.score / groupHighest.numberStudents));
//                        printf("Total Score: %.2f\n", groupHighest.score);
//                        printf("Total Students: %.2f\n", groupHighest.numberStudents);
//                    }
//                } else {
//                    printf("Error!\n");
//                    system("PAUSE");
//                }
                break;
            case 5:
                avg = studentsScoreAverage(rootBST);
                if (!avg) printf("Empty!\n");
                printf("Number of students with average: %d\n", avg);
                break;
            default:
                printf("Invalid option!\n");
                system("PAUSE");
        }
    } while (option != 0);
    return 0;
}