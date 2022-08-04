#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

NODEPTR head=NULL;
int isOK=1;  //  key to control the algorithm used
char way;   //  
int presentfloor = 1;
int aimfloor = 0; 
int flag = 1;  //to control when to stop the input in second algorithm
int state = PAUSE;
int direction = NOORDER;

// for second algorithm
int inSide[10] = {0};
int up[10] = {0};
int down[10] = {0};

FILE *fP;  
char ch; // TO READ CHARACTER FROM THE FILE
//aQWE674
//bQW45GS1
int main(int argc, char *argv[]) 
{	printf("_____________________________________________________________________________\n");
	printf("_____________________________________________________________________________\n\n");
	printf("                                 WELCOME                         \n");
	printf("	Q	W	E	R	T	Y	U	I 	(up buttons for floor 1 to 8)\n");  // buttons for up direction for 1 to 8
	printf("	A	S	D	F	G	H	J	K 	(down buttons from floor 9 to 2)\n");  // buttons for down direction from 9 to 2
	printf("	1	2	3	4	5	6	7	8	(9  buttons inside the elevator)\n");  //buttons inside the elevator for the destination floor 
	printf("_____________________________________________________________________________\n");
	printf("_____________________________________________________________________________\n");
		
	printf("\n______________________________________________________\n");
	printf("------------------choose the option-------------------\n");
	printf("a : First Come First Serve\n");
	printf("b : second algorithm\n");
	printf("c : take input from file\n");
	printf("d : exit\n");
	printf("\n______________________________________________________\n");
	printf("your option is: ");
	//fflush(stdin);
	scanf("%c",&way);
		
	while(1){
		
		switch(way){
			case 'a':
				isOK=1;
				while(isOK==1){
					getInput2();					
					removeDuplicates(head);
					print_list(head);
					control2();				
					free_list(head);
					//system("pause");
				}
				break;
			case 'b':
				isOK=1;
				
      			while(isOK==1) 
         		{	
         			if(flag==1){					
          				getInput1();
          			}
//          		print_request(up);
//          		print_request(down);
//          		print_request(inSide);									
         			state_trans();//decides the state of the elevator and changes the presentfloor
         			print_message(); //displays the output according to the aimfloor and present floor set by control1 
          			control1(); // sets the aimfloor
					time_count();//pause for each floor          			
          		}
				break;
			case 'c':
				if((fP=fopen("clientInput.txt","r"))==NULL){	
					printf("File could not be opened\n");
					exit(1);
				}
				//while((ch = fgetc(fP))!=EOF){
				ch = fgetc(fP);
					if(ch=='a'){
						isOK=1;
					//	while(isOK==1){
							getInput2FILE();							
							removeDuplicates(head);
							print_list(head);
							control2();							
							free_list(head);
							//system("pause");
							fflush(stdin);
							scanf("%c",&way);
							//break;
						//}
					}
		
					else if(ch=='b'){
						isOK=1;
						flag=1;
						do{
							ch = fgetc(fP);
							if(flag==1){				
								getInput1FILE();
							}
         					state_trans();//decides the state of the elevator and changes the presentfloor
         					print_message();           		
          					control1(); // sets the aimfloor
          					time_count();
          				}while(isOK==1) ;
					break;				
					}
					
				//}		
				fclose(fP);
				break;
			case 'd':
				exit(0);
				break;
			default:
				
				printf("INVALID REQUEST!!\n");
    			printf("please input your request according to the instruction: ");
    			//scanf("%c",&way);
    			break;
		}
		//fflush(stdin);
		
		//scanf("%c",&way);		
	}
	return 0;
}
