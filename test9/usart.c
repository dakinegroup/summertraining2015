#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdlib.h>


#define BUFFER_SIZE  100
#define EMPTY_THRESHOLD  10
volatile unsigned char tx_buffer[100];
volatile unsigned char tx_buffer_last_write = 0;
volatile unsigned char tx_buffer_last_read = 0;
volatile char tx_buffer_nearly_full = 0;
volatile char tx_buffer_empty = 1;

void USART_Init( unsigned int ubrr)
{
int i;
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/*Enable receiver and transmitter */
UCSR0B = UCSR0B | (1<<TXEN0) | (1<<RXEN0) ;
//| (1 << UDRIE0);
// | (1 << RXCIE0);
tx_buffer_last_write=0;
tx_buffer_last_read=0;
tx_buffer_nearly_full=0;
tx_buffer_empty=1;
for(i=0; i < BUFFER_SIZE; i++) {
	tx_buffer[i] = 0;
}
}

void USART_Transmit(unsigned char data) {
/* Wait for empty transmit buffer */
	int i;
while ( !( UCSR0A & (1<<UDRE0)) )
;
  
/* Put data into buffer, sends the data */
UDR0 = data;
}


void printByte(unsigned char p) {
	unsigned char c;
	c = (p >> 4) & 0x0f;
	if(c < 10) {
		USART_Transmit('0' + c);	
	} else {	
	USART_Transmit(c+'A'-10);			
		//USART_Transmit(getCharacter(c));		
	}
//	USART_Transmit(c < 10? ('0' + c) : getCharacter(c));
	c = p  & 0x0f;
	if(c < 10) {
		USART_Transmit('0' + c);	
	} else {
		USART_Transmit(c+'A'-10);		
		//USART_Transmit(getCharacter(c));		
	}
}



void USART_Transmit_String_P(const char *x) {
	int i = 0;
	char c;
	for(i=0; i < 100; i++) {
			//printByte(pgm_read_byte((char *)(0x0000 + i)));
		c = pgm_read_byte(&x[i]);
		if(c)
			USART_Transmit(c);
		else break;
	}
	USART_Transmit('\r');
	USART_Transmit('\n');
}

void USART_Transmit_Bytes_P() {
	int i = 0;
	char c;
	return;
	for(i=0; i < 100; i++) {
			//printByte(pgm_read_byte((char *)(0x0000 + i)));
		c = pgm_read_byte((char *)(0x05BA + i));
	    printByte(c);
	    USART_Transmit(' ');
	}
	USART_Transmit('\r');
	USART_Transmit('\n');
}

void USART_Transmit_String(char *x) {
	int i = 0;
	char c;
	for(i=0; i < 100; i++) {
		c = x[i];
		if(c)
			USART_Transmit(c);
		else break;
	}
	USART_Transmit('\r');
	USART_Transmit('\n');
}
void testFunction2(){
	int diff = 0;
	USART_Transmit_String("Value of..");
	printByte((tx_buffer_last_read & 0xff00) >> 8);
	printByte(tx_buffer_last_read & 0x00ff);
	printByte((tx_buffer_last_write & 0xff00) >> 8);
	printByte(tx_buffer_last_write & 0x00ff);

    if(tx_buffer_last_read != tx_buffer_last_write) {
      
      tx_buffer_empty = 0;
      USART_Transmit_String("Transmitting");
      //UDR0 = tx_buffer[tx_buffer_last_read];
      tx_buffer_last_read++;
      if(tx_buffer_last_read == BUFFER_SIZE) {
        tx_buffer_last_read = 0;
      }

      if(tx_buffer_last_read == tx_buffer_last_write) {
        tx_buffer_empty = 1;
      } else {
	       /* find difference between read and write pointers*/
	      if(tx_buffer_last_read < tx_buffer_last_write) {
	        diff = tx_buffer_last_write - tx_buffer_last_read;
	      } else {
	        diff = tx_buffer_last_write + BUFFER_SIZE - tx_buffer_last_read;
	      }

	      if((BUFFER_SIZE - diff) < EMPTY_THRESHOLD) {
	        tx_buffer_nearly_full = 1;
	      } else {
	        tx_buffer_nearly_full = 0;
	      }
      }
     } 	
}

