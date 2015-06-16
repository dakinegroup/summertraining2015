#define __AVR_ATmega328P__ 1
#include <avr/io.h>

inttmp  =       19

.section .data
    .global tx_buffer
    .type tx_buffer, @object
    .size   tx_buffer, 10
tx_buffer:
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    .byte 0

.section .text

        .global USART_RX_vect                 
USART_TX_vect:
        ;checkif UDRE0 is set
        ldi r30, lo8(UCSR0A)
        ldi r31, hi8(UCSR0A)
        ld r24, Z
        SBRS r24, UDRE0
        reti

        ;if set than
        ;write next byte
        ldi r30, lo8(UDR0)
        ldi r31, hi8(UDR0)
        st Z, R24
        reti

        .global USART_TX_vect                 
USART_RX_vect:

        reti