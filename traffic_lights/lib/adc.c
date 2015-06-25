/* File: adc.c
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

#include "adc.h"
void initADC() {
  //ADMUX
  // REFS1:0 = 00, AREF, internal Vref turned off
  //ADLAR = 0,Right adjust result, default
  //MUX0:3, 101, ADC5 being used
  ADMUX = 0x05;
  //ADCSRA
  //ADEN = 1, adc enabled
  //ADSC = 1, start conversion
  //ADATE = 1
  //ADIF = NA
  //ADIE = 1, interrupt enable
  //ADPS0:2 = 3, divide by 8 prescaler
  ADCSRA = 0xEF;
  // with timer1 overflow interrupt
  ADCSRB = 0x06;
}

unsigned int analog_input = 0;
ISR(ADC_vect) {
  cli();
  analog_input = ADCL;
  analog_input |= (ADCH << 8);
  sei();
}

int ADC_getReading() {
  int i=0;
        cli();
        i = analog_input;
        sei();
  return i;
}

void ADC_selectChannel(int ch) {
  ADMUX = ch;
}