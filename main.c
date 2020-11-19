#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "information.h"


int main() {

    struct node *head = NULL;

    int i, go = 1, choice, val1, val2, val3, val4;

    float fval1;

    struct household userHouse;

    char filename[20];

    srand(time(NULL));

    printf("Adding 100 randomly generated records to the database");

    for(i = 0; i < MAX_VAL; i++) {

        struct node *temp = randomNode();

        addRandom(&head);

    }

    //turn into a func that accepts head as a parameter?
    while(go) {

        printf("\n\n***Population Info Menu***\n");

        printf("**************************\n");

        printf("1. Display households of a Region\n");

        printf("2. Display households of a Town\n");

        printf("3. Display households of a Race\n");

        printf("4. display households of a region with a given minimum number of people tested positive for Covid-19\n");

        printf("5. display the regions town-wise ranking of number of people tested positive for Covid-19\n");

        printf("6. add a record\n");

        printf("7. delete all records of a region, town and race triplet\n");

        printf("8. display updated data\n");

        printf("9. store data to a file\n");

        printf("10. display data from file\n");


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

                printf("Enter a min number of people tested \n");

                scanf(" %f",&fval1);

                displayTestedAboveThresh(head,fval1);

                break;

            case 5:

                getRank(head);
                break;

            case 6:
                userAdd(head,userHouse);
                break;

            case 7:

                val1 = getRegion();

                val2 = getTown();

                val3 = getRace();

                deleteRTR(&head,regions[val1],towns[val2],races[val3]);

                printf("Records Deleted\n");

                break;

            case 8:
                displayAll(head);

                break;

                val1 = getRegion();

                printf("Enter a family size to lookup (1-6) : ");

                scanf("%d",val2);

                displayRegionandFamilySize(head,regions[val1],val2);

                break;

            case 9:
                printf("Enter filename to write to : \n");

                scanf("%s",filename);

                writeToFile(&head,filename);

                printf("Data writtten to file successfully");

                break;
                val1 = getRegion();

                printf("Enter an upper bound on family income: ");

                scanf("%f",&fval1);

                displayRegionandFamilyIncome(head,regions[val1],fval1);

                break;

            case 10:
                head = NULL;

                printf("Enter filename to read from : \n");

                scanf("%s",filename);

                readFromFile(&head,filename);

                printf("Data loaded from file file successfully");

                break;



            case 0:

                exit(1);

                

            default:

                printf("\nInvalid Choice! Try again.");

        }

    }

}
