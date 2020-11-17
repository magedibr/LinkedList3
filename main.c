#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "information.h"


int main() {

    struct node *head = NULL;

    int i, go = 1, choice, val1, val2, val3, val4;

    float fval1;

    struct household h1;

    char filename[20];

    srand(time(NULL));

    printf("Adding 100 randomly generated records to the database");

    for(i = 0; i < 100; i++) {

        struct node *temp = randomNode();

        addRandom(&head);

    }

    while(go) {

        printf("\n\n***Population Info Menu***\n");

        printf("**************************\n");

        printf("1. Display records of a Region\n");

        printf("2. Display records of a Town\n");

        printf("3. Display records of a Race\n");

        printf("4. Display records of upto family size\n");

        printf("5. Display records of for family income less than x\n");

        printf("6. Display records of for family income greater than equal to x\n");

        printf("7. Display records of a Region-Town Pair\n");

        printf("8. Display records of a Region-Family size Pair\n");

        printf("9. Display records of a Region-Max Income Pair\n");

        printf("10. Add a new record\n");

        printf("11. Delete Records for Region, Town, and Race triplet\n");

        printf("12. Delete Records for Region, Town and Family size triplet\n");

        printf("13. Show all records\n");

        printf("14. Save database to file\n");

        printf("15. Load data from file\n");

        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch(choice) {

            case 1:

                val1 = getRegion();

                displayRegion(head,regions[val1]);

                break;

            case 2:

                val1 = getTown();

                displayTown(head,towns[val1]);

                break;

            case 3:

                val1 = getRace();

                displayRace(head,races[val1]);

                break;

            case 4:

                printf("Enter a family size to lookup (1-6) : ");

                scanf("%d",val1);

                displayFamilySize(head,val1);

                break;

            case 5:

                printf("Enter an upper bound on family income: ");

                scanf("%f",&fval1);

                displayBelowFamilyIncome(head,fval1);

                break;

            case 6:

                printf("Enter a lower bound on family income: ");

                scanf("%f",&fval1);

                displayAboveFamilyIncome(head,fval1);

                break;

            case 7:

                val1 = getRegion();

                val2 = getTown();

                displayRegionandTown(head,regions[val1],towns[val2]);

                break;

            case 8:

                val1 = getRegion();

                printf("Enter a family size to lookup (1-6) : ");

                scanf("%d",val2);

                displayRegionandFamilySize(head,regions[val1],val2);

                break;

            case 9:

                val1 = getRegion();

                printf("Enter an upper bound on family income: ");

                scanf("%f",&fval1);

                displayRegionandFamilyIncome(head,regions[val1],fval1);

                break;

            case 10:

                val1 = getRegion();

                h1.region = (char *)malloc(sizeof(char) * strlen(regions[val1]));

                strcpy(h1.region,regions[val1]);

                val2 = getTownInRegion(val1);

                h1.town = (char *)malloc(sizeof(char) * strlen(towns[val2]));

                strcpy(h1.town,towns[val2]);

                val3 = getRace();

                h1.race_of_head = (char *)malloc(sizeof(char) * strlen(races[val3]));

                strcpy(h1.race_of_head,races[val3]);

                printf("Enter family size : ");

                scanf("%d",&h1.h_Size);

                printf("Enter family income: ");

                scanf("%f",&h1.h_Size);

                add(&head,h1);

                printf("Record Successfully added\n");

                break;

            case 11:

                val1 = getRegion();

                val2 = getTown();

                val3 = getRace();

                deleteRTR(&head,regions[val1],towns[val2],races[val3]);

                printf("Records Deleted\n");

                break;

            case 12:

                val1 = getRegion();

                val2 = getTown();

                printf("Enter family size: ");

                scanf("%d",&val3);

                deleteRTF(&head,regions[val1],towns[val2],val3);

                printf("Records Deleted\n");

                break;

            case 13:

                displayAll(head);

                break;

            case 14:

                printf("Enter filename to write to : \n");

                scanf("%s",filename);

                writeToFile(&head,filename);

                printf("Data writtten to file successfully");

                break;

            case 15:

                head = NULL;

                printf("Enter filename to read from : \n");

                scanf("%s",filename);

                readFromFile(&head,filename);

                printf("Data loaded from file file successfully");

                break;

            case 16:

                go = 0;

                break;

            default:

                printf("\nInvalid Choice! Try again.");

        }

    }

}
