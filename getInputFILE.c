#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"
// to get input from the file


void getInput2FILE(){  // gets all the input at once
	char request;
	printf("\ninput: \n");
	while((request=fgetc(fP)) != EOF){
		
		//scanf("%c",&request);
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
                ch='b';
                isOK=0; 
                break; 
			case 'd':
				exit(0);
				break; 
			case '\n':
			 	break;  
           default:
                printf("INVALID REQUEST\n");
                break;
		}
	}
	if(request==EOF){
		append(&head, 1);
	}
	
}


void getInput1FILE()   // gets the input one by one as the program runs 
{
  char request;  // request from the user
  //printf("\nenter your requests£º\n");  
    //scanf ("%c",&request);  
    request = ch;
    switch(request)
        { 	
        	case EOF:
        		inSide[1]=1;
        		flag=0;
        		break;
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
	            break;
            case 'b':
                printf("already in process.\n");
                break;     
            case 'a':
                printf("switching to option a.\n");
                way='a';
                isOK=0;    
                break; 
			case 'd':
				exit(0);
				break;  
            default:
                printf("INVALID REQUEST\n");
        }
}
