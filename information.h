//
// Created by Abdelrahman Mohamed on 2020-11-16.
//

#ifndef ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H
#define ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H

#define MAX_VAL 5
static const char *regions[] = {"Peel","York","Dorm"};

static const char *towns[] = {"Brampton","Mississauga","Maple","Vaughan","Whitby","Oshawa"};

static const char *races[] = {"Caucasian", "Indigenous", "African American", "Asian", "Other"};


struct household {
    char* race_of_head;
    char* region;
    char* town;
    int h_Size;
    int tested;
    int positive;
    int un20;
    int bt2050;
    int abv50;


    //int chronDu50;
    struct houseinfo *houseinfo;
};



struct node {
    struct household house;
    struct node *next;
};

struct node * newNode(struct household house);
struct node *randomNode();
void addRandom(struct node **head);
void add(struct node **head,struct household house);
void printHousehold(struct household h);
void displayRegion(struct node *head, const char *region);
void displayAll(struct node *head);
void displayTown(struct node *head, const char *town);
void displayRace(struct node *head, const char *race);
void displayFamilySize(struct node *head, int ub);
void displayBelowFamilyIncome(struct node *head, float ub);
void displayTestedAboveThresh(struct node *head, float lb);
void displayRegionandTown(struct node *head, const char *region, const char *town);
void displayRegionandFamilySize(struct node *head, const char *region, int ub);
void displayRegionandFamilyIncome(struct node *head, const char *region, float ub);
void removeAtFront(struct node **head);
void removeAtMiddle(struct node** prevNode, struct node **currNode);
void removeAtEnd(struct node **prevNode);
void deleteRTR(struct node **head, const char* region, const char* town, const char* race);
void deleteRTF(struct node **head, const char* region, const char* town, int family_size);
void writeToFile(struct node **head, const char* filename);
void readFromFile(struct node **head, const char* filename);
int getRegion();
int getTown();
int getRace();
int getTownInRegion(int regInd);

void userAdd();
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);
void getRank(struct node *head);
#endif //ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H
