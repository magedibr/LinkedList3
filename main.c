//Create by: Abdelrahman Mohamed
//Date:21/11/2020
//Main method

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "information.h"


int main() {

    struct node *head = NULL;

    int on = 1, choice, v1, v2, v3;

    int minTest;

    struct household userHouse;


    srand(time(NULL));

    //Random record generation
    create(&head);
    showAll(head);

    while(on) {

        printf("\n\n*********************** Population Info Menu ***********************\n");


        printf("1.  Display households of a Region\n");

        printf("2.  Display households of a Town\n");

        printf("3.  Display households of a Race\n");

        printf("4.  Display households of a region with a given minimum number of people tested positive for Covid-19\n");

        printf("5.  Display the regions town-wise ranking of number of people tested positive for Covid-19\n");

        printf("6.  Add a record\n");

        printf("7.  Delete all records of a region, town and race triplet\n");

        printf("8.  Display all/updated data\n");

        printf("9.  Store data to a file\n");

        printf("10. Display data from file\n");

        printf("0.  Exit\n");


        //Loop to check that input is an int
        while(1) {
            printf("Enter your choice: ");
            int ctr= scanf("%d",&choice);

            if(ctr!=1){ puts("Please enter a valid number");
                purgeData();}
            else break;
        }


        switch(choice) {

            case 1:

                v1 = getRegion();

                showRegion(head,regions[v1]);

                break;

            case 2:

                v1 = getTown();

                displayTown(head,towns[v1]);

                break;

            case 3:

                v1 = getRace();

                displayRace(head,races[v1]);

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

                v1 = getRegion();

                v2 = getTown();

                v3 = getRace();

                deleteTriplet(&head,regions[v1],towns[v2],races[v3]);

                printf("Records Deleted\n");

                break;

            case 8:


                showAll(head);

                break;

            case 9:

                textOutput(&head);
                break;


            case 10:
                head = NULL;
                printf("File contents : \n");
                textInput();

                break;

            case 0:
                on=0;
                break;

            default:

                printf("\nInvalid Choice! Try again.");

        }

    }

}


