
demo.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 7d 00 	jmp	0xfa	; 0xfa <__ctors_end>
   4:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
   8:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
   c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  10:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  14:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  18:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  1c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  20:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  24:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  28:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  2c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  30:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  34:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  38:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  3c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  40:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  44:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  48:	0c 94 0d 03 	jmp	0x61a	; 0x61a <__vector_18>
  4c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  50:	0c 94 04 03 	jmp	0x608	; 0x608 <__vector_20>
  54:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  58:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  5c:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  60:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>
  64:	0c 94 9a 00 	jmp	0x134	; 0x134 <__bad_interrupt>

00000068 <__c.1746>:
  68:	0a 00                                               ..

0000006a <__c.1740>:
  6a:	6f 6e 65 20 72 6f 75 6e 64 20 64 6f 6e 65 20 21     one round done !
  7a:	21 0a 0a 0a 00                                      !....

0000007f <__c.1734>:
  7f:	6c 65 66 74 20 67 72 65 65 6e 20 69 73 20 6f 6e     left green is on
	...

00000090 <__c.1732>:
  90:	61 6e 64 20 73 74 61 72 74 20 79 65 6c 6c 6f 77     and start yellow
  a0:	2c 20 6e 65 78 74 32 00                             , next2.

000000a8 <__c.1730>:
  a8:	61 6e 64 20 73 74 61 72 74 20 79 65 6c 6c 6f 77     and start yellow
  b8:	2c 20 6e 65 78 74 00                                , next.

000000bf <__c.1728>:
  bf:	73 77 69 74 63 68 20 6f 66 66 20 67 72 65 65 6e     switch off green
	...

000000d0 <__c.1726>:
  d0:	67 6c 6f 77 69 6e 67 20 79 65 6c 6c 6f 77 20 32     glowing yellow 2
	...

000000e1 <__c.1724>:
  e1:	67 6c 6f 77 69 6e 67 20 79 65 6c 6c 6f 77 00        glowing yellow.

000000f0 <__c.1722>:
  f0:	6e 65 78 74 20 70 6f 6c 65 00                       next pole.

000000fa <__ctors_end>:
  fa:	11 24       	eor	r1, r1
  fc:	1f be       	out	0x3f, r1	; 63
  fe:	cf ef       	ldi	r28, 0xFF	; 255
 100:	d8 e0       	ldi	r29, 0x08	; 8
 102:	de bf       	out	0x3e, r29	; 62
 104:	cd bf       	out	0x3d, r28	; 61

00000106 <__do_copy_data>:
 106:	11 e0       	ldi	r17, 0x01	; 1
 108:	a0 e0       	ldi	r26, 0x00	; 0
 10a:	b1 e0       	ldi	r27, 0x01	; 1
 10c:	e4 e3       	ldi	r30, 0x34	; 52
 10e:	f6 e0       	ldi	r31, 0x06	; 6
 110:	02 c0       	rjmp	.+4      	; 0x116 <__do_copy_data+0x10>
 112:	05 90       	lpm	r0, Z+
 114:	0d 92       	st	X+, r0
 116:	a0 32       	cpi	r26, 0x20	; 32
 118:	b1 07       	cpc	r27, r17
 11a:	d9 f7       	brne	.-10     	; 0x112 <__do_copy_data+0xc>

0000011c <__do_clear_bss>:
 11c:	11 e0       	ldi	r17, 0x01	; 1
 11e:	a0 e2       	ldi	r26, 0x20	; 32
 120:	b1 e0       	ldi	r27, 0x01	; 1
 122:	01 c0       	rjmp	.+2      	; 0x126 <.do_clear_bss_start>

00000124 <.do_clear_bss_loop>:
 124:	1d 92       	st	X+, r1

00000126 <.do_clear_bss_start>:
 126:	a2 35       	cpi	r26, 0x52	; 82
 128:	b1 07       	cpc	r27, r17
 12a:	e1 f7       	brne	.-8      	; 0x124 <.do_clear_bss_loop>
 12c:	0e 94 0e 03 	call	0x61c	; 0x61c <main>
 130:	0c 94 18 03 	jmp	0x630	; 0x630 <_exit>

00000134 <__bad_interrupt>:
 134:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000138 <ourDelay>:
 138:	00 97       	sbiw	r24, 0x00	; 0
 13a:	c1 f0       	breq	.+48     	; 0x16c <ourDelay+0x34>
 13c:	40 e0       	ldi	r20, 0x00	; 0
 13e:	50 e0       	ldi	r21, 0x00	; 0
 140:	20 e4       	ldi	r18, 0x40	; 64
 142:	30 e0       	ldi	r19, 0x00	; 0
 144:	00 00       	nop
 146:	21 50       	subi	r18, 0x01	; 1
 148:	31 09       	sbc	r19, r1
 14a:	21 15       	cp	r18, r1
 14c:	31 05       	cpc	r19, r1
 14e:	d1 f7       	brne	.-12     	; 0x144 <ourDelay+0xc>
 150:	20 e4       	ldi	r18, 0x40	; 64
 152:	30 e0       	ldi	r19, 0x00	; 0
 154:	00 00       	nop
 156:	21 50       	subi	r18, 0x01	; 1
 158:	31 09       	sbc	r19, r1
 15a:	21 15       	cp	r18, r1
 15c:	31 05       	cpc	r19, r1
 15e:	d1 f7       	brne	.-12     	; 0x154 <ourDelay+0x1c>
 160:	4f 5f       	subi	r20, 0xFF	; 255
 162:	5f 4f       	sbci	r21, 0xFF	; 255
 164:	48 17       	cp	r20, r24
 166:	59 07       	cpc	r21, r25
 168:	59 f7       	brne	.-42     	; 0x140 <ourDelay+0x8>
 16a:	08 95       	ret
 16c:	08 95       	ret

