#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
    int inputInformation, option, optionView;
    nodeType *rootNode;
    initializeTree(&rootNode);
    do {
        printf("SELECT OPTION:\n");
        printf("1 - Insert information\n2 - View information\n3 - Remove information\n0 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                exit(1);
            case 1:
                printf("Enter integer number: ");
                scanf("%d", &inputInformation);
                if (addInformation(&rootNode, inputInformation)) printf("Success!\n");
                else printf("Error!\n");
                break;
            case 2:
                printf("SELECT OPTION FOR VIEW INFORMATION:\n");
                printf("1 - Pre-order\n2 - Post-order\n3 - In order\n");
                printf("Enter option: ");
                scanf("%d", &optionView);
                if (optionView == 1 || optionView == 2 || optionView == 3) {
                    order(rootNode, optionView);
                    printf("\n");
                } else {
                    printf("Invalid option!\n");
                    system("PAUSE");
                }
                break;
            case 3:
                printf("Enter integer number: ");
                scanf("%d", &inputInformation);
                if (removeInformation(&rootNode, inputInformation)) printf("Success!\n");
                else printf("Not found!\n");
                break;
            default:
                printf("Invalid option!\n");
                system("PAUSE");
        }
    } while (optionView != 0 || option != 0);
}