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
#include "lcd.h"

#define FOSC 16000000UL // Clock Speed
#define BAUD 19200
#define MYUBRR FOSC/16/BAUD-1


enum { UP, DOWN };

ISR(BADISR_vect) {
}

void ioinit() {
  USART_Init(MYUBRR); 
  initTimer();
  DDRD &=  ~(1 << DDD7);
  PORTD |=  (1 << DDD7);
  sei ();
}

#define HIGH 1
#define LOW 0

int
main (void)
{
  int i;    
  char iteration[6];
  unsigned char pin;
  ioinit ();
  USART_Transmit_String("Restarting..."); 
  USART_Transmit_String("Version to do testing of LCD write");
  USART_Transmit_String("Welcome to DKT - Embedded!!");
  USART_Transmit_String("Waiting for LCD to come up..");
  USART_Transmit_String("LCD Ready now..");
  initLCD();
  /*
  goto home without consideration to prev written text
  move relative number of positions
  move to home without clearing contents
  move cursor up and down with key
  scroll screen up
  maintain last cursor
  switch of cursor
  switch on cursor
  switch off display
  goto address
  switch off usart logs
  */
  LCD_Write("Restarting...");
  LCD_WriteXY(1,0,"Greetings!");
  LCD_WriteXY(1,0,"Traffic Console");

   wait(200);
   LCD_Clear();
   LCD_GotoHome();
  i=0;
   LCD_WriteXY(1,0,"Count: ");
  while(1) {
   pin = PIND & (1 << 7);
   sprintf(iteration, "%05d, %02x",i++, pin);

   //LCD_Clear();
   //LCD_gotoXY(0,0);
  // LCD_Write("Testing in progress.. ");
  // LCD_WriteXY(1,0,"Please don't touch");
   wait(5);
  // LCD_WriteXY(1,0,"Count: ");
   LCD_WriteXY(1,7,iteration);
   wait(200); 
  }
  return (0);
}