0000016e <getBinaryString>:
 16e:	e1 e2       	ldi	r30, 0x21	; 33
 170:	f1 e0       	ldi	r31, 0x01	; 1
 172:	20 e0       	ldi	r18, 0x00	; 0
 174:	30 e0       	ldi	r19, 0x00	; 0
 176:	71 e3       	ldi	r23, 0x31	; 49
 178:	60 e2       	ldi	r22, 0x20	; 32
 17a:	ac 01       	movw	r20, r24
 17c:	02 2e       	mov	r0, r18
 17e:	02 c0       	rjmp	.+4      	; 0x184 <getBinaryString+0x16>
 180:	44 0f       	add	r20, r20
 182:	55 1f       	adc	r21, r21
 184:	0a 94       	dec	r0
 186:	e2 f7       	brpl	.-8      	; 0x180 <getBinaryString+0x12>
 188:	45 2f       	mov	r20, r21
 18a:	40 95       	com	r20
 18c:	44 1f       	adc	r20, r20
 18e:	44 27       	eor	r20, r20
 190:	44 1f       	adc	r20, r20
 192:	57 2f       	mov	r21, r23
 194:	54 1b       	sub	r21, r20
 196:	df 01       	movw	r26, r30
 198:	11 97       	sbiw	r26, 0x01	; 1
 19a:	5c 93       	st	X, r21
 19c:	60 83       	st	Z, r22
 19e:	2f 5f       	subi	r18, 0xFF	; 255
 1a0:	3f 4f       	sbci	r19, 0xFF	; 255
 1a2:	32 96       	adiw	r30, 0x02	; 2
 1a4:	20 31       	cpi	r18, 0x10	; 16
 1a6:	31 05       	cpc	r19, r1
 1a8:	41 f7       	brne	.-48     	; 0x17a <getBinaryString+0xc>
 1aa:	10 92 40 01 	sts	0x0140, r1
 1ae:	80 e2       	ldi	r24, 0x20	; 32
 1b0:	91 e0       	ldi	r25, 0x01	; 1
 1b2:	08 95       	ret

000001b4 <digitalWrite>:
 1b4:	88 30       	cpi	r24, 0x08	; 8
 1b6:	91 05       	cpc	r25, r1
 1b8:	39 f0       	breq	.+14     	; 0x1c8 <digitalWrite+0x14>
 1ba:	0d 97       	sbiw	r24, 0x0d	; 13
 1bc:	09 f0       	breq	.+2      	; 0x1c0 <digitalWrite+0xc>
 1be:	08 95       	ret
 1c0:	67 2b       	or	r22, r23
 1c2:	41 f4       	brne	.+16     	; 0x1d4 <digitalWrite+0x20>
 1c4:	2d 98       	cbi	0x05, 5	; 5
 1c6:	08 95       	ret
 1c8:	67 2b       	or	r22, r23
 1ca:	11 f0       	breq	.+4      	; 0x1d0 <digitalWrite+0x1c>
 1cc:	5b 9a       	sbi	0x0b, 3	; 11
 1ce:	08 95       	ret
 1d0:	5b 98       	cbi	0x0b, 3	; 11
 1d2:	08 95       	ret
 1d4:	2d 9a       	sbi	0x05, 5	; 5
 1d6:	08 95       	ret

000001d8 <digitalRead>:
 1d8:	81 e0       	ldi	r24, 0x01	; 1
 1da:	90 e0       	ldi	r25, 0x00	; 0
 1dc:	08 95       	ret

