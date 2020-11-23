//Create by: Abdelrahman Mohamed
//Date:21/11/2020
//Function prototypes

#ifndef ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H
#define ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H

#define MAX_VAL 100

static const char *regions[] = {"Peel","York","Durham"};

static const char *towns[] = {"Brampton","Mississauga","Maple","Vaughan","Whitby","Oshawa"};

static const char *races[] = {"Caucasian", "Indigenous", "A.American","Asian", "Other"};


struct household {
    char* race;
    char* region;
    char* town;
    int h_Size;
    int tested;
    int positive;
    int un20;
    int bt2050;
    int abv50;
    int chronDu50;

};

struct node {
    struct household house;
    struct node *next;
};


// Node manipulation functions
void create(struct node **head);
struct node * newNode(struct household house);
struct node *randomNode();
void addRandom(struct node **head);
void add(struct node **head,struct household house);
void purgeData();
void frontDelete(struct node **head);
void deleteBtwn(struct node** prevNode, struct node **thisNode);
void deleteTail(struct node **prevNode);
void deleteTriplet(struct node **head, const char* region, const char* town, const char* race);
void userAdd(struct  node *head,struct household userHouse);

// Print functions
void printHousehold(struct household h);
void showRegion(struct node *head, const char *region);
void showAll(struct node *head);
void displayTown(struct node *head, const char *town);
void displayRace(struct node *head, const char *race);
void displayTestedAboveThresh(struct node *head, int lb);

// I/O functions
void textOutput(struct node **head);
void textInput();

// Data retrieval
int getRegion();
int getTown();
int getRace();
void getRank(struct node *head);

#endif //ABDELRAHMANMOHAMEDASSIGN3_INFORMATION_H
