/* File: tc_main.c
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
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include "usart.h"
#include "mytimer.h"
#include "iocompat.h" 
#include "tc_ctrl.h"
 #include "tc_cntr.h"
#include "lcd.h"
#include "tc_cli.h"
 

int toggleDebugLed(int x) {
    if(debug_led == 0) {
      debug_led = 0x01;
      PORTB = PORTB | _BV(1);
    } else {
      debug_led = 0;
      PORTB = PORTB & ~(_BV(1));
    }
    return 0;

}
int printCounters(int x) {
  int counter,i;
  char msg[20];
      LCD_gotoXY(1,0);
    for(i=0;i<4;i++){
      counter = readCounter(i);
      sprintf(msg, "%03x:", counter);
      USART_Transmit_String2(msg);
      LCD_Write(msg);
   }
   USART_Transmit_String2("\r\n");
}
int printTrafficStatus(int x) {
  int i;
  LCD_gotoXY(0,0);
  for(i=3; i >= 0; i--) {
    int st = (startingState >>i*4) & 0x000F;
    if(st == 0x09) {
      LCD_Write("Lft:");
    } else if(st==0x04) {
      LCD_Write("Grn:");
    } else if(st == 0x02) {
      LCD_Write("Ylw:");
    } else if(st == 0x01) {
      LCD_Write("Red:");
    }
  }
}

int main (void) {
  int i = 0;
  char iteration[6];
  unsigned char pin;
  //char userCommand[20];
  initTimer();
  USART_Init(51);
  USART_Transmit_String("Restarted: \r\n"); 
  //USART_Transmit_String("System Initializing\r\n");
  initTimedTasks();
  initTrafficStateMachine();
  initCli();
  initLCD();

  initTrafficCounters();
  
  //schedule heartbeat type of events here
  repeat(1000, toggleDebugLed);
  /* get counters for incoming traffic at each pole*/
  repeat(800, checkTrafficStatus); 
  /* sequentially as per configured logic, lights should go on / off */
  repeat(260, processTrafficStateMachine);
  repeat(500, printCounters);
  repeat(500, printTrafficStatus);
  USART_Transmit_String2("System ready\r\n");
  LCD_Write("Restarting...");
  LCD_WriteXY(1,0,"Greetings!");
  LCD_WriteXY(1,0,"Traffic Console");
  wait(200);
  LCD_Clear();
   LCD_GotoHome();
  
   LCD_WriteXY(0,0,"Count: ");
  // loop and check for various flags
  while(1) {
    asm("nop");
    invokeScheduledItem(); // includes - TL update, HeartBeat
    if(USART_Receive_String2(userCommand, 30) > 0) {
      processUserCommand(userCommand);
    }
    
      // ... check for scheduled events
      // ......glow an led, switch off led
      // ... check for user command from terminal
      // ... check for change in input from configuration
      // ... update user information on LCD display
      // ... check for user inputs from three keys
    }
}