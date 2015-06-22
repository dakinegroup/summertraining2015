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


int main (void) {
  int i = 0;
  //char userCommand[20];
  initTimer();
  USART_Init(51);
  USART_Transmit_String("Restarted: \r\n"); 
  USART_Transmit_String("System Initializing\r\n");
  initTimedTasks();
  initTrafficStateMachine();
  initCli();

  //schedule heartbeat type of events here
  repeat(1000, toggleDebugLed);
  /* get counters for incoming traffic at each pole*/
  repeat(800, checkTrafficStatus); 
  /* sequentially as per configured logic, lights should go on / off */
  repeat(260, processTrafficStateMachine);

  USART_Transmit_String2("System ready\r\n");
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