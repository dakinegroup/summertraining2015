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
#include "mytimer.h"
#include "adc.h"

#define FOSC 16000000UL // Clock Speed
#define BAUD 19200
#define MYUBRR FOSC/16/BAUD-1

#define DEBUG_TIMER2_LED 0


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
  
  sei ();
}

#define TIMER0_TOP 200
ISR(TIMER0_OVF_vect) {
static unsigned int pwm = 0;
static uint8_t direction;
  cli();
  switch (direction) {
  case UP:
    if (++pwm == TIMER0_TOP)
      direction = DOWN;
    break;
  case DOWN:
    if (--pwm == 0)
      direction = UP;
    break;
  }
  OCR0A = pwm;
  sei();
}



int debug_led_timer2 = 0;
unsigned int timestamp[2] = {0,0};
unsigned int topup_timer2 = 0;
ISR(TIMER2_OVF_vect) {
  cli();
  topup_timer2++;
  if((topup_timer2 & 0x01F) == 0) {
    topup_timer2 = 0;
    timestamp[0] ++;
    if(timestamp == 0) {
      timestamp[1] ++;
    }
    if(debug_led_timer2  == 0) {
      topup_timer2 = 0;
      debug_led_timer2 = 0x01;
      PORTB = PORTB | _BV(1);
    } else {
      debug_led_timer2 = 0;
      PORTB = PORTB & ~(_BV(1));
    }
  }
  sei();
}


void initTimer2() {
  //TCCR0A

  //TCCR0B
  //CS02:0 = 0x01 -> divide by 16
  TCCR2B |= _BV(CS20) | _BV(CS21);
/* Enable timer 0 overflow interrupt. */
TIMSK2 |= _BV (TOIE2);

#ifdef DEBUG_TIMER2_LED
  DDRB = DDRB | _BV(DDB1);
  PORTB = PORTB & ~(_BV(1));
  debug_led_timer2 = 0;
#endif
}

#define HIGH 1
#define LOW 0


void wait(int ms) {
unsigned int ts[2], t[2];
    cli();
            ts[0] = timestamp[0];
            ts[1] = timestamp[1];
    sei();
    if((0xFFFF - ts[0]) < ms) {
        ts[1] += 1;
    } 
    ts[0] += ms;
 while(1) {
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    cli();
            t[0] = timestamp[0];
            t[1] = timestamp[1];
    sei();
    if(ts[1] > timestamp[1]) {
    } else if(ts[1] == timestamp[1]) {
        if(ts[0] > timestamp[0]) {

        } else {
            break; //time up
        }
    }
 }    
}

int
main (void)
{
  char msg[30];
  unsigned char c; int i=0;
  int counter[3];
ioinit();
  //initTimer();
  initTimer2();
  initPWM();
  initLCD();
  //initPWM();
  USART_Transmit_String("Restarting..\r\n");
        wait(10);
    //LCD_gotoXY(1,0);
    //LCD_Write("Out-PWM-BC1");
     while (1) {
      unsigned int en, en1;
      asm("nop");
      cli();
       en = topup_timer2;
       en1 = timestamp[0];
      sei();
      sprintf(msg, "%04x,%04x", en, en1);
      USART_Transmit_String(msg);
      LCD_gotoXY(0,0);
      LCD_Write(msg);
    }
    return 0;
}
