#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"elevator.h"


void getInput2(){
	char request;
	printf("\ninput: \n");
	while(request!='\n' && isOK==1){		
		scanf("%c",&request);
		switch(request){
			case 'Q': 
                append(&head, 1);
                break; 
           case 'W': 
                append(&head, 2);
                break; 
           case 'E': 
                append(&head, 3);
                break; 
           case 'R': 
                append(&head, 4); 
                break; 
           case 'T': 
                append(&head, 5); 
                break; 
           case 'Y': 
                append(&head, 6);
                break; 
           case 'U': 
                append(&head, 7);
                break; 
           case 'I': 
                append(&head, 8);
                break; 
           case 'A': 
                append(&head, 9);
                break; 
           case 'S': 
                append(&head, 8);
                break; 
           case 'D': 
                append(&head, 7);
                break; 
           case 'F': 
                append(&head, 6);
                break; 
           case 'G': 
                append(&head, 5);
                break; 
           case 'H': 
                append(&head, 4);
                break; 
           case 'J': 
                append(&head, 3);
                break; 
           case 'K': 
                append(&head, 2); 
                break; 
           case '1':  
                append(&head, 1); 
                break; 
           case '2': 
                append(&head, 2); 
                break; 
           case '3': 
                append(&head, 3); 
                break; 
           case '4': 
                append(&head, 4); 
                break; 
           case '5': 
                append(&head, 5); 
                break; 
           case '6': 
                append(&head, 6); 
                break; 
           case '7': 
                append(&head, 7); 
                break; 
           case '8': 
                append(&head, 8); 
                break; 
           case '9': 
                append(&head, 9); 
                break;
           case 'a':
                printf("already in process.\n");
                break;     
           case 'b':
                printf("switching to option b.\n");
                way = 'b';
                isOK=0; 
                break;
			case 'c':
				printf("switching to option c.\n");
				way = 'c';
				isOK = 0;
				break; 
			case 'd':
				exit(0);
				break; 
			case '\n':
				append(&head, 1); //to return to ground floor//
			 	break;  
           default:
                printf("INVALID REQUEST (in fcfs)\n");
                break;
		}
	}
	
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(NODE** head_ref, int new_data)
{
    /* 1. allocate node */
    NODE* new_node = malloc(sizeof(NODE));
 
    NODE *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->floor  = new_data;
 
    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->nextPtr = NULL;
 
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    } 
      
    /* 5. Else traverse till the last node */
    while (last->nextPtr != NULL)
        last = last->nextPtr;
  
    /* 6. Change the next of last node */
    last->nextPtr = new_node;
    return;   
}
