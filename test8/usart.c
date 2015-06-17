#define FOSC 16000000UL // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
extern unsigned char* tx_buffer;
extern unsigned char* tx_buffer_last_write;
extern unsigned char* tx_buffer_last_read;

void USART_Init( unsigned int ubrr)
{
/*if(!ubrr) {
	ubrr = 104;
}*/
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/*Enable receiver and transmitter */
UCSR0B = (1<<TXEN0) ;
//| (1<<RXEN0);

asm("sei");
/*UCSR0B = _BV(UDRIE0);*/
UCSR0B = UCSR0B | _BV(UDRIE0) ;
//UDR0 = 'A';

strcpy(tx_buffer, "this is a test");
tx_buffer_last_write = tx_buffer + 15;
tx_buffer_last_read = tx_buffer;
UDR0 = 'A';
while(1) asm("nop");
//UCSR0B = UCSR0B | (1 << RXCIE0);
/* Set frame format: 8data, no parity, 1stop bit */
//UCSR0C = (3<<UCSZ00);
}

void USART_Transmit(unsigned char data) {
/* Wait for empty transmit buffer */
	int i;
while ( !( UCSR0A & (1<<UDRE0)) )
;
/* Put data into buffer, sends the data */
UDR0 = data;
}
//static char hexb[] = {'A', 'B', 'C', 'D', 'E', 'F','-','+'};


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
	for(i=0; i < 100; i++) {
			//printByte(pgm_read_byte((char *)(0x0000 + i)));
		c = pgm_read_byte((char *)(0x05BA + i));
	    printByte(c);
	    USART_Transmit(' ');
	}
	USART_Transmit('\r');
	USART_Transmit('\n');
}

void USART_Transmit_Bytes() {
	int i = 0;
	char c;
	for(i=0; i < 100; i++) {
			//printByte(pgm_read_byte((char *)(0x0000 + i)));
		c = *((char *)(0x0060 + i));
	    printByte(c);
	    USART_Transmit(' ');
	}
	USART_Transmit('\r');
	USART_Transmit('\n');
}
