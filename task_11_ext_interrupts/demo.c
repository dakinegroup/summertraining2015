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
unsigned int gCounter1[] ={0,0,0};
unsigned char pinb_history = 0;

ISR(BADISR_vect) {
}

ISR(PCINT0_vect) {
  unsigned char chgBits;
  cli();
  chgBits = pinb_history ^ PINB;
  if(chgBits & (1 << 0)) {
    gCounter1[0]++;
  } else if(chgBits & (1 << 2)) {
    gCounter1[1]++;
  } else if (chgBits & (1 << 3)) {
    gCounter1[2]++;
  }
  pinb_history = PINB;
  sei();
  }




void ioinit() {
  USART_Init(MYUBRR); 
   /* set PORTB for output*/
    //DDRB = 0xFF;
    /* set PORTD for input*/
    DDRB &= ~(1 <<DDB3);
    PORTB |= (1 << DDB3);
    DDRB &= ~(1 << DDB2);
    PORTB |= (1 << DDB2);
    DDRB &= ~(1 << DDB0);
    PORTB |= (1 << DDB0);

    /* enable pin change interrupt */
    /* PIMSK */
   /* PCMSK2 |= _BV(PCINT23);
    PCMSK0 |= _BV(PCINT22);
    PCMSK0 |= _BV(PCINT21);*/
    PCMSK0 |= _BV(PCINT0);
    PCMSK0 |= _BV(PCINT2);
    PCMSK0 |= _BV(PCINT3);
    /* PC Interrupt enable */
    PCICR |= _BV(PCIE0);

  sei ();
}

#define HIGH 1
#define LOW 0

int
main (void)
{
  char msg[30];
  unsigned char c; int i=0;
  int counter[2];
  ioinit();
  USART_Transmit_String("Restarting..\r\n");
     while (1) {
         /*if (PINB & (1<<3))
             PORTB &= ~0x02;
         else
             PORTB |= 0x02;*/
           cli();
          counter[0] = gCounter1[0];
          counter[1] = gCounter1[1];
          counter[2] = gCounter1[2];
          sei();
        sprintf(msg, "Ctr:%04x, %04x, %04x\r\n", counter[0], counter[1],counter[2]);
        USART_Transmit_String(msg);
    }
    return 0;
}
