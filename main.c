#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "information.h"


int main() {

    struct node *head = NULL;

    int on = 1, choice, val1, val2, val3;

    int minTest;

    struct household userHouse;


    srand(time(NULL));


 create(&head);


    while(on) {

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

        printf("0. Exit\n");



        while(1) {
            printf("Enter your choice: ");
            int ctr= scanf("%d",&choice);

            if(ctr!=1){ puts("Please enter a valid number");
            purgeData();}
            else break;
        }


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

                scanf("%d",&minTest);

                displayTestedAboveThresh(head,minTest);

                break;

            case 5:

                getRank(head);
                break;

            case 6:
                userHouse.bt2050=0;
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

                printf("%20s%20s%20s%20s%20s%20s\n\n","S.Num","Size","Total tested","Race","Region" ,"Town");
                displayAll(head);

                break;

            case 9:

                writeToFile(&head);
                break;


            case 10:
                head = NULL;
                printf("File contents : \n");
                readFromFile(&head);

                break;

            case 0:
                    on=0;
                break;

            default:

                printf("\nInvalid Choice! Try again.");

        }

    }

}


