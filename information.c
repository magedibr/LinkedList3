//Create by: Abdelrahman Mohamed
//Date:21/11/2020
//Function implementations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "information.h"

////Function to generate Random households
void create(struct node **head){

    int i =0;

    for(i = 0; i < MAX_VAL; i++) {

        addRandom(head);

    }

    printf("%d  records inserted\n\n",i);
}////End of create function

////New node creation
struct node * newNode(struct household house) {

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->house.race = (char *)malloc(sizeof(char) * strlen(house.race));

    strcpy(temp->house.race,house.race);

    temp->house.region = (char *)malloc(sizeof(char) * strlen(house.region));

    strcpy(temp->house.region,house.region);

    temp->house.town = (char *)malloc(sizeof(char) * strlen(house.town));

    strcpy(temp->house.town,house.town);

    temp->house.h_Size = house.h_Size;

    temp->house.tested=house.tested;

    temp->house.positive=house.positive;

    temp->house.un20=house.un20;

    temp->house.bt2050=house.bt2050;

    temp->house.abv50=house.abv50;

    temp->house.chronDu50=house.chronDu50;

    temp->next = NULL;

    return temp;

}////End of new node function


/////Generate random household
struct node *randomNode() {

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    //Random (town/region/race) generation
    int town_ind = rand() % 6;
    int region_ind = town_ind / 2;
    int race_ind = rand() % 5;

    //Assign random race
    temp->house.race = (char *)malloc(sizeof(char) * strlen(races[race_ind]));
    strcpy(temp->house.race,races[race_ind]);

    //Assign random region
    temp->house.region = (char *)malloc(sizeof(char) * strlen(regions[region_ind]));
    strcpy(temp->house.region,regions[region_ind]);

    //Assign random town
    temp->house.town = (char *)malloc(sizeof(char) * strlen(towns[town_ind]));
    strcpy(temp->house.town,towns[town_ind]);


    //Assign random size from 1-10 members
    int r_size = rand() % 10 + 1;
    temp->house.h_Size = r_size;

    //Assign random under 20
    int under20 = rand()% r_size;
    temp->house.un20=under20;

    int j = r_size-under20;
    int btw = rand()%j;

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

}//// End of random household generation function




////Add random household to list
void addRandom(struct node **head) {

    struct node *new_node = randomNode();

    if(*head == NULL) {

        *head = new_node;

        return;

    }

    struct node *temp = *head;

    while(temp->next != NULL)

        temp = temp->next;

    temp->next = new_node;

}////End of addRandom function




////Add node function
void add(struct node **head,struct household house) {

    struct node *new = newNode(house);

    if(new == NULL) {

        printf("\nTry again");

        return;
    }

    if(*head == NULL) {

        *head = new;
    }

    else {

        struct node *temp = *head;

        while(temp->next != NULL)

            temp = temp->next;

        temp->next = new;

    }

}////End of addNode function


////Print function
void printHousehold(struct household h) {

    static int i=0;

    printf("%20d%20d%20d%20d%20s%25s%20s\n",(i+=1),h.h_Size,h.tested,h.positive,h.race,h.region,h.town);

}////End of print function



////Function to display region
void showRegion(struct node *head, const char *region) {

    struct node *temp = head;

    int dex = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.region,region)==0) {

            if(dex == 0) {

                printf("\nHouseholds of Region: %s\n",region);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

        }

        temp = temp->next;

        dex++;

    }

}////End of region display function


////Function to print all records
void showAll(struct node *head) {

    struct node *temp = head;
    printf("%20s%20s%20s%15s%10s%30s%15s\n\n","S.Num","Size","Total tested","      Total Tested Positive","Race","Region" ,"Town");
    while(temp != NULL) {

        printHousehold(temp->house);

        temp = temp->next;

    }

}////End of all record print function


////Function to display town
void displayTown(struct node *head, const char *town) {

    struct node *temp = head;

    int dex = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.town,town)==0) {

            if(dex == 0) {

                printf("\nHouseholds of Town: %s\n",town);
                printHousehold(temp->house);
            }

            else {

                printHousehold(temp->house);

            }
            dex++;
        }

        temp = temp->next;

    }

}////End of town display


////Function to show race
void displayRace(struct node *head, const char *race) {

    struct node *temp = head;

    int dex = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.race,race)==0) {

            if(dex == 0) {

                printf("\nHouseholds with heads of Race: %s\n",race);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            dex++;

        }

        temp = temp->next;

    }

}////End of Race function



////function to show people tested above a certain level
void displayTestedAboveThresh(struct node *head, int min) {

    struct node *temp = head;

    int v_Reg = getRegion();

    printf("\nHouseholds with a min of %d people tested in region %s :\n\n",min,regions[v_Reg]);

    printf("%20s%20s%25s%25s%25s%20s\n\n","S.Num","Size","Total tested","Race","Region" ,"Town");
    while(temp != NULL) {


        if( strcmp(temp->house.region,regions[v_Reg])==0)
            if (temp->house.tested >= min)
                printHousehold(temp->house);

        temp = temp->next;
    }

}



