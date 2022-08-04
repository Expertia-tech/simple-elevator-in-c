#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"elevator.h"



void print_message(void)  // displyas the output according to the aimfloor and presentfloor
{	
	FILE * cfPtr;
	if((cfPtr=fopen("clients2.dat","a+"))==NULL)
    	printf("File could be opened\n");
 	else{   

        if(state==RUNNING){
		
           if(direction == UP)
            {
              	fprintf(cfPtr,"up      ");
               	printf("up      ");
            }
           else 
            {
              	fprintf(cfPtr,"down      ");
              	printf("down      ");
            }
        
     	fprintf(cfPtr,"present floor:      %d   aimfloor  %d    running... \n", presentfloor, aimfloor);
     	printf("present floor:      %d   aimfloor  %d    running... \n", presentfloor, aimfloor);

        }else if(state==STOP)
           {
          	fprintf(cfPtr,"present floor:      %d	door is opening.\n", presentfloor);
            printf("present floor:      %d	door is opening.\n", presentfloor);      
            sleep(time1);                          
           	fprintf(cfPtr,"present floor:      %d   waiting\n", presentfloor);
            printf("present floor:      %d   waiting\n", presentfloor);
            sleep(time3);
           	fprintf(cfPtr,"present floor:      %d   door is closing..\n", presentfloor);
            printf("present floor:      %d   door is closing..\n", presentfloor);
           }
}
fclose(cfPtr);
}

void print_request(int arr[]){  // to check if the array is initialized
	int i;
	printf("\n");
	for(i=1; i<MAX_FLOOR;i++){
		printf("| %d |", arr[i]);
	}	
	printf("\n______________________________________________\n");
}
