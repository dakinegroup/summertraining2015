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
int incomingTraffic[]={10,10,10,10};

enum { UP, DOWN };
//unsigned int incomingTraffic[]={0,0,0,0};
ISR(BADISR_vect) {
}

ISR(PCINT2_vect) {
  cli();
   incomingTraffic[0]++;
  sei();
}

unsigned char pinb_history=0;


ISR(PCINT0_vect) {
unsigned char chgBits=0;
  cli();
  chgBits = pinb_history ^ PINB;
  if(chgBits & (1 << 0)) {
    incomingTraffic[1]++;
  } else if (chgBits & (1 << 2)) {
    incomingTraffic[2]++;
  } else if (chgBits & (1 << 3)) {
    incomingTraffic[3]++;
  } 
  pinb_history = PINB;
  sei();
}
void initTrafficCounters() {
    /* set PORTD for input*/
    DDRD  &= ~(1 << 7);
    PORTD |= (1 << 7);

    DDRB &= ~(1 << DDB3);
    PORTB |= (1 << DDB3);
    DDRB &= ~(1 << DDB2);
    PORTB |= (1 << DDB2);
    DDRB &= ~(1 << DDB0);
    PORTB |= (1 << DDB0);

/*    DDRB &= ~(_BV(0)|_BV(2) | _BV(3));
    PORTB |= (_BV(0)|_BV(2) | _BV(3));
*/     /* enable pin change interrupt */
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
	 int counter;
          cli();
          counter = incomingTraffic[ctr];
          sei();
        
    return counter;

}
void resetCounter(int ctr){
	cli();
	incomingTraffic[ctr]=0;
	sei();

}

int resetAllCounters(int x ) {
	int i;
	cli();
	for(i=0; i < 4; i++) {
		incomingTraffic[i] = 0;
	}
	sei();
}


