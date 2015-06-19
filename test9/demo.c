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
#include "iocompat.h" /* Note [1] */

#define FOSC 16000000UL // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

unsigned char debug_led = 0;
enum { UP, DOWN };

unsigned int timestamp[2] = {0,0};

#include <avr/interrupt.h>

 

ISR(TIMER1_OVF_vect)
{
  cli();
 //     PORTB = PORTB | _BV(1);
  timestamp[0] ++;
  if(timestamp == 0) {
    timestamp[1] ++;
  }
  if((timestamp[0] & 0x002F) == 0) {
    if(debug_led == 0) {
      debug_led = 0x01;
      PORTB = PORTB | _BV(1);
    } else {
      debug_led = 0;
      PORTB = PORTB & ~(_BV(1));
    }
  }
  sei();
}


ISR(BADISR_vect)
{
    // user code here
}

void ioinit() {
DDRB = DDRB | _BV(DDB1);
PORTB = PORTB & ~(_BV(1));
//PORTB = PORTB | _BV(1);
debug_led = 0;

USART_Init(51); /* IMPORTANT: 41 values works with -mmcu=avr5, where it should have been */
/* IMPORTANT: 51 works with -mmcu=atmega328p, strange.. what is the secret here???*/
TCCR1B = (TCCR1B & 0xF8) | 0x01;
TIMSK1 = TIMSK1 | _BV(TOIE1);
sei ();
}

#define HIGH 1
#define LOW 0
extern char tx_buffer[];
extern char tx_buffer_last_write;
int
main (void)
{
  int i;
  unsigned int readValue[2];
  ioinit ();
//USART_Transmit_String("Restarted: "); 
UDR0 = 'A';
UCSR0B = UCSR0B |  (1 << TXCIE0) ;//|(1 << UDRIE0);

USART_Transmit_String2("Thsi is a test..");
for(i = 0;i < 30000; i++) {
  asm("nop");
}
UDR0 = 'A';

USART_Transmit_String2("How are you???");
//UDR0 = 'A';
   //  USART_Transmit_String2("TimeValue: "); 

     /*testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");
     testFunction();
     USART_Transmit_String("\r\n");*/
 while(1) {
  asm("nop");
    //cli();
    //readValue[0] = timestamp[0];
    //readValue[1] = timestamp[1];
    //sei();
    /*printByte((readValue[1] & 0xFF00)>>8); 
    printByte(readValue[1] & 0x00FF); 
    printByte((readValue[0] & 0xFF00)>>8); 
    printByte(readValue[0] & 0x00FF);*/ 
  }

  return (0);
}
