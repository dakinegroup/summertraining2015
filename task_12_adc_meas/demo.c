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

#define HIGH 1
#define LOW 0

int
main (void)
{
  char msg[30];
  unsigned char c; int i=0;
  int counter[3];
  ioinit();
  initTimer();
  initADC();
  initLCD();
  USART_Transmit_String("Restarting..\r\n");
     while (1) {
      i = ADC_getReading();
        sprintf(msg, "Meas: %04x\r\n", i);
        USART_Transmit_String(msg);
        LCD_gotoXY(1,0);
        LCD_Write(msg);
    }
    return 0;
}
