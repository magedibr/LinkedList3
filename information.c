#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "information.h"


struct node * newNode(struct household house) {

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->house.race_of_head = (char *)malloc(sizeof(char) * strlen(house.race_of_head));

    strcpy(temp->house.race_of_head,house.race_of_head);

    temp->house.region = (char *)malloc(sizeof(char) * strlen(house.region));

    strcpy(temp->house.region,house.region);

    temp->house.town = (char *)malloc(sizeof(char) * strlen(house.town));

    strcpy(temp->house.town,house.town);

    temp->house.h_Size = house.h_Size;

    temp->house.tested=house.tested;

    temp->house.positive=house.positive;

    temp->next = NULL;

    return temp;

}


//Generate random household
struct node *randomNode() {

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    //Random town/region/race generation
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

    //Assign random size from 1-10 members
    int r_size = rand() % 10 + 1;
    temp->house.h_Size = r_size;

    //Assign random tested qty
    int r_tested = rand()% r_size+ 1;
    temp->house.tested=r_tested;

    //Assign random posotivity rate
    int r_positive= rand()% r_tested;
    temp->house.positive=r_positive;

    temp->next = NULL;

    return temp;

} //// End of random household generation function

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

void add(struct node **head,struct household house) {

    struct node *new = newNode(house);

    if(new == NULL) {

        printf("\nOverflow");

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

}

void printHousehold(struct household h) {

    printf("\nRegion : %s\n",h.region);

    printf("Town: %s\n",h.town);

    printf("Race of Head of the Household: %s\n",h.race_of_head);

    printf("Number of people in the household: %d\n",h.h_Size);

    printf("Household yearly income: $%.2f\n",h.yearly_income);

}

void displayRegion(struct node *head, const char *region) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.region,region)==0) {

            if(idx == 0) {

                printf("\nHouseholds of Region: %s\n",region);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

        }

        temp = temp->next;

        idx++;

    }

}

void displayAll(struct node *head) {

    struct node *temp = head;

    while(temp != NULL) {

        printHousehold(temp->house);

        temp = temp->next;

    }

}

void displayTown(struct node *head, const char *town) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.town,town)==0) {

            if(idx == 0) {

                printf("\nHouseholds of Town: %s\n",town);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            idx++;

        }

        temp = temp->next;

    }

}

void displayRace(struct node *head, const char *race) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.race_of_head,race)==0) {

            if(idx == 0) {

                printf("\nHouseholds with heads of Race: %s\n",race);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            idx++;

        }

        temp = temp->next;

    }

}

void displayFamilySize(struct node *head, int ub) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(temp->house.h_Size <= ub) {

            if(idx == 0) {

                printf("\nHouseholds with atmost : %d family members\n",ub);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            idx++;

        }

        temp = temp->next;

    }

}

void displayBelowFamilyIncome(struct node *head, float ub) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(temp->house.yearly_income < ub) {

            if(idx == 0) {

                printf("\nHouseholds with income less than : $%.2f \n",ub);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            idx++;

        }

        temp = temp->next;

    }

}

void displayAboveFamilyIncome(struct node *head, float lb) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(temp->house.yearly_income >= lb) {

            if(idx == 0) {

                printf("\nHouseholds with income greater than or equal to : $%.2f \n",lb);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

            idx++;

        }

        temp = temp->next;

    }

}

void displayRegionandTown(struct node *head, const char *region, const char *town) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.region,region)==0 && strcmp(temp->house.town,town)==0) {

            if(idx == 0) {

                printf("\nHouseholds of Region and Town: %s, %s respectively\n",region,town);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

        }

        temp = temp->next;

    }

}

void displayRegionandFamilySize(struct node *head, const char *region, int ub) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.region,region)==0 && temp->house.h_Size <= ub) {

            if(idx == 0) {

                printf("\nHouseholds of Region : %s, and at most %d family members\n",region,ub);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

        }

        temp = temp->next;

    }

}

void displayRegionandFamilyIncome(struct node *head, const char *region, float ub) {

    struct node *temp = head;

    int idx = 0;

    while(temp != NULL) {

        if(strcmp(temp->house.region,region)==0 && temp->house.yearly_income <= ub) {

            if(idx == 0) {

                printf("\nHouseholds of Region : %s, and at most $%.2f yearly income\n",region,ub);

                printHousehold(temp->house);

            }

            else {

                printHousehold(temp->house);

            }

        }

        temp = temp->next;

    }

}

