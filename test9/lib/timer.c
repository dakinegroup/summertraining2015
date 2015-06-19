
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "mytimer.h"


unsigned int timestamp[2] = {0,0};
unsigned char debug_led = 0;

void initTimer() {
  TIMSK1 = TIMSK1 | _BV(TOIE1);
  TCCR1B = (TCCR1B & 0xF8) | 0x01;
  DDRB = DDRB | _BV(DDB1);
  PORTB = PORTB & ~(_BV(1));
  debug_led = 0;
}
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
