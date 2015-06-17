#define FOSC 16000000UL // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdlib.h>
extern unsigned char* tx_buffer;
extern unsigned char tx_buffer_last_write;
extern unsigned char tx_buffer_last_read;

void USART_Init( unsigned int ubrr)
{
/*if(!ubrr) {
	ubrr = 104;
}*/
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/*Enable receiver and transmitter */
UCSR0B = UCSR0B | (1<<TXEN0) | (1<<RXEN0);

sei ();
//cli();
//UCSR0B = UCSR0B | _BV(UDRIE0) | _BV(TXCIE0) |_BV(RXCIE0) ;

/*strcpy(tx_buffer, "this is a test");
tx_buffer_last_write = 15;
tx_buffer_last_read = 0;
UDR0 = 'A';*/
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
	static unsigned char i=0;;
	while(1) {
		while ( !( UCSR0A & (1<<RXC0)) )
;
//loop_until_bit_is_set(UCSR0A, );
		inputs[i] = UDR0;
		USART_Transmit(inputs[i]);
		if(!inputs[i] || inputs[i] == '\r' || inputs[i] == '\n') {
			break;
		}
		i++;
	}
	USART_Transmit_String("\r\n");
	USART_Transmit_String(strcat("You have typed: ",inputs));
	USART_Transmit_String("\r\n");
	return inputs;
}
