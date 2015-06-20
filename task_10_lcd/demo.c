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
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "iocompat.h" /* Note [1] */
#include "usart.h"

#define FOSC 16000000UL // Clock Speed
#define BAUD 19200
#define MYUBRR FOSC/16/BAUD-1

enum { UP, DOWN };


ISR(BADISR_vect)
{
}

void ioinit() {
  USART_Init(MYUBRR); 
  sei ();
}

#define HIGH 1
#define LOW 0

void initLCD() {
  DDRD = DDRD | _BV(3) | _BV(4) |_BV(5) |_BV(6) ;
}

#define SR_SHCP 3
#define SR_STCP 6
#define SR_DS 5
#define LCD_EN 6

void sendShClockFallingEdge(){
  PORTD = PORTD | _BV(SR_SHCP);
  PORTD = PORTD & (~ _BV(SR_SHCP));
  PORTD = PORTD | _BV(SR_SHCP);
}
void sendStClockFallingEdge(){
  PORTD = PORTD | _BV(SR_STCP);
  PORTD = PORTD & (~ _BV(SR_STCP));
  PORTD = PORTD | _BV(SR_STCP);
}
void enableLCD() {
  PORTD = PORTD | _BV(LCD_EN);
  PORTD = PORTD & (~ _BV(LCD_EN));
  PORTD = PORTD | _BV(LCD_EN);
}
void sendDataToLCD(unsigned char data) {
    unsigned int i, bit;
    for(i=0;i<8;i++) { 
    /* though only 4bits are relevant, lets do it all */
      /* extract bit */
      bit = data & 0x01;

      if(bit) 
        PORTD = PORTD | _BV(SR_DS);
      else
        PORTD = PORTD & (~ _BV(SR_DS));    
      /* time to clock it in */
      sendShClockFallingEdge();
      /* next bit */
      data = data >>1;
    }
    
    /* now move out data to output register */
    sendStClockFallingEdge();
    /* now let it be registered by LCD */
    enableLCD();
}
/*
  Green on the cable is 1
  On board, where first green is seen that side is towards pin 1 of connector

|Connector | 328 Pins  |  595 pins  | LCD Pins|
|----------|-----------|------------|---------|
|1 (Green) |  1/RESET  |  10/MR#    |    x    |
|----------|-----------|------------|---------|
|     2    |    5/PD3  |   11/SHCP  |    x    |
|----------|-----------|------------|---------|
|     3    |     6/PD4 |   12/STCP  |         |
|----------|-----------|------------|---------|
|     4    |   11/PD5  |   14/DS    |         |
|----------|-----------|------------|---------|
|     5    |    12/PD6 |      x     |   E     |
|----------|-----------|------------|---------|
|6 (Black) |  13/PD7   |      x     |         |
|----------|-----------|------------|---------|
|     x    |    x      |      1/Q1  |   D4    |
|----------|-----------|------------|---------|
|     x    |    x      |      2/Q2  |   D5    |
|----------|-----------|------------|---------|
|     x    |    x      |      3/Q3  |   D6    |
|----------|-----------|------------|---------|
|     x    |    x      |      4/Q4  |   D7    |
|----------|-----------|------------|---------|
|     x    |    x      |      5/Q5  |  RS     |   
|----------|-----------|------------|---------|
|     x    |    x      |      x     |RW to GND|     
|----------|-----------|------------|---------|
|     x    |    x      |  OE#to GND |    x    |
|----------|-----------|------------|---------|

To give command to LCD
     BITs --->
Data at 595:    x x x 0 A B C D
Data at PD5:    00 - 0F (command)
Data at PD3:    clock to put it in input shift
Data at PD4:    high and low, to transfer out
Data at PD6:    high and low, to transfer to LCD

To give data to LCD
Data at 595:    x x x 1 A B C D
Data at PD5:    00 - 0F (data)
Data at PD3:    same as above
Data at PD4:    same as above
Data at PD6:    same as above

To give data to shift register
*/

int
main (void)
{
  ioinit ();
  USART_Transmit_String("Restarting..."); 
  USART_Transmit_String("Version to do testing of LCD write");
  USART_Transmit_String("Welcome to DKT - Embedded!!");
  initLCD();
  while(1) {
    asm("nop");
  }
  return (0);
}
