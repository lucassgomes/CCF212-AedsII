#include <stdio.h>
#include <stdlib.h>

#include "ADT/AdtBst.h"

int main() {
    int inputInformation, option, height;
    nodeType *rootPointer;
    initializeTree(&rootPointer);
    do {
        printf("SELECT OPTION:\n");
        printf("1 - Insert information\n2 - Search information\n3 - Number of nodes\n4 - Highest element\n5 - Height element\n0 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                exit(1);
            case 1:
                printf("Enter integer number: ");
                scanf("%d", &inputInformation);
                if (addInformation(&rootPointer, inputInformation)) printf("Success!\n");
                else printf("Error!\n");
                break;
            case 2:
                printf("Enter integer number for search: ");
                scanf("%d", &inputInformation);
                if (search(rootPointer, inputInformation)) printf("Success!\n");
                else printf("Not found!\n");
                break;
            case 3:
                printf("%d\n", numberNodesTree(rootPointer));
                break;
            case 4:
                printf("%d\n", highestInformation(rootPointer));
                break;
            case 5:
                printf("Enter integer number for search: ");
                scanf("%d", &inputInformation);
                height = heightInformation(rootPointer, inputInformation);
                if (!height) printf("Information in root node\n");
                else if (height == -1) printf("Not found!\n");
                else printf("Nodes: %d\n", height);
                break;
            default:
                printf("Invalid option!\n");
                system("PAUSE");
        }
    } while (option != 0);
    return 0;
}