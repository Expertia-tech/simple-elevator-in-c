#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"


void control2(){
	FILE * cfPtr;
 	if((cfPtr=fopen("clients2.dat","a+"))==NULL){
	   	printf("File could be opened\n");
	}
 	else{
 		while(head!=NULL){
 			aimfloor = head->floor;
 			if(aimfloor < presentfloor){
 				while(aimfloor < presentfloor){
 					presentfloor --;
 					sleep(time2);  //3
 					fprintf(cfPtr,"DOWN		current floor is %d		target floor is %d 		running...\n", presentfloor, aimfloor);
 					printf("DOWN		current floor is %d		target floor is %d		running...\n",presentfloor, aimfloor);
				 }
			 }
			
			if(aimfloor > presentfloor){
				while(aimfloor > presentfloor){
					presentfloor ++;
					sleep(time2);  //3
					fprintf(cfPtr,"UP		current floor is %d	 target floor is %d		running...\n", presentfloor, aimfloor);
 					printf("UP		current floor is %d		target floor is %d		running...\n",presentfloor, aimfloor);
					
				}
			}
			
			if(aimfloor == presentfloor){
				sleep(time1); // time for door
				fprintf(cfPtr,"\nstoping.. 	current floor is %d		The door is opening..\n",aimfloor);
				printf("\nstoping.. 	current floor is %d		The door is opening...\n",presentfloor);  // since aimfloor is equals to presentfloor u can write both
				sleep(time3); // 3
				fprintf(cfPtr,"stopped		current floor is %d		waiting....\n", aimfloor);
				printf("stopped		current floor is %d		waiting....\n",aimfloor);
				sleep(time1); //time for door
				fprintf(cfPtr,"stopped		current floor is %d		the door is closing..\n\n", aimfloor);
				printf("stopped		current floor is %d		the door is closing..\n\n",aimfloor);					
			}
			head = head->nextPtr;
		 }
		 fprintf(cfPtr,"stopped		current floor is %d		IDLE..\n\n", presentfloor);
		 printf("stopped		current floor is %d 	IDLE..\n\n",presentfloor);
		 sleep(time2);
	}
	fclose(cfPtr);
}




/* The function removes duplicates from a sorted list */
void removeDuplicates(NODEPTR headPtr)
{
    /* Pointer to traverse the linked list */
    NODEPTR current = headPtr;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    NODEPTR next_next;
   
    /* do nothing if the list is empty */
    if (current == NULL)
       return;
 
    /* Traverse the list till last node */
    while (current->nextPtr != NULL)
    {
       /* Compare current node with next node */
       if (current->floor == current->nextPtr->floor)
       {
           /* The sequence of steps is important*/              
           next_next = current->nextPtr->nextPtr;
           free(current->nextPtr);
           current->nextPtr = next_next; 
       }
       else /*  only advance if no deletion */
       {
          current = current->nextPtr;
       }
    }
}

void print_list(NODEPTR Ptr){
	while(Ptr != NULL){
		printf("%d ", Ptr->floor);
		Ptr = Ptr->nextPtr;
	}
	printf("\n");
}

void free_list(NODEPTR hPtr){
	while(hPtr!=NULL){
		free(hPtr);
		hPtr = hPtr->nextPtr;
	}	
}
