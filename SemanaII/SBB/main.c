#include <stdio.h>
#include <stdlib.h>


#include "Library/ADTSbb.h"

int main() {
    int option, optionView, key;
    nodeType *rootNode;
    initializeTree(&rootNode);
    do {
        printf("SELECT OPTION:\n");
        printf("1 - Insert in SBB Tree\n2 - View order\n3 - Search key\n0 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                exit(1);
            case 1:
                printf("Enter integer number: ");
                scanf("%d", &key);
                if (insert(key, &rootNode))
                    printf("SUCCESS!\n");
                else printf("ERROR! \n");
                break;
            case 2:
                printf("SELECT OPTION FOR VIEW INFORMATION:\n");
                printf("1 - Pre-order\n2 - Post-order\n3 - In order\n0 - Exit\n");
                printf("Enter option: ");
                scanf("%d", &optionView);
                switch (optionView) {
                    case 0:
                        exit(1);
                    case 1:
                        preOrder(rootNode);
                        break;
                    case 2:
                        postOrder(rootNode);
                        break;
                    case 3:
                        order(rootNode);
                        break;
                    default:
                        printf("Invalid option!\n");
                        system("PAUSE");
                }
                printf("\n");
                break;
            case 3:
                printf("Enter integer number: ");
                scanf("%d", &key);
                if (search(rootNode, key))
                    printf("SUCCESS! KEY EXISTS\n");
                else printf("NOT FOUND!\n");
                break;
            default:
                printf("Invalid option!\n");
                system("PAUSE");
                break;
        }
    } while (option != 0);
    return 0;
}