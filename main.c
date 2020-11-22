#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "information.h"


int main() {

    struct node *head = NULL;

    int go = 1, choice, val1, val2, val3;

    int fval1;

    struct household userHouse;

    char filename[20];

    srand(time(NULL));


    //Node creation
   for(int i =0;i<10;i++){
            printf("%d\n",i);

       printf("Insert call");

       struct node *new_node = randomNode();

       if(head == NULL){head = new_node;
       continue;}

       struct node *temp = head;



       while(temp->next != NULL)

           temp = temp->next;

       temp->next = new_node;

//printHousehold(head->house);
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

                scanf("%d",&fval1);

                displayTestedAboveThresh(head,fval1);

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
                displayAll(head);

                break;



            case 9:
                printf("Enter filename to write to : \n");

                scanf("%s",filename);

                writeToFile(&head,filename);

                printf("Data writtten to file successfully");

                break;


            case 10:
                head = NULL;

                printf("Enter filename to read from : \n");

                scanf("%s",filename);

                readFromFile(&head,filename);

                printf("Data loaded from file file successfully");
                go=0;
                break;

            case 0:
                break;

            default:

                printf("\nInvalid Choice! Try again.");

        }

    }

}
void addRandom(struct node **head) {

    printf("Insert call");

    struct node *new_node = randomNode();

    if(*head == NULL) {

        *head = new_node;

        return;

    }

    struct node *temp = *head;

    while(temp->next != NULL)

        temp = temp->next;

    temp->next = new_node;

}

struct node *randomNode() {
    // srand(time(NULL));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int l =0;
    l++;
    printf("%d DIFF NODES",l);
    //Random town~region~race generation
    int town_ind = rand() % 6;
    int region_ind = town_ind / 2;
    int race_ind = rand() % 5;

    //Assign random race
    temp->house.race_of_head = (char *)malloc(sizeof(char) * strlen(races[race_ind]));
    strcpy(temp->house.race_of_head,races[race_ind]);

    //Assign random region
    temp->house.region = (char *)malloc(sizeof(char) * strlen(regions[region_ind]));
    strcpy(temp->house.region,regions[region_ind]);

    //Assign random town
    temp->house.town = (char *)malloc(sizeof(char) * strlen(towns[town_ind]));
    strcpy(temp->house.town,towns[town_ind]);

    ///malloc needed?
    //Assign random size from 1-10 members
    int r_size = rand() % 10 + 1;
    temp->house.h_Size = r_size;


    //Assign random under 20

    // temp->house.un20=under20;
    int under20 = rand()% r_size;
    int j = r_size-under20;  //20++
    int btw = rand()%j
    ;
    temp->house.bt2050=btw;

    int abv = r_size-(under20+btw);
    temp->house.abv50=abv;


    //Assign random tested qty
    int r_tested = rand()% r_size+ 1;
    temp->house.tested=r_tested;

    //Assign random positivity rate
    int r_positive= rand()% r_tested+1;
    temp->house.positive=r_positive;

    //random U50 chronic D
    int lf = under20+btw;

    temp->house.chronDu50=0;

    temp->next = NULL;

    return temp;

}