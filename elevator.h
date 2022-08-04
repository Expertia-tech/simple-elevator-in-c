#ifndef TEST_H
#define TEST_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_FLOOR 9
#define UP 1    
#define DOWN -1 
#define NOORDER 0

#define PAUSE 1     
#define RUNNING 2  
#define STOP 3

#define time1 2 // for door
#define time2 3  // for each floor
#define time3 6  // waiting time



struct requestNode{
	int floor;
	struct requestNode *nextPtr;
};
typedef struct requestNode NODE;
typedef NODE *NODEPTR;

extern NODEPTR head;  // head pointer to the request list
extern int isOK;
extern char way;
extern int presentfloor;
extern int aimfloor; 
extern int flag;


// fcfs
//  functions definations
void getInput2(); // gets the input 
void control2();  // runs the elevator and print the output to the user
void append(NODE** head_ref, int new_data);  // apends new node to the list
void removeDuplicates(NODEPTR headPtr);   // removes the dublicate nodes from the list
void print_list(NODEPTR Ptr);   // prints the final request list
void free_list(NODEPTR hPtr);   // frees the list



//  for shun bian fu wu
extern int state;
extern int direction;

extern int inSide[10];
extern int up[10];
extern int down[10];



//  function definations
void getInput1(void);        //  gets the request   
void control1(void);    //  sets the aim floor for shun bian fu wu 
void print_message(void);   //displays the out put
int findup(int k);
int finddown(int k);
void state_trans(void);     // desides the state and present floor    
void time_count(void);    // to pause for each floor
void print_request(int arr[]);


//  for input from file
void getInput2FILE(); // gets the input from the file
extern FILE *fP;
extern char ch; // TO READ CHARACTER FROM THE FILE
void getInput1FILE(); // for option b for input from the file 

#endif