000001de <shiftOutClockedData>:
 1de:	0f 93       	push	r16
 1e0:	1f 93       	push	r17
 1e2:	cf 93       	push	r28
 1e4:	df 93       	push	r29
 1e6:	9c 01       	movw	r18, r24
 1e8:	20 7f       	andi	r18, 0xF0	; 240
 1ea:	33 27       	eor	r19, r19
 1ec:	20 31       	cpi	r18, 0x10	; 16
 1ee:	31 05       	cpc	r19, r1
 1f0:	f1 f0       	breq	.+60     	; 0x22e <shiftOutClockedData+0x50>
 1f2:	20 32       	cpi	r18, 0x20	; 32
 1f4:	31 05       	cpc	r19, r1
 1f6:	f1 f0       	breq	.+60     	; 0x234 <shiftOutClockedData+0x56>
 1f8:	20 34       	cpi	r18, 0x40	; 64
 1fa:	31 05       	cpc	r19, r1
 1fc:	f1 f0       	breq	.+60     	; 0x23a <shiftOutClockedData+0x5c>
 1fe:	8c 01       	movw	r16, r24
 200:	00 95       	com	r16
 202:	10 95       	com	r17
 204:	c0 e1       	ldi	r28, 0x10	; 16
 206:	d0 e0       	ldi	r29, 0x00	; 0
 208:	b8 01       	movw	r22, r16
 20a:	61 70       	andi	r22, 0x01	; 1
 20c:	77 27       	eor	r23, r23
 20e:	88 e0       	ldi	r24, 0x08	; 8
 210:	90 e0       	ldi	r25, 0x00	; 0
 212:	0e 94 da 00 	call	0x1b4	; 0x1b4 <digitalWrite>
 216:	16 95       	lsr	r17
 218:	07 95       	ror	r16
 21a:	2d 9a       	sbi	0x05, 5	; 5
 21c:	2d 98       	cbi	0x05, 5	; 5
 21e:	21 97       	sbiw	r28, 0x01	; 1
 220:	20 97       	sbiw	r28, 0x00	; 0
 222:	91 f7       	brne	.-28     	; 0x208 <shiftOutClockedData+0x2a>
 224:	df 91       	pop	r29
 226:	cf 91       	pop	r28
 228:	1f 91       	pop	r17
 22a:	0f 91       	pop	r16
 22c:	08 95       	ret
 22e:	8f 70       	andi	r24, 0x0F	; 15
 230:	80 68       	ori	r24, 0x80	; 128
 232:	e5 cf       	rjmp	.-54     	; 0x1fe <shiftOutClockedData+0x20>
 234:	8f 70       	andi	r24, 0x0F	; 15
 236:	80 64       	ori	r24, 0x40	; 64
 238:	e2 cf       	rjmp	.-60     	; 0x1fe <shiftOutClockedData+0x20>
 23a:	8f 70       	andi	r24, 0x0F	; 15
 23c:	80 62       	ori	r24, 0x20	; 32
 23e:	df cf       	rjmp	.-66     	; 0x1fe <shiftOutClockedData+0x20>

