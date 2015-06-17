/*
*  Cables for programmer
* MISO - 3rd
* SCK - 2nd
* RST - 5th
* MOSI - 4th
* GND - 6th
* VCC - 1st
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <joerg@FreeBSD.ORG> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return. Joerg Wunsch
* ----------------------------------------------------------------------------
*
* Simple AVR demonstration. Controls a LED that can be directly
* connected from OC1/OC1A to GND. The brightness of the LED is
* controlled with the PWM. After each period of the PWM, the PWM
* value is either incremented or decremented, that's all.
*
* $Id: group__demo__project.html,v 1.1.1.23 2014/08/13 06:29:30 joerg_wunsch Exp $
*/
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include "usart.h"
#include "iocompat.h" /* Note [1] */
enum { UP, DOWN };
char * getBinaryString(unsigned int);
void runTrafficLight(/*unsigned int*/);
void shiftOutClockedData(unsigned int);

volatile unsigned char tx_buffer[100];
volatile unsigned char tx_buffer_last_write = 0;
volatile unsigned char tx_buffer_last_read = 0;

volatile unsigned char rx_buffer[100];
volatile unsigned char rx_buffer_last_write = 0;
volatile unsigned char rx_buffer_last_read = 0;

#include <avr/interrupt.h>

ISR(USART_RX_vect)
{
  rx_buffer[rx_buffer_last_write] = UDR0;
  rx_buffer_last_write++;
}
ISR(USART_UDRE_vect)
{
  //PORTB = PORTB | (_BV(0) | _BV(1) | _BV(2));
  /*if(tx_buffer_last_read < tx_buffer_last_write) {
    UDR0 = tx_buffer[tx_buffer_last_read];
    tx_buffer_last_read++;
  }
  if(tx_buffer_last_write == tx_buffer_last_read) {
    tx_buffer_last_read = tx_buffer_last_write = 0;
  }*/
}

ISR(USART_TX_vect, ISR_ALIASOF(USART_UDRE_vect));

ISR(BADISR_vect)
{
    // user code here
}
void ourDelay(unsigned int delay) {
	unsigned int x,y,z;
	for(x = 0; x < delay; x++) {
	    for(y = 0; y < 0x2; y++) {
		  for(z = 0; z < 0x40; z++) {
		  	asm("nop");
		  }
		}
	}
}
#define HIGH 1
#define LOW 0
int
main (void)
{
	unsigned int a=0x9114;
	unsigned char flag = 0;
//ioinit ();
DDROC = DDROC | _BV (OC1) | _BV(0) | _BV(DDB5) ;
DDRD = DDRD | _BV(DDD3);
//PORTB = _BV(0);
//PORTD = !_BV(PORTD3);
USART_Init(51); /* IMPORTANT: 41 values works with -mmcu=avr5, where it should have been */
/* IMPORTANT: 51 works with -mmcu=atmega328p, strange.. what is the secret here???*/

runTrafficLight(/*a*/);

/*shiftOutClockedData(0x0001);//red
ourDelay(5000);
shiftOutClockedData(0x0002);//yellow
ourDelay(5000);
shiftOutClockedData(0x0004);//green
ourDelay(5000);
shiftOutClockedData(0x0008);//left green
ourDelay(10000);


shiftOutClockedData(0x0010); //left green
ourDelay(5000);
shiftOutClockedData(0x0020); //green
ourDelay(5000);
shiftOutClockedData(0x0040); //yellow
ourDelay(5000);
shiftOutClockedData(0x0080); //red
ourDelay(10000);

shiftOutClockedData(0x0100); //red
ourDelay(5000);
shiftOutClockedData(0x0200); //yellow
ourDelay(5000);
shiftOutClockedData(0x0400); //green
ourDelay(5000);
shiftOutClockedData(0x0800); //left green
ourDelay(10000);


shiftOutClockedData(0x1000); //red
ourDelay(5000);
shiftOutClockedData(0x2000); //yellow
ourDelay(5000);
shiftOutClockedData(0x4000); //green
ourDelay(5000);
shiftOutClockedData(0x8000); //left green
ourDelay(10000);

for(;;) asm("nop");*/

PORTB = flag;
while(1) {
	ourDelay(1000);
flag=~flag;
PORTB = flag;
}
/* loop forever, the interrupts are doing the rest */
for (;;) /* Note [7] */
//sleep_mode();
/* if(PINB & 0x04) {
    PORTB = 0x01;
} else {
  PORTB = 0x00;
}*/
return (0);
}