////Functions used to find and delete specific nodes

void frontDelete(struct node **head) {

    if(*head == NULL) {
        printf("\nerror\n");
        return;

    }

    struct node *temp = *head;

    *head = (*head)->next;

    free(temp);

}

void deleteBtwn(struct node** prevNode, struct node **thisNode) {

    struct node *nextNode = (*thisNode)->next;

    (*prevNode)->next = nextNode;

}

void deleteTail(struct node **prevNode) {

    struct node *current = *prevNode;
    current->next = NULL;
    free(current);

}

void deleteTriplet(struct node **head, const char* region, const char* town, const char* race) {

    struct node *current = *head;

    struct node *prevNode = NULL;

    while(current != NULL) {
        if(strcmp(current->house.region,region)==0 && strcmp(current->house.town,town) == 0 && strcmp(current->house.race,race)==0) {
            if(current == *head) {
                frontDelete(head);
            }

            else if(current->next == NULL) {
                deleteTail(&prevNode);
            }
            else {

                deleteBtwn(&prevNode,&current);

            }
        }

        prevNode = current;
        current = current->next;

    }

}////End of delete functions


////Function to write data to a text file
void textOutput(struct node **head) {

    FILE *fp = fopen("houseinfo.txt","w+");

    if(fp == NULL) {

        printf("\nFile Couldn't be opened");

        return;

    }

    struct node *temp = *head;
    int dex =0;
    fprintf(fp,"%20s%20s%20s%15s%10s%30s%15s\n\n","S.Num","Size","Total tested","      Total Tested Positive","Race","Region" ,"Town");


    while(temp != NULL) {
        dex++;

        fprintf(fp,"%20d%20d%20d%20d%20s%25s%20s\n", dex,temp->house.h_Size,temp->house.tested,temp->house.positive,temp->house.race,temp->house.region,temp->house.town);
        temp = temp->next;
    }

    puts("Content saved to houseinfo.txt");
    fclose(fp);

}////End of text output function


////Function to read from file
void textInput() {
    int c;
    FILE *file;
    file = fopen("houseinfo.txt", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }

}////End of read function


////Function to clear data
void purgeData() {
    int delete;
    while ((delete = getchar()) != '\n' && delete != EOF)
    {}
}////End of clear data function



////Beginning of get region function
int getRegion() {

    int choice;

    while(1) {
        printf("Pick a Region:\n");

        printf("1.Peel 2.York 3.Durham\n");

        if (scanf("%d", &choice) == 1 && (choice > 0 && choice < 4)) { return choice-1; }
        else {
            printf("Invalid data. You should enter one integer in the range 1 through 3. Try again.\n");
            purgeData();
            getRegion();
        }

    }

}
////End of getRegion function



////Begging of getTown function
int getTown() {

    int choice;

    while(1) {

        printf("Pick a town:\n");

        printf("1.Brampton 2.Mississauga 3.Maple 4.Vaughan 5.Whitby 6.Oshawa\n");

        if (scanf("%d", &choice) == 1 && (choice > 0 && choice < 7)) { return choice-1; }
        else {
            printf("Invalid data. You should enter one integer in the range 1 through 6. Try again.\n");
            purgeData();
            getTown();
        }

    }

}////End of town function


int getRace() {

    int choice;

    while(1) {
        printf("Pick a Race:\n");

        printf("1.Caucasian 2.Indigenous 3.African American 5.Asian 6.Other\n");

        if (scanf("%d", &choice) == 1 && (choice > 0 && choice < 7)) { return choice-1; }
        else {
            printf("Invalid data. You should enter one integer in the range 1 through 6. Try again\n");
            purgeData();
            getRace();
        }
    }
}



////Function to count rank of towns and cities
void getRank(struct node *head){

    struct node *temp = head;


    int reg_D=0,reg_P=0,reg_Y=0;

    int twn_Osh=0,twn_Whi=0,twn_brmp=0,twn_Miss=0,twn_Map=0,twn_Va=0;


    while(temp->next!=NULL){

        if(strcmp(temp->house.region,"Peel")==0)reg_P+=temp->house.tested;
        if(strcmp(temp->house.region,"York")==0)reg_Y+=temp->house.tested;
        if(strcmp(temp->house.region,"Durham")==0)reg_D+=temp->house.tested;

        if(strcmp(temp->house.town,"Brampton")==0)twn_brmp+=temp->house.tested;
        if(strcmp(temp->house.town,"Mississauga")==0)twn_Miss+=temp->house.tested;
        if(strcmp(temp->house.town,"Maple")==0)twn_Map+=temp->house.tested;
        if(strcmp(temp->house.town,"Vaughan")==0)twn_Va+=temp->house.tested;
        if(strcmp(temp->house.town,"Whitby")==0)twn_Whi+=temp->house.tested;
        if(strcmp(temp->house.town,"Oshawa")==0)twn_Osh+=temp->house.tested;

        temp=temp->next;

    }


    puts("Town wise ranking of regions with highest number of people tested Positive for Covid-19");

    printf("Peel: %d \n York: %d \n Durham: %d\n\n",reg_P,reg_Y,reg_D);

    printf("Town-wise distribution:"
           "\n Brampton: %d"
           "\n Mississauga: %d"
           "\n Maple: %d"
           "\n Vaughan: %d"
           "\n Whitby: %d"
           "\n Oshawa: %d",twn_brmp,twn_Miss,twn_Map,twn_Va,twn_Whi,twn_Osh);
}////End of get Rank function