00000240 <runTrafficLight>:
 240:	84 e1       	ldi	r24, 0x14	; 20
 242:	91 e9       	ldi	r25, 0x91	; 145
 244:	0e 94 ef 00 	call	0x1de	; 0x1de <shiftOutClockedData>
 248:	24 e1       	ldi	r18, 0x14	; 20
 24a:	42 2e       	mov	r4, r18
 24c:	21 e9       	ldi	r18, 0x91	; 145
 24e:	52 2e       	mov	r5, r18
 250:	c0 e0       	ldi	r28, 0x00	; 0
 252:	d0 e0       	ldi	r29, 0x00	; 0
 254:	3f e0       	ldi	r19, 0x0F	; 15
 256:	e3 2e       	mov	r14, r19
 258:	f1 2c       	mov	r15, r1
 25a:	88 24       	eor	r8, r8
 25c:	83 94       	inc	r8
 25e:	91 2c       	mov	r9, r1
 260:	52 e0       	ldi	r21, 0x02	; 2
 262:	a5 2e       	mov	r10, r21
 264:	b1 2c       	mov	r11, r1
 266:	64 e0       	ldi	r22, 0x04	; 4
 268:	c6 2e       	mov	r12, r22
 26a:	d1 2c       	mov	r13, r1
 26c:	79 e0       	ldi	r23, 0x09	; 9
 26e:	67 2e       	mov	r6, r23
 270:	71 2c       	mov	r7, r1
 272:	c4 30       	cpi	r28, 0x04	; 4
 274:	d1 05       	cpc	r29, r1
 276:	0c f4       	brge	.+2      	; 0x27a <runTrafficLight+0x3a>
 278:	5d c0       	rjmp	.+186    	; 0x334 <runTrafficLight+0xf4>
 27a:	8a e6       	ldi	r24, 0x6A	; 106
 27c:	90 e0       	ldi	r25, 0x00	; 0
 27e:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 282:	0e 94 b9 02 	call	0x572	; 0x572 <USART_Transmit_Bytes_P>
 286:	94 e3       	ldi	r25, 0x34	; 52
 288:	90 93 00 02 	sts	0x0200, r25
 28c:	84 e3       	ldi	r24, 0x34	; 52
 28e:	90 e0       	ldi	r25, 0x00	; 0
 290:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 294:	80 91 00 02 	lds	r24, 0x0200
 298:	99 27       	eor	r25, r25
 29a:	87 fd       	sbrc	r24, 7
 29c:	90 95       	com	r25
 29e:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 2a2:	80 91 00 02 	lds	r24, 0x0200
 2a6:	99 27       	eor	r25, r25
 2a8:	87 fd       	sbrc	r24, 7
 2aa:	90 95       	com	r25
 2ac:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 2b0:	80 91 61 00 	lds	r24, 0x0061
 2b4:	99 27       	eor	r25, r25
 2b6:	87 fd       	sbrc	r24, 7
 2b8:	90 95       	com	r25
 2ba:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 2be:	80 91 62 00 	lds	r24, 0x0062
 2c2:	99 27       	eor	r25, r25
 2c4:	87 fd       	sbrc	r24, 7
 2c6:	90 95       	com	r25
 2c8:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 2cc:	80 91 60 00 	lds	r24, 0x0060
 2d0:	99 27       	eor	r25, r25
 2d2:	87 fd       	sbrc	r24, 7
 2d4:	90 95       	com	r25
 2d6:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 2da:	80 91 60 00 	lds	r24, 0x0060
 2de:	99 27       	eor	r25, r25
 2e0:	87 fd       	sbrc	r24, 7
 2e2:	90 95       	com	r25
 2e4:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 2e8:	8d e4       	ldi	r24, 0x4D	; 77
 2ea:	90 e0       	ldi	r25, 0x00	; 0
 2ec:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 2f0:	8d e4       	ldi	r24, 0x4D	; 77
 2f2:	90 e0       	ldi	r25, 0x00	; 0
 2f4:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 2f8:	0e 94 e0 02 	call	0x5c0	; 0x5c0 <USART_Transmit_Bytes>
 2fc:	80 91 60 00 	lds	r24, 0x0060
 300:	99 27       	eor	r25, r25
 302:	87 fd       	sbrc	r24, 7
 304:	90 95       	com	r25
 306:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 30a:	8a e0       	ldi	r24, 0x0A	; 10
 30c:	90 e0       	ldi	r25, 0x00	; 0
 30e:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 312:	88 e6       	ldi	r24, 0x68	; 104
 314:	90 e0       	ldi	r25, 0x00	; 0
 316:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 31a:	80 91 60 00 	lds	r24, 0x0060
 31e:	99 27       	eor	r25, r25
 320:	87 fd       	sbrc	r24, 7
 322:	90 95       	com	r25
 324:	0e 94 69 02 	call	0x4d2	; 0x4d2 <USART_Transmit>
 328:	c0 e0       	ldi	r28, 0x00	; 0
 32a:	d0 e0       	ldi	r29, 0x00	; 0
 32c:	c4 30       	cpi	r28, 0x04	; 4
 32e:	d1 05       	cpc	r29, r1
 330:	0c f0       	brlt	.+2      	; 0x334 <runTrafficLight+0xf4>
 332:	a3 cf       	rjmp	.-186    	; 0x27a <runTrafficLight+0x3a>
 334:	80 ef       	ldi	r24, 0xF0	; 240
 336:	90 e0       	ldi	r25, 0x00	; 0
 338:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 33c:	8e 01       	movw	r16, r28
 33e:	00 0f       	add	r16, r16
 340:	11 1f       	adc	r17, r17
 342:	00 0f       	add	r16, r16
 344:	11 1f       	adc	r17, r17
 346:	c2 01       	movw	r24, r4
 348:	00 2e       	mov	r0, r16
 34a:	02 c0       	rjmp	.+4      	; 0x350 <runTrafficLight+0x110>
 34c:	96 95       	lsr	r25
 34e:	87 95       	ror	r24
 350:	0a 94       	dec	r0
 352:	e2 f7       	brpl	.-8      	; 0x34c <runTrafficLight+0x10c>
 354:	80 fd       	sbrc	r24, 0
 356:	3a c0       	rjmp	.+116    	; 0x3cc <runTrafficLight+0x18c>
 358:	81 ff       	sbrs	r24, 1
 35a:	3a c0       	rjmp	.+116    	; 0x3d0 <runTrafficLight+0x190>
 35c:	44 ef       	ldi	r20, 0xF4	; 244
 35e:	51 e0       	ldi	r21, 0x01	; 1
 360:	80 e4       	ldi	r24, 0x40	; 64
 362:	90 e0       	ldi	r25, 0x00	; 0
 364:	00 00       	nop
 366:	01 97       	sbiw	r24, 0x01	; 1
 368:	00 97       	sbiw	r24, 0x00	; 0
 36a:	e1 f7       	brne	.-8      	; 0x364 <runTrafficLight+0x124>
 36c:	20 e4       	ldi	r18, 0x40	; 64
 36e:	30 e0       	ldi	r19, 0x00	; 0
 370:	00 00       	nop
 372:	21 50       	subi	r18, 0x01	; 1
 374:	31 09       	sbc	r19, r1
 376:	21 15       	cp	r18, r1
 378:	31 05       	cpc	r19, r1
 37a:	d1 f7       	brne	.-12     	; 0x370 <runTrafficLight+0x130>
 37c:	41 50       	subi	r20, 0x01	; 1
 37e:	51 09       	sbc	r21, r1
 380:	41 15       	cp	r20, r1
 382:	51 05       	cpc	r21, r1
 384:	69 f7       	brne	.-38     	; 0x360 <runTrafficLight+0x120>
 386:	17 01       	movw	r2, r14
 388:	00 2e       	mov	r0, r16
 38a:	02 c0       	rjmp	.+4      	; 0x390 <runTrafficLight+0x150>
 38c:	22 0c       	add	r2, r2
 38e:	33 1c       	adc	r3, r3
 390:	0a 94       	dec	r0
 392:	e2 f7       	brpl	.-8      	; 0x38c <runTrafficLight+0x14c>
 394:	20 94       	com	r2
 396:	30 94       	com	r3
 398:	24 20       	and	r2, r4
 39a:	35 20       	and	r3, r5
 39c:	c6 01       	movw	r24, r12
 39e:	00 2e       	mov	r0, r16
 3a0:	02 c0       	rjmp	.+4      	; 0x3a6 <runTrafficLight+0x166>
 3a2:	88 0f       	add	r24, r24
 3a4:	99 1f       	adc	r25, r25
 3a6:	0a 94       	dec	r0
 3a8:	e2 f7       	brpl	.-8      	; 0x3a2 <runTrafficLight+0x162>
 3aa:	28 2a       	or	r2, r24
 3ac:	39 2a       	or	r3, r25
 3ae:	20 97       	sbiw	r28, 0x00	; 0
 3b0:	09 f0       	breq	.+2      	; 0x3b4 <runTrafficLight+0x174>
 3b2:	4f c0       	rjmp	.+158    	; 0x452 <runTrafficLight+0x212>
 3b4:	81 ee       	ldi	r24, 0xE1	; 225
 3b6:	90 e0       	ldi	r25, 0x00	; 0
 3b8:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 3bc:	21 01       	movw	r4, r2
 3be:	8f e0       	ldi	r24, 0x0F	; 15
 3c0:	58 22       	and	r5, r24
 3c2:	90 e9       	ldi	r25, 0x90	; 144
 3c4:	59 2a       	or	r5, r25
 3c6:	c2 01       	movw	r24, r4
 3c8:	0e 94 ef 00 	call	0x1de	; 0x1de <shiftOutClockedData>
 3cc:	21 96       	adiw	r28, 0x01	; 1
 3ce:	51 cf       	rjmp	.-350    	; 0x272 <runTrafficLight+0x32>
 3d0:	82 fd       	sbrc	r24, 2
 3d2:	08 c0       	rjmp	.+16     	; 0x3e4 <runTrafficLight+0x1a4>
 3d4:	83 ff       	sbrs	r24, 3
 3d6:	fa cf       	rjmp	.-12     	; 0x3cc <runTrafficLight+0x18c>
 3d8:	8f e7       	ldi	r24, 0x7F	; 127
 3da:	90 e0       	ldi	r25, 0x00	; 0
 3dc:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 3e0:	21 96       	adiw	r28, 0x01	; 1
 3e2:	47 cf       	rjmp	.-370    	; 0x272 <runTrafficLight+0x32>
 3e4:	20 ed       	ldi	r18, 0xD0	; 208
 3e6:	37 e0       	ldi	r19, 0x07	; 7
 3e8:	80 e4       	ldi	r24, 0x40	; 64
 3ea:	90 e0       	ldi	r25, 0x00	; 0
 3ec:	00 00       	nop
 3ee:	01 97       	sbiw	r24, 0x01	; 1
 3f0:	00 97       	sbiw	r24, 0x00	; 0
 3f2:	e1 f7       	brne	.-8      	; 0x3ec <runTrafficLight+0x1ac>
 3f4:	80 e4       	ldi	r24, 0x40	; 64
 3f6:	90 e0       	ldi	r25, 0x00	; 0
 3f8:	00 00       	nop
 3fa:	01 97       	sbiw	r24, 0x01	; 1
 3fc:	00 97       	sbiw	r24, 0x00	; 0
 3fe:	e1 f7       	brne	.-8      	; 0x3f8 <runTrafficLight+0x1b8>
 400:	21 50       	subi	r18, 0x01	; 1
 402:	31 09       	sbc	r19, r1
 404:	21 15       	cp	r18, r1
 406:	31 05       	cpc	r19, r1
 408:	79 f7       	brne	.-34     	; 0x3e8 <runTrafficLight+0x1a8>
 40a:	8f eb       	ldi	r24, 0xBF	; 191
 40c:	90 e0       	ldi	r25, 0x00	; 0
 40e:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 412:	17 01       	movw	r2, r14
 414:	00 2e       	mov	r0, r16
 416:	02 c0       	rjmp	.+4      	; 0x41c <runTrafficLight+0x1dc>
 418:	22 0c       	add	r2, r2
 41a:	33 1c       	adc	r3, r3
 41c:	0a 94       	dec	r0
 41e:	e2 f7       	brpl	.-8      	; 0x418 <runTrafficLight+0x1d8>
 420:	20 94       	com	r2
 422:	30 94       	com	r3
 424:	24 20       	and	r2, r4
 426:	35 20       	and	r3, r5
 428:	c4 01       	movw	r24, r8
 42a:	00 2e       	mov	r0, r16
 42c:	02 c0       	rjmp	.+4      	; 0x432 <runTrafficLight+0x1f2>
 42e:	88 0f       	add	r24, r24
 430:	99 1f       	adc	r25, r25
 432:	0a 94       	dec	r0
 434:	e2 f7       	brpl	.-8      	; 0x42e <runTrafficLight+0x1ee>
 436:	28 2a       	or	r2, r24
 438:	39 2a       	or	r3, r25
 43a:	20 97       	sbiw	r28, 0x00	; 0
 43c:	21 f5       	brne	.+72     	; 0x486 <runTrafficLight+0x246>
 43e:	88 ea       	ldi	r24, 0xA8	; 168
 440:	90 e0       	ldi	r25, 0x00	; 0
 442:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 446:	21 01       	movw	r4, r2
 448:	9f e0       	ldi	r25, 0x0F	; 15
 44a:	59 22       	and	r5, r25
 44c:	68 94       	set
 44e:	55 f8       	bld	r5, 5
 450:	ba cf       	rjmp	.-140    	; 0x3c6 <runTrafficLight+0x186>
 452:	80 ed       	ldi	r24, 0xD0	; 208
 454:	90 e0       	ldi	r25, 0x00	; 0
 456:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 45a:	04 50       	subi	r16, 0x04	; 4
 45c:	11 09       	sbc	r17, r1
 45e:	27 01       	movw	r4, r14
 460:	00 2e       	mov	r0, r16
 462:	02 c0       	rjmp	.+4      	; 0x468 <runTrafficLight+0x228>
 464:	44 0c       	add	r4, r4
 466:	55 1c       	adc	r5, r5
 468:	0a 94       	dec	r0
 46a:	e2 f7       	brpl	.-8      	; 0x464 <runTrafficLight+0x224>
 46c:	40 94       	com	r4
 46e:	50 94       	com	r5
 470:	42 20       	and	r4, r2
 472:	53 20       	and	r5, r3
 474:	c3 01       	movw	r24, r6
 476:	02 c0       	rjmp	.+4      	; 0x47c <runTrafficLight+0x23c>
 478:	88 0f       	add	r24, r24
 47a:	99 1f       	adc	r25, r25
 47c:	0a 95       	dec	r16
 47e:	e2 f7       	brpl	.-8      	; 0x478 <runTrafficLight+0x238>
 480:	48 2a       	or	r4, r24
 482:	59 2a       	or	r5, r25
 484:	a0 cf       	rjmp	.-192    	; 0x3c6 <runTrafficLight+0x186>
 486:	80 e9       	ldi	r24, 0x90	; 144
 488:	90 e0       	ldi	r25, 0x00	; 0
 48a:	0e 94 97 02 	call	0x52e	; 0x52e <USART_Transmit_String_P>
 48e:	04 50       	subi	r16, 0x04	; 4
 490:	11 09       	sbc	r17, r1
 492:	27 01       	movw	r4, r14
 494:	00 2e       	mov	r0, r16
 496:	02 c0       	rjmp	.+4      	; 0x49c <runTrafficLight+0x25c>
 498:	44 0c       	add	r4, r4
 49a:	55 1c       	adc	r5, r5
 49c:	0a 94       	dec	r0
 49e:	e2 f7       	brpl	.-8      	; 0x498 <runTrafficLight+0x258>
 4a0:	40 94       	com	r4
 4a2:	50 94       	com	r5
 4a4:	42 20       	and	r4, r2
 4a6:	53 20       	and	r5, r3
 4a8:	c5 01       	movw	r24, r10
 4aa:	02 c0       	rjmp	.+4      	; 0x4b0 <runTrafficLight+0x270>
 4ac:	88 0f       	add	r24, r24
 4ae:	99 1f       	adc	r25, r25
 4b0:	0a 95       	dec	r16
 4b2:	e2 f7       	brpl	.-8      	; 0x4ac <runTrafficLight+0x26c>
 4b4:	48 2a       	or	r4, r24
 4b6:	59 2a       	or	r5, r25
 4b8:	86 cf       	rjmp	.-244    	; 0x3c6 <runTrafficLight+0x186>

