#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"elevator.h"

//int presentfloor = 1;
//int aimfloor = 0;

//  arrays representing buttons for each floor
///int inSide[10] = {0};
//int up[10] = {0};
//int down[10] = {0};


//  for shun bian fu wu
//int state = PAUSE;
//int direction = NOORDER;

// shun bian fu wu

//  this basically runs the elevator
void control1()
{
	int floor,i,j;
	if(direction==UP)
  	{   
   		floor=findup(presentfloor);  //floor nearest up request 
   		 
   		if(floor<=MAX_FLOOR){
   
      	aimfloor=floor;
   		
    	}else{
      		floor=finddown(9);  //nearest down request 
      		if(floor>=1)
         		aimfloor=floor;
     		else
       		{
         		floor=findup(1);
         		if(floor<presentfloor)
         			aimfloor=floor;
         	}
     	}
   }
	else if(direction==DOWN)
  	{
   		floor=finddown(presentfloor);
   
   		if(floor>=1){ // if there is a down request
       		aimfloor=floor;
    	}else{  // if no request
      	floor=findup(1);
      	if(floor<=MAX_FLOOR)
        aimfloor=floor;
      	else
        {
         	floor=finddown(9);
         	if(floor>presentfloor)
         		aimfloor=floor;
        	}
      	}
    }
	if(direction==NOORDER)
   	{   		
		// serves the nearest down or up request
   		//  return which ever has the shortest path
    	for(i=presentfloor;i<=9&&up[i]==0&&down[i]==0&&inSide[i]==0;i++);  // from down to up 
        	for(j=presentfloor;j>=1&&up[j]==0&&down[j]==0&&inSide[j]==0;j--);  // from up to down 
               	if(i!=10&&j!=0)  
                {
                 	if((i-presentfloor)>=(presentfloor-j)){
                		floor=j;
					}else{
						floor=i;
					}
                  	aimfloor=floor;   
                }else if(i==10&&j!=0)
                  		aimfloor=j;
              	else if(j==0&&i!=10)
                  		aimfloor=i; 
                else{  // after traversing if i is 10 and j is 0 then there is no order left so we want to take the input again
					   	if(way=='b'||way=='a'){
						   
                  		flag=1; // to stop the loop and take the input 
                  		}
                  		else if(way=='c'&&flag==0){  // to end the loop and take the new input
                  			isOK=0;
                  			fflush(stdin);
						  	scanf("%c",&way);	
						}
                  	}
   }
   	if(aimfloor<presentfloor) 
    	direction=DOWN;
	else if(aimfloor>presentfloor)
    	direction=UP;	
	else 
    	direction=NOORDER;
}

int findup(int k)  // returns the nearest up request 
{
int i;
for (i=k;i<=9;i++)
    if (up[i] || inSide[i])
    return(i);
return 10;
}
int finddown(int k)  // returns the nearest down request
{
int i;
for (i=k;i>=1;i--)
    if (down[i] || inSide[i])
    return(i);
return 0;
}

void time_count()
{
 time_t start,finish;
 start=clock();
 finish=clock();
 if(direction!=NOORDER){  // to not stop if the direction of the elevator is noorder
 
 while((finish-start)/CLOCKS_PER_SEC < time2)
    {
      finish=clock();
    }
}
}
