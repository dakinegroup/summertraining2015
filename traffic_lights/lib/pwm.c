#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"

static unsigned int pwm = 0;
static pwm_width = 0;
static pwm_demo = 0;
enum { UP, DOWN };

ISR(TIMER1_OVF_vect) {
static uint8_t direction;
  cli();
  if(pwm_demo) {

  switch (direction) {
  case UP:
    if (++pwm == 1023)
      direction = DOWN;
    break;
  case DOWN:
    if (--pwm == 0)
      direction = UP;
    break;
  }
  OCR1A = pwm;
  } else {
    OCR1A = pwm_width;
  }
  sei();
}

void initPWM() {
  //TCCR0A
  // COM0A1:0 10 --> OC0A clear on match
  // WGM01:0  11 --> Fast PWM mode
  TCCR1A |= _BV(COM1A1) | _BV(WGM11) | _BV(WGM10);

  //TCCR0B
  //CS02:0 = 0x01 -> full clock no prescaling
  TCCR1B |= _BV(CS10);
// require to set output direction for Port B/B1
  DDRB = DDRB | _BV(DDB1);
/* Enable timer 0 overflow interrupt. */
TIMSK1 |= _BV (TOIE1);
OCR1A = 0;
pwm_demo = 1;
}

void setPWMWidth(int x) {
  cli();
  pwm_width = x;
  sei();
}