000004ba <USART_Init>:
 4ba:	90 93 c5 00 	sts	0x00C5, r25
 4be:	80 93 c4 00 	sts	0x00C4, r24
 4c2:	e1 ec       	ldi	r30, 0xC1	; 193
 4c4:	f0 e0       	ldi	r31, 0x00	; 0
 4c6:	88 e0       	ldi	r24, 0x08	; 8
 4c8:	80 83       	st	Z, r24
 4ca:	80 81       	ld	r24, Z
 4cc:	80 64       	ori	r24, 0x40	; 64
 4ce:	80 83       	st	Z, r24
 4d0:	08 95       	ret

000004d2 <USART_Transmit>:
 4d2:	90 91 c0 00 	lds	r25, 0x00C0
 4d6:	95 ff       	sbrs	r25, 5
 4d8:	fc cf       	rjmp	.-8      	; 0x4d2 <USART_Transmit>
 4da:	80 93 c6 00 	sts	0x00C6, r24
 4de:	08 95       	ret

000004e0 <printByte>:
 4e0:	98 2f       	mov	r25, r24
 4e2:	92 95       	swap	r25
 4e4:	9f 70       	andi	r25, 0x0F	; 15
 4e6:	9a 30       	cpi	r25, 0x0A	; 10
 4e8:	d8 f4       	brcc	.+54     	; 0x520 <printByte+0x40>
 4ea:	20 e3       	ldi	r18, 0x30	; 48
 4ec:	29 0f       	add	r18, r25
 4ee:	90 91 c0 00 	lds	r25, 0x00C0
 4f2:	95 ff       	sbrs	r25, 5
 4f4:	fc cf       	rjmp	.-8      	; 0x4ee <printByte+0xe>
 4f6:	20 93 c6 00 	sts	0x00C6, r18
 4fa:	8f 70       	andi	r24, 0x0F	; 15
 4fc:	8a 30       	cpi	r24, 0x0A	; 10
 4fe:	40 f4       	brcc	.+16     	; 0x510 <printByte+0x30>
 500:	80 5d       	subi	r24, 0xD0	; 208
 502:	90 91 c0 00 	lds	r25, 0x00C0
 506:	95 ff       	sbrs	r25, 5
 508:	fc cf       	rjmp	.-8      	; 0x502 <printByte+0x22>
 50a:	80 93 c6 00 	sts	0x00C6, r24
 50e:	08 95       	ret
 510:	89 5c       	subi	r24, 0xC9	; 201
 512:	90 91 c0 00 	lds	r25, 0x00C0
 516:	95 ff       	sbrs	r25, 5
 518:	fc cf       	rjmp	.-8      	; 0x512 <printByte+0x32>
 51a:	80 93 c6 00 	sts	0x00C6, r24
 51e:	08 95       	ret
 520:	27 e3       	ldi	r18, 0x37	; 55
 522:	29 0f       	add	r18, r25
 524:	90 91 c0 00 	lds	r25, 0x00C0
 528:	95 ff       	sbrs	r25, 5
 52a:	fc cf       	rjmp	.-8      	; 0x524 <printByte+0x44>
 52c:	e4 cf       	rjmp	.-56     	; 0x4f6 <printByte+0x16>