char binaryString[50];
char * getBinaryString(unsigned int bytes) {
	int i = 0;
	for(;i<16; i++) {
		binaryString[i*2] =  ((bytes << i)&0x8000)?'1':'0';
		binaryString[i*2+1] = ' ';
	}
	binaryString[i*2] = 0;
	return &binaryString[0];
}

void digitalWrite(int pin, unsigned int state) {
  if(pin == 8) {
  	if(state) {
  		PORTD = PORTD | _BV(3);
  	} else {
  		PORTD = PORTD & ~(_BV(3));
  	}
  } else if(pin == 13) {
  	if(state) {
  		PORTB = PORTB | _BV(5);
  	} else {
  		PORTB = PORTB & ~(_BV(5));
  	}
  }
}

unsigned int digitalRead(int v) {
	return 1;
}

unsigned int reverseBits[16] = {0,8,4,0xC,2,0xA,6,0xE, 1, 9, 5, 0xD,3,0xB,7,15};
void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0,val=0;
     unsigned int chgByte = (dat1 & 0x00F0) ;
     if(chgByte == 0x10) {
     	dat1 = (dat1 & 0xFF0F) | 0x80;     	
     } else if (chgByte == 0x20) {
     	dat1 = (dat1 & 0xFF0F) | 0x40;     	
     } else if (chgByte == 0x40) {
     	dat1 = (dat1 & 0xFF0F) | 0x20;
     }

     unsigned int data = 0xFFFF - dat1;
    val=digitalRead(7);
    //Serial.println(val);
    if (val==1){
    for(i=0;i<16;i++) {
      digitalWrite(8, data & 0x01);
      data = data >>1;
      //ourDelay(500); 
      digitalWrite(13, HIGH); 
      //ourDelay(500); 
      digitalWrite(13, LOW); 
    }
    }else{digitalWrite(8,LOW);}
      //delay(10000);  
}
void runTrafficLight(/*unsigned int startingState*/) {
  /* main logic of traffic light shall work from here */
  int duration[2] = {2000, 500}; 
  char *inputUser;
  //int tick = 0;
  int i = 0, tState = 0;
  /* 0th pole is BIT:0-3, 1st pole: BIT:4-7, 2nd pole: BIT:8:11, 3rd pole: BIT:12:15*/
  unsigned int startingState = 0x9114;
   shiftOutClockedData(startingState);
do {
  //Serial.println("startingState");
  USART_Receive_String();
   for(i=0; i < 4; i ++) { /* go over all the traffic poles */
  USART_Transmit_String("next pole");
     /* which is green right now */
     /* first get the pole */
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) {/* Red is on */
     } else if(tState & 0x02) {/*Yellow is on*/
        ourDelay(duration[1]);
        startingState = (startingState & ~(0x0F << i*4)) | (0x04 << i*4) ;
        if(i == 0) {
         /* Glow yellow led for 0th pole*/
  USART_Transmit_String("glowing yellow");
       startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x09 << ((i+3)*4)) ;
       } else {
         /* Glow yellow led for next pole in sequence */
  USART_Transmit_String("glowing yellow 2");
         startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x09 <<( (i-1)*4)) ;
      }
        shiftOutClockedData(startingState);
      //printf("%0x",startingState);
     } else if(tState & 0x04) {/*Green is on */
       ourDelay(duration[0]);
       //after this delay switch off green, switch on red
  USART_Transmit_String("switch off green");
       startingState = (startingState & ~(0x0F << i*4)) | (0x01 << i*4) ;
       if(i == 0) {
         /* Glow yellow led for 4th pole*/
  USART_Transmit_String("and start yellow, next");
        	startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x02 << ((i+3)*4)) ;
       } else {
         /* Glow yellow led for next pole in sequence */
  USART_Transmit_String("and start yellow, next2");
         startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x02 << ((i-1)*4)) ;
       }
  shiftOutClockedData(startingState);
  //printf("%0x",startingState);
    } else if(tState & 0x08) {/* Left is on */
  USART_Transmit_String("left green is on");        
     }
   }  
  USART_Transmit_String("one round done !!\n\n\n");        
  USART_Transmit_String("\n");
  } while (1);
}
