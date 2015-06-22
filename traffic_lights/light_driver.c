/* File: light_driver.c
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
#include "iocompat.h"
#include "light_driver.h"
void digitalWrite(int pin, unsigned int state) {
  if(pin == 8) {
    if(state) {
        PORTD = PORTD | _BV(2);
    } else {
        PORTD = PORTD & ~(_BV(2));
    }
  } else if(pin == 13) {
    if(state) {
        PORTB = PORTB | _BV(5);
    } else {
        PORTB = PORTB & ~(_BV(5));
    }
  }
}
void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0,val=0;
     char msg[10];

     unsigned int chgByte = (dat1 & 0x00F0) ;
         
     if(chgByte == 0x10) {
        dat1 = (dat1 & 0xFF0F) | 0x80;      
     } else if (chgByte == 0x20) {
        dat1 = (dat1 & 0xFF0F) | 0x40;      
     } else if (chgByte == 0x40) {
        dat1 = (dat1 & 0xFF0F) | 0x20;
     }

     unsigned int data = 0xFFFF - dat1;
    //val=digitalRead(7);
    //Serial.println(val);
    //if (val==1){
    for(i=0;i<16;i++) {
      digitalWrite(8, data & 0x01);
 /*     USART_Transmit_String("step1");
    while (USART_Receive_String2(msg,10)<=0)
      asm("nop");
  */    data = data >>1;
      //ourDelay(500); 
      digitalWrite(13, HIGH); 
/*      USART_Transmit_String("step2");
    while (USART_Receive_String2(msg,10)<=0)
      asm("nop");
*/      //ourDelay(500); 
      digitalWrite(13, LOW); 
/*      USART_Transmit_String("step3");
    while (USART_Receive_String2(msg,10)<=0)
      asm("nop");*/
    }
    //}else{digitalWrite(8,LOW);}
/*    USART_Transmit_String("end");
    while (USART_Receive_String2(msg,10)<=0)
      asm("nop");
*/      //delay(10000);  
}