0000052e <USART_Transmit_String_P>:
 52e:	20 e0       	ldi	r18, 0x00	; 0
 530:	30 e0       	ldi	r19, 0x00	; 0
 532:	fc 01       	movw	r30, r24
 534:	e2 0f       	add	r30, r18
 536:	f3 1f       	adc	r31, r19
 538:	e4 91       	lpm	r30, Z
 53a:	ee 23       	and	r30, r30
 53c:	59 f0       	breq	.+22     	; 0x554 <USART_Transmit_String_P+0x26>
 53e:	40 91 c0 00 	lds	r20, 0x00C0
 542:	45 ff       	sbrs	r20, 5
 544:	fc cf       	rjmp	.-8      	; 0x53e <USART_Transmit_String_P+0x10>
 546:	e0 93 c6 00 	sts	0x00C6, r30
 54a:	2f 5f       	subi	r18, 0xFF	; 255
 54c:	3f 4f       	sbci	r19, 0xFF	; 255
 54e:	24 36       	cpi	r18, 0x64	; 100
 550:	31 05       	cpc	r19, r1
 552:	79 f7       	brne	.-34     	; 0x532 <USART_Transmit_String_P+0x4>
 554:	80 91 c0 00 	lds	r24, 0x00C0
 558:	85 ff       	sbrs	r24, 5
 55a:	fc cf       	rjmp	.-8      	; 0x554 <USART_Transmit_String_P+0x26>
 55c:	8d e0       	ldi	r24, 0x0D	; 13
 55e:	80 93 c6 00 	sts	0x00C6, r24
 562:	80 91 c0 00 	lds	r24, 0x00C0
 566:	85 ff       	sbrs	r24, 5
 568:	fc cf       	rjmp	.-8      	; 0x562 <USART_Transmit_String_P+0x34>
 56a:	8a e0       	ldi	r24, 0x0A	; 10
 56c:	80 93 c6 00 	sts	0x00C6, r24
 570:	08 95       	ret

