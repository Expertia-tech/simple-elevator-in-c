#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"
// for shun bian fu wu 
void getInput1()
{
  char request;  // request from the user
  //printf("\nenter your requests£º\n");  
    scanf ("%c",&request);  
    switch(request)
        { 
        	case '1':
                inSide[1]=1;
                break;
        	case '2':
                inSide[2]=1;
                break;
            case '3':
                inSide[3]=1;
                break;      
            case '4':
                inSide[4]=1;
                break;                                        
            case '5':
                inSide[5]=1;
                break; 
            case '6':
                inSide[6]=1;
                break;
            case '7':
                inSide[7]=1;
                break;  
            case '8':
                inSide[8]=1;
                break;
            case '9':
                inSide[9]=1;
                break;   
            case 'Q':
                up[1] = 1;
                break;    
            case 'W':
                up[2]=1;
                break;
            case 'E':
                up[3]=1;
                break;
            case 'R':
                up[4]=1;
                break;    
            case 'T':
                up[5]=1;
                break;      
            case 'Y':
                up[6]=1;
                break;   
        	case 'U':
                up[7]=1;
                break;
            case 'I':
                up[8]=1;
                break;    
            case 'A':
                down[9]=1;
                break;
            case 'S':
                down[8]=1;
                break;
            case 'D':
                down[7]=1;
                break;
            case 'F':
                down[6]=1;
                break;
            case 'G':
                down[5]=1;
                break;
            case 'H':
                down[4]=1;
                break;
            case 'J':
                down[3]=1;
                break;
            case 'K':
                down[2]=1;
                break;
            case '\n':
            	inSide[1]=1;
            	flag = 0;
	            break;
            case 'b':
                printf("already in process.\n");
                break;     
            case 'a':
                printf("switching to option a.\n");
                way = 'a';
                isOK=0;    
                break; 
            case 'c':
            	printf("switching to option c.press c again\n");
            	way = 'c';
            	flag=1; // but since isOK is already set to o it wouldn't enter the loop
            	isOK = 0;
            	break;
			case 'd':
				exit(0);
				break;  
            default:
                printf("INVALID REQUEST\n");
        }
}
