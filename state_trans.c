#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"elevator.h"


void state_trans()
{  //flag=1;                               
  switch(state){
               case PAUSE: 
                          
                   if(aimfloor == presentfloor){
                      	state = STOP;
                   
                   	}else if(aimfloor != 0){
					    state = RUNNING;
					}
                   // if no order  
                    else if(aimfloor == 0)
                      direction = NOORDER;
                    break;
            
               case RUNNING:                                          
                     if( direction == UP )
                            presentfloor++;
                           else
                            presentfloor--;
                           if(aimfloor == presentfloor) // reseting the order that has been fulfilled
                             {	
                             	if(direction == UP){								 
                              		inSide[aimfloor] = up[aimfloor] = 0;
                             	}else{
                              		inSide[aimfloor] = down[aimfloor] =0;
								}
                              state=STOP;
                            }
                           break;
       
               case STOP:      
                         if(aimfloor==0)  
                            state=PAUSE;

                        else if(aimfloor == presentfloor)
                            {
                              state=PAUSE;
                              up[presentfloor]=down[presentfloor]=down[aimfloor]=0;
                              aimfloor =0;
                             }
                        else
                            state=RUNNING;           
                        break;
             }
}