00000572 <USART_Transmit_Bytes_P>:
 572:	1f 93       	push	r17
 574:	cf 93       	push	r28
 576:	df 93       	push	r29
 578:	ca eb       	ldi	r28, 0xBA	; 186
 57a:	d5 e0       	ldi	r29, 0x05	; 5
 57c:	10 e2       	ldi	r17, 0x20	; 32
 57e:	fe 01       	movw	r30, r28
 580:	84 91       	lpm	r24, Z
 582:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 586:	80 91 c0 00 	lds	r24, 0x00C0
 58a:	85 ff       	sbrs	r24, 5
 58c:	fc cf       	rjmp	.-8      	; 0x586 <USART_Transmit_Bytes_P+0x14>
 58e:	10 93 c6 00 	sts	0x00C6, r17
 592:	21 96       	adiw	r28, 0x01	; 1
 594:	ce 31       	cpi	r28, 0x1E	; 30
 596:	f6 e0       	ldi	r31, 0x06	; 6
 598:	df 07       	cpc	r29, r31
 59a:	89 f7       	brne	.-30     	; 0x57e <USART_Transmit_Bytes_P+0xc>
 59c:	80 91 c0 00 	lds	r24, 0x00C0
 5a0:	85 ff       	sbrs	r24, 5
 5a2:	fc cf       	rjmp	.-8      	; 0x59c <USART_Transmit_Bytes_P+0x2a>
 5a4:	8d e0       	ldi	r24, 0x0D	; 13
 5a6:	80 93 c6 00 	sts	0x00C6, r24
 5aa:	80 91 c0 00 	lds	r24, 0x00C0
 5ae:	85 ff       	sbrs	r24, 5
 5b0:	fc cf       	rjmp	.-8      	; 0x5aa <USART_Transmit_Bytes_P+0x38>
 5b2:	8a e0       	ldi	r24, 0x0A	; 10
 5b4:	80 93 c6 00 	sts	0x00C6, r24
 5b8:	df 91       	pop	r29
 5ba:	cf 91       	pop	r28
 5bc:	1f 91       	pop	r17
 5be:	08 95       	ret

