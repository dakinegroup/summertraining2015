#define __AVR_ATmega328P__
#include <avr/io.h>
#include <avr/interrupt.h>

inttmp  =       19

.section .data
    .global tx_buffer
    .type tx_buffer, @object
tx_buffer:
    .space 100

    .global tx_buffer_data_length
tx_buffer_data_length: 
    .byte 1

.section .text

        .global USART_RX_vect     
    .org 0x28
rjmp USART_TX_vect

USART_TX_vect:
        reti
        sbi _SFR_IO_ADDR(PORTB), 0
;checkif UDRE0 is set, if not return back
        ldi r30, lo8(UCSR0A)
        ldi r31, hi8(UCSR0A)
        ld r24, Z
        SBRS r24, UDRE0
        reti

;if set than
;write next byte
        ldi r30, lo8(UDR0)
        ldi r31, hi8(UDR0)
        ldi r28, lo8(tx_buffer)
        ldi r29, hi8(tx_buffer)
        ld r24, Y        
        st Z, R24

; decrease data length, check for zero value
       ldi r28, lo8(tx_buffer_data_length)
        ldi r29, hi8(tx_buffer_data_length)
        ld r24, Y
        tst r24
        breq zero
        dec r24       
        st Y, r24
zero:
        reti

        .global USART_TX_vect                 
USART_RX_vect:

        reti