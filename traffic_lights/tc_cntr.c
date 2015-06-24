/* File: tc_cntr.c
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
#include "tc_cntr.h"

#define FOSC 16000000UL // Clock Speed
#define BAUD 19200
#define MYUBRR FOSC/16/BAUD-1

enum { UP, DOWN };
unsigned int gCounter[]={0,0,0,0};
ISR(BADISR_vect) {
}

ISR(PCINT2_vect) {
  cli();
   gCounter[0]++;
  sei();
}
unsigned char pinb_history;
ISR(PCINT0_vect) {
unsigned char chgBits=0;
  cli();
  chgBits = pinb_history ^ PINB;
  if(chgBits & (1 << 0)) {
    gCounter[1]++;
  } else if (chgBits & (1 << 2)) {
    gCounter[2]++;
  } else if (chgBits & (1 << 3)) {
    gCounter[3]++;
  } 
  pinb_history = PINB;
  sei();

}
void initTrafficCounters() {
    /* set PORTB for output*/
    DDRB = 0xFF;
    /* set PORTD for input*/
    DDRD  &= ~(1 << 7);
    PORTD |= (1 << 7);
    DDRB &= ~(_BV(0)|_BV(2) | _BV(3));
    PORTB |= (_BV(0)|_BV(2) | _BV(3));
     /* enable pin change interrupt */
    /* PIMSK */
    PCMSK2 |= _BV(PCINT23);
    PCMSK0 |= _BV(PCINT0);
    PCMSK0 |= _BV(PCINT2);
    PCMSK0 |= _BV(PCINT3);
    /* PC Interrupt enable */
    PCICR |= _BV(PCIE2);
    PCICR |= _BV(PCIE0);
     sei ();
}
#define HIGH 1
#define LOW 0

int readCounter(int ctr) {
	 char msg[10];int i=0,counter;
	 initTrafficCounters();
    /*while (1) {
        if (PIND & 0x80)
            PORTB &= ~0x02;
        else
            PORTB |= 0x02;*/
          cli();
          counter = gCounter[ctr];
          sei();
        
    return counter;

}
void resetCounter(int ctr){
	cli();
	gCounter[ctr]=0;
	sei();

}