000005c0 <USART_Transmit_Bytes>:
 5c0:	1f 93       	push	r17
 5c2:	cf 93       	push	r28
 5c4:	df 93       	push	r29
 5c6:	c0 e6       	ldi	r28, 0x60	; 96
 5c8:	d0 e0       	ldi	r29, 0x00	; 0
 5ca:	10 e2       	ldi	r17, 0x20	; 32
 5cc:	89 91       	ld	r24, Y+
 5ce:	0e 94 70 02 	call	0x4e0	; 0x4e0 <printByte>
 5d2:	80 91 c0 00 	lds	r24, 0x00C0
 5d6:	85 ff       	sbrs	r24, 5
 5d8:	fc cf       	rjmp	.-8      	; 0x5d2 <USART_Transmit_Bytes+0x12>
 5da:	10 93 c6 00 	sts	0x00C6, r17
 5de:	c4 3c       	cpi	r28, 0xC4	; 196
 5e0:	d1 05       	cpc	r29, r1
 5e2:	a1 f7       	brne	.-24     	; 0x5cc <USART_Transmit_Bytes+0xc>
 5e4:	80 91 c0 00 	lds	r24, 0x00C0
 5e8:	85 ff       	sbrs	r24, 5
 5ea:	fc cf       	rjmp	.-8      	; 0x5e4 <USART_Transmit_Bytes+0x24>
 5ec:	8d e0       	ldi	r24, 0x0D	; 13
 5ee:	80 93 c6 00 	sts	0x00C6, r24
 5f2:	80 91 c0 00 	lds	r24, 0x00C0
 5f6:	85 ff       	sbrs	r24, 5
 5f8:	fc cf       	rjmp	.-8      	; 0x5f2 <USART_Transmit_Bytes+0x32>
 5fa:	8a e0       	ldi	r24, 0x0A	; 10
 5fc:	80 93 c6 00 	sts	0x00C6, r24
 600:	df 91       	pop	r29
 602:	cf 91       	pop	r28
 604:	1f 91       	pop	r17
 606:	08 95       	ret

00000608 <__vector_20>:
 608:	e0 ec       	ldi	r30, 0xC0	; 192
 60a:	f0 e0       	ldi	r31, 0x00	; 0
 60c:	80 81       	ld	r24, Z
 60e:	85 ff       	sbrs	r24, 5
 610:	18 95       	reti
 612:	e6 ec       	ldi	r30, 0xC6	; 198
 614:	f0 e0       	ldi	r31, 0x00	; 0
 616:	80 83       	st	Z, r24
 618:	18 95       	reti

0000061a <__vector_18>:
 61a:	18 95       	reti

0000061c <main>:
 61c:	84 b1       	in	r24, 0x04	; 4
 61e:	83 62       	ori	r24, 0x23	; 35
 620:	84 b9       	out	0x04, r24	; 4
 622:	53 9a       	sbi	0x0a, 3	; 10
 624:	83 e3       	ldi	r24, 0x33	; 51
 626:	90 e0       	ldi	r25, 0x00	; 0
 628:	0e 94 5d 02 	call	0x4ba	; 0x4ba <USART_Init>
 62c:	0e 94 20 01 	call	0x240	; 0x240 <runTrafficLight>

00000630 <_exit>:
 630:	f8 94       	cli

00000632 <__stop_program>:
 632:	ff cf       	rjmp	.-2      	; 0x632 <__stop_program>