////Begging of userAdd function
void userAdd(struct node *head,struct household userHouse){

    int r_Id = getRegion();
    userHouse.region = (char *)malloc(sizeof(char) * strlen(regions[r_Id]));
    strcpy(userHouse.region,regions[r_Id]);


    int tr_Id = getTown();
    userHouse.town = (char *)malloc(sizeof(char) * strlen(towns[tr_Id]));
    strcpy(userHouse.town,towns[tr_Id]);


    int rc_Id = getRace();
    userHouse.race = (char *)malloc(sizeof(char) * strlen(races[rc_Id ]));
    strcpy(userHouse.race,races[rc_Id]);


    int v1=0,v2=0,v3=0,val4=0,val5=0;

    while(1) {
        ////Family size validation
        while(1) {
            printf("Enter family size :\n");
            int ctr=  scanf("%d", &userHouse.h_Size);


            if ( userHouse.h_Size> 10 || userHouse.h_Size <= 0 ||ctr !=1 ){
                puts("Size must between 1-10, please try again.");
                purgeData();}

            else{
                v1=1;
                break;}
        }
        //////End of family size validation

        ////Number of people tested validation
        while(v1) {
            printf("Enter number of people tested:\n");

            int ctr2=  scanf("%d", &userHouse.tested);

            if(userHouse.tested<0|| userHouse.tested>userHouse.h_Size||ctr2!=1){

                printf("Amount of people tested must be less than or equal to %d and the it must be a positive integer, please try again.\n",userHouse.h_Size) ;
                purgeData();}
            else { v2=1;
                break;

            }
        }
        ////End of number of people tested validation

        ////positive cases validation

        while(v2) {

            printf("Enter number of positive cases:\n");
            int ctr3= scanf("%d", &userHouse.positive);

            if(userHouse.positive<0||userHouse.positive>userHouse.h_Size||userHouse.positive>userHouse.tested ||ctr3!=1){
                printf("Amount of positive cases can not be greater then the amount of"
                       "tested members( %d ) or larger than %d and  must be a real "
                       "positive integer, please try again.\n",userHouse.tested,userHouse.h_Size);
                purgeData();}
            else{
                v3=1;
                break;}
        }
        ////End of positive cases validation

        ////U20 validation
        while(v3){

            printf("Number of people below 20:\n");

            int ctr4 = scanf("%d", &userHouse.un20);

            if(userHouse.un20<0||userHouse.un20>userHouse.h_Size||ctr4!=1){
                printf("People under 20 can not be more than %d and must be a real positive integer, please try again.\n",userHouse.h_Size);
                purgeData();
            }
            else{
                val4=1;
                break;
            }
        }
        ////End of u20 validation

        while (val4){

            printf("Please Enter the amount of people above 50\n");

            int ctr6= scanf("%d",&userHouse.abv50);

            if(ctr6!=1||userHouse.abv50>(userHouse.h_Size-userHouse.un20)){
                puts("Number can not be larger then the amount of people under 50 and must be a valid positive integer, please try again.\n");
                purgeData();

            }else {
                purgeData();
                val5=1;
                break;
            }

        }
        /////chron U50 validation

        while(val5){

            char buff[5];
            int p1=0,p2=0,p3=0,p4=0,p5=0;
            int btw= userHouse.un20+userHouse.bt2050;

            printf("Enter number of people below 50 with chronic dis, separated by tabs. Please make sure these are valid integers(Maximum of 5 entries)");

            fgets(buff,sizeof(buff),stdin);
            int ctr5 = sscanf(buff,"%d%d%d%d%d",&p1,&p2,&p3,&p4,&p5);
            int totalPe = p1+p2+p3+p4+p5;

            if( !(ctr5>0 && ctr5<6) ||totalPe>btw){

                printf("The number of people can not exceed the total of people under 50");
                purgeData();
            }else {
                userHouse.chronDu50=totalPe;
                break;
            }
        }
////end of chron50 validation
        break;
    }
    printHousehold(userHouse);

    add(&head,userHouse);
}////End of user add function
