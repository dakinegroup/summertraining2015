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
