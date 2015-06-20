#include <stdio.h>

char getCharacter(unsigned char c) {
	switch(c) {
		case 0x0A: return 'A';
		case 0x0B: return 'B';
		case 0x0C: return 'C';
		case 0x0D: return 'D';
		case 0x0E: return 'E';
		case 0x0F: return 'F';
		default: return '*';
	}
}
USART_Transmit(char c) {
	putchar(c);
}
void printByte(unsigned char p) {
	unsigned char c;
	c = (p >> 4) & 0x0f;
	USART_Transmit(c < 10? ('0' + c) : getCharacter(c ));
	c = p  & 0x0f;
 	USART_Transmit(c < 10? ('0' + c) : getCharacter(c ));
}

void main(void) {
     printByte(0x3A);
     printByte(100);
}