ISR(USART_TX_vect)
{
	int diff = 0;
//	return;
  cli();
  if(tx_buffer_last_read < tx_buffer_last_write) {
  UDR0 = tx_buffer[tx_buffer_last_read];
  tx_buffer_last_read=tx_buffer_last_read+1;  	

  } else {
  	tx_buffer_last_read = 0;
  	tx_buffer_last_write= 0;
  }  /* if(tx_buffer_last_read != tx_buffer_last_write) {
      
      tx_buffer_empty = 0;
      UDR0 = tx_buffer[tx_buffer_last_read];
      tx_buffer_last_read++;
      if(tx_buffer_last_read == BUFFER_SIZE) {
        tx_buffer_last_read = 0;
      }

      if(tx_buffer_last_read == tx_buffer_last_write) {
        tx_buffer_empty = 1;
      } else {
	       // find difference between read and write pointers
	      if(tx_buffer_last_read < tx_buffer_last_write) {
	        diff = tx_buffer_last_write - tx_buffer_last_read;
	      } else {
	        diff = tx_buffer_last_write + BUFFER_SIZE - tx_buffer_last_read;
	      }

	      if((BUFFER_SIZE - diff) < EMPTY_THRESHOLD) {
	        tx_buffer_nearly_full = 1;
	      } else {
	        tx_buffer_nearly_full = 0;
	      }
      }
     } */           
  sei();
}
//ISR(USART_TX_vect, ISR_ALIASOF(USART_UDRE_vect));

int logs_dropped = 0;
int logs_truncated = 0;
void USART_Transmit_String2(char *x) {
	int diff,i=0;
/*     USART_Transmit_String(x);
*/ 	cli();
	for(i=0; i < 5; i++) {
		tx_buffer[i] = x[i];
	}
	UDR0 = tx_buffer[0];
	tx_buffer_last_read = tx_buffer_last_read + 1;
	sei();
	return;
	if(tx_buffer_nearly_full == 1)  {
		logs_dropped++;
	} else {
/*		USART_Transmit_String("condition check");
*/		while((x[i] != 0) && (i < 50)) {
			tx_buffer[tx_buffer_last_write] = x[i];
			tx_buffer_last_write++;
			if(tx_buffer_last_write == BUFFER_SIZE) {
				tx_buffer_last_write = 0;
			}
			i++;
/*			USART_Transmit_String("value of x..");
     USART_Transmit_String(x);
			USART_Transmit_String("value of txb..");
     USART_Transmit_String(tx_buffer);
*/			if(tx_buffer_last_write == tx_buffer_last_read) {
				logs_truncated ++;
				break;
			}
		}
		//tx_buffer_last_write = 5;
/*		printByte((tx_buffer_last_read & 0xFF00) >> 8);
		printByte(tx_buffer_last_read & 0x00FF);
*/
      if(tx_buffer_last_read < tx_buffer_last_write) {
        diff = tx_buffer_last_write - tx_buffer_last_read;
      } else {
        diff = tx_buffer_last_write + BUFFER_SIZE - tx_buffer_last_read;
      }
		if((BUFFER_SIZE - diff) < EMPTY_THRESHOLD) {
        	tx_buffer_nearly_full = 1;
      	} else {
        	tx_buffer_nearly_full = 0;
      	}
/*		printByte((tx_buffer_empty & 0xFF00) >> 8);
		printByte(tx_buffer_empty & 0x00FF);
*/		if(tx_buffer_empty) {
			tx_buffer_empty = 0;
			if( UCSR0A & (1<<UDRE0)) {	
				UDR0 = tx_buffer[tx_buffer_last_read];
/*      USART_Transmit_String("Transmitting1");
      USART_Transmit_String(tx_buffer);
      USART_Transmit_String((tx_buffer + tx_buffer_last_read));
*/				tx_buffer_last_read++;
				if(tx_buffer_last_read == BUFFER_SIZE) {
					tx_buffer_last_read = 0;
				}
			}
		}
   }
   sei();
}
void USART_Transmit_Bytes() {
	int i = 0;
	char c;
	return;
	/*for(i=0; i < 100; i++) {
			//printByte(pgm_read_byte((char *)(0x0000 + i)));
		c = *((char *)(0x0060 + i));
	    printByte(c);
	    USART_Transmit(' ');
	}
	USART_Transmit('\r');
	USART_Transmit('\n');*/
}

unsigned char USART_Receive_Byte() {
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

unsigned char* USART_Receive_String() {
	static char inputs[50];
	unsigned char i=0;;
	while(1) {
		if(i >= 49) {
			inputs[49] = 0;
			break;
		}
		while ( !( UCSR0A & (1<<RXC0)) )
;
//loop_until_bit_is_set(UCSR0A, );
		inputs[i] = UDR0;
		USART_Transmit(inputs[i]);
		if(!inputs[i] || inputs[i] == '\r' || inputs[i] == '\n') {
			inputs[i] = 0;
			break;
		}
		i++;
	}
	USART_Transmit_String("\r\n You have typed: ");
	//Issue: Here use of strcat("You have typed", inputs) had caused crash
	USART_Transmit_String(inputs);
	USART_Transmit_String("\r\n");
	return inputs;
}


