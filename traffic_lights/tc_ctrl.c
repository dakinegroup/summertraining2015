/* File: tc_ctrl.c
 * Copyright (C) da Kine Technologies (P) Ltd. - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vineet Maheshwari <vineet@dakinegroup.com>, June 2015
 * Revision History
 * Date        Ticket   Change Note
 * -----------------------------------
 * 
 */
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "iocompat.h"
#include "tc_ctrl.h"
#include "light_driver.h"

#define CLEAR_POLE(i) (startingState & ~(0x0F << (i%4)*4))

#define RED_ON_POLE(i)  (CLEAR_POLE(i) | (0x01 << (i%4)*4))
#define YELLOW_ON_POLE(i) (CLEAR_POLE(i) | (0x02 << ((i%4)*4)))
#define GREEN_ON_POLE(i) (CLEAR_POLE(i) | (0x04 << ((i%4)*4)))
#define LEFT_GREEN_ON_POLE(i) (CLEAR_POLE(i) | (0x09 << ((i%4)*4)))

unsigned int startingState;
unsigned int tick;
void initTraffiStateMachine() {
DDROC = DDROC | _BV (OC1) | _BV(0) | _BV(DDB5) ;
DDRD = DDRD | _BV(DDD2);
    startingState = 0x9114;
    shiftOutClockedData(startingState);
    tick = 0;
}
int processTrafficStateMachine(int x) {
static int  i;
static unsigned int tState;
static int duration[]= {5,4,8};     
char msg[20];

    tick++;
    USART_Transmit_String2("Tick");  
   for(i=0; i < 4; i ++) { 
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) { /* red light */
       
     } else if(tState & 0x02) { /* yellow light */
          if (tick>=duration[1]) {
            USART_Transmit_String2("Yellow->Green");
    // sprintf(msg,"P#%d,Time:%d,Dur:%d, Yellow", i, tick, duration[1]);
    //USART_Transmit_String2(msg);  
            /* wait for duration of yellow light is over */
            /* move this pole to red light */
             startingState = GREEN_ON_POLE(i) ;
            /* restart counter */
             tick=0;
             /* glow left green on the next pole */
                startingState = LEFT_GREEN_ON_POLE(i-1) ;
    // sprintf(msg,"SS:%0x4d", startingState);
             
            /*printf("set duration for green light");
            scanf("%d",&glt);
            duration[2]=glt;*/

            shiftOutClockedData(startingState);
          }
     } else if(tState & 0x04) { /* green light */
            /*printf("enter sleep time\n");
            scanf("%d",&st); */

            /* Checking for the incoming traffic on other two poles */
            /*
           do
                  {
                    usleep(st);
                    counter++;
                    ctr1=counter;
                    tick++;
                  }while(counter<((duration[2]*1000000)/st));
                  printf("%ld\n",ctr1);
                  counter=0;
                   printf("enter sleep time2\n");
                  scanf("%d",&st); 
                  do
                  {
                    usleep(st);
                    counter++;
                    ctr2=counter;
                    
                    tick++;
                  }while(counter<((duration[2]*1000000)/st));
                  printf("%ld\n",ctr2);
                  counter = 0;
            */
        if (tick >= duration[2]) {
            USART_Transmit_String2("Green->Red");
    // sprintf(msg,"P#%d,Time:%d,Dur:%d, Green", i, tick, duration[2]);
    //USART_Transmit_String2(msg);  
            /* wait for green light is over */
          startingState = RED_ON_POLE(i);
          startingState = YELLOW_ON_POLE(i+1);
          startingState = RED_ON_POLE(i-1);
    // sprintf(msg,"SS:%0x4d", startingState);
          tick=0;
          shiftOutClockedData(startingState);
        } else if(tState & 0x08) {
        
        }
     }
   }
}

int checkTrafficStatus(int i) {
  // check traffic status / volume and make changes
}