#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "utility.h"

int main() {
    struct NODE * head = NULL;
    int input;
    while (1) {
        system("clear");
        printf("\n");
        printf("1. To Enter New Record\n");
        printf("2. To View All Records\n");
        printf("3. To View Single Record\n");
        printf("4. To Delete A Record\n");
        printf("5. To update a Record\n");
        printf("6. Any number key to exit the program\n");
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
            system("clear");
            head = insertNode(head);
            break;
        case 2:
            system("clear");
            viewList(head);
            break;
        case 3:
            system("clear");
            viewSingle(head);
            break;
        case 4:
            system("clear");
            deleteStudent(head);
            break;
        case 5:
            system("clear");
            updateRecord(head);
            break;
        default:
            return 0;
        }
    }
    return 0;
}