void removeAtFront(struct node **head) {

    if(*head == NULL) {

        printf("\nUnderflow");

        return;

    }

    struct node *temp = *head;

    *head = (*head)->next;

    free(temp);

}

void removeAtMiddle(struct node** prevNode, struct node **currNode) {

    struct node *nextNode = (*currNode)->next;

    (*prevNode)->next = nextNode;

}

void removeAtEnd(struct node **prevNode) {

    struct node *tracer = *prevNode;

    struct node *temp = tracer->next;

    tracer->next = NULL;

    free(tracer);

}

void deleteRTR(struct node **head, const char* region, const char* town, const char* race) {

    struct node *tracer = *head;

    struct node *prevNode = NULL;

    while(tracer != NULL) {

        if(strcmp(tracer->house.region,region)==0 && strcmp(tracer->house.town,town) == 0 && strcmp(tracer->house.race_of_head,race)==0) {

            if(tracer == *head) {

                removeAtFront(head);

            }

            else if(tracer->next == NULL) {

                removeAtEnd(&prevNode);

            }

            else {

                removeAtMiddle(&prevNode,&tracer);

            }

        }

        prevNode = tracer;

        tracer = tracer->next;

    }

}

void deleteRTF(struct node **head, const char* region, const char* town, int family_size) {

    struct node *tracer = *head;

    struct node *prevNode = NULL;

    while(tracer != NULL) {

        if(strcmp(tracer->house.region,region)==0 && strcmp(tracer->house.town,town) == 0 && tracer->house.h_Size == family_size) {

            if(tracer == *head) {

                removeAtFront(head);

            }

            else if(tracer->next == NULL) {

                removeAtEnd(&prevNode);

            }

            else {

                removeAtMiddle(&prevNode,&tracer);

            }

        }

        prevNode = tracer;

        tracer = tracer->next;

    }

}

void writeToFile(struct node **head, const char* filename) {

    FILE *fp = fopen(filename,"w");

    if(fp == NULL) {

        printf("\nFile Couldn't be opened");

        return;

    }

    struct node *temp = *head;

    while(temp != NULL) {

        fwrite(&temp->house,sizeof(struct household),1,fp);

        temp = temp->next;

    }

    fclose(fp);

}

void readFromFile(struct node **head, const char* filename) {

    FILE *fp = fopen(filename,"r");

    if(fp == NULL) {

        printf("\nFile Couldn't be opened");

        return;

    }

    struct household house;

    while(fread(&house,sizeof(struct household),1,fp)) {

        add(head,house);

    }

    printf("\nDatabase Loaded from file");

}

int getRegion() {

    int choice;

    do {

        printf("Pick a Region:\n");

        printf("1.Peel 2.York 3.Dorm\n");

        scanf("%d",&choice);

        if(choice < 1 || choice > 3)

            printf("Invalid region pick!\n");

    } while(choice < 1 || choice > 3);

    return choice-1;

}

int getTown() {

    int choice;

    do {

        printf("Pick a town:\n");

        printf("1.Brampton 2.Mississauga 3.Maple 4.Vaughan 5.Whitby 6.Oshawa\n");

        scanf("%d",&choice);

        if(choice < 1 || choice > 6)

            printf("Invalid town pick!\n");

    } while(choice < 1 || choice > 6);

    return choice-1;

}

int getRace() {

    int choice;

    do {

        printf("Pick a Race:\n");

        printf("1.Caucasian 2.Indigenous 3.African 4.American 5.Asian 6.Other\n");

        scanf("%d",&choice);

        if(choice < 1 || choice > 6)

            printf("Invalid race pick!\n");

    } while(choice < 1 || choice > 6);

    return choice-1;

}

int getTownInRegion(int regInd) {

    int choice;

    printf("Pick a town: \n");

    do {

        printf("1. %s 2. %s",regions[2*regInd],regions[2*regInd+1]);

        scanf("%d",&choice);

        if(choice < 1 || choice > 2)

            printf("\nInvalid town pick!\n");

    } while(choice < 1 || choice > 2);

    return 2 * regInd + (choice - 1);

}