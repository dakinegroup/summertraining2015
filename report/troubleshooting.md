#Troubleshooting

While working on arduino based projects, there came several instances, where it took lot of time to make things work. Some of the instances 
are worth capturing here, as they often repeat and knowing them beforehand can save some precious minutes of
working on hardware.

##Random behaviour of the port pins on peripheral ICs

While working on breadboard, too much engrossed in the pin connections between Arduino, Resistances and LEDs, 
VSS and VDD connections were forgotten. This caused this spurious behaviour. It took sometime, to arrive at 
the conclusion of missing supply and correct. Other doubts that came in mind were: power supply was 
apparently loaded, IC 74164 has gone bad, we are not using right sequence of instructions on controller.

##Bits mapped on software don't match with physical placement

Reason found here was the way bytes were interpreted. It was simple and got fixed soon.

##Port pins not going as commanded

It was simple though took time. PortD, pins 3:4 were to be used. So to enabled port pins, DDRD3:4 were to be set to 1,
instead, 2:3 were being set. Similarly, PORTD3:4 were to be set low or high, instead, they were 2:3. It was a confusion
between 0x0C v/s 0x06 hex values.

##Arduino IDE not working

There were few items here:

### Serial Port is not enabled

Reason here was that to run arduino one has to be sudoer or member of wvdial group on linux

### Kit not responding

Reason was that instead of using /dev/ACM0 should have been used instead of /dev/tts0.
Also, programmer mode needs to be AVRISP.

## USART Not working

It is dependent on the UBRRR value to be calculated depending on the crystal placed with ATMEga. Appropriate value as per calculation and information also available from various calculators was put. Circuit failed to respond on serial interface. With deeper reading on configuration of ATmega328, it was discovered, that by default, processor runs on 8MHz internal clock, scaled down by 8 internally for all practical purposes. Also, it is not a precise clock. This also correlated with response on serial interface, when baud was made 1200 on terminal side, while configuration in UBRR mapped to 9600.

As per specifications, 51 as UBRR worked, but still the desired output was not there. Tailoring it further both sides, 51 till 56 and 40 till 56. Accuracy of transmission was achieved at UBRR of 41.

## Fuse Bits bricked processor

As we discovered processor works at 8MHz because of unprogrammed fuse bits. So next step was to fuse them with desired bit status using AVRDude. As we fused high byte with 0xFF, it stopped interacting even with AVRdude, and even our running program of traffic lights stopped working. Now the task at hand was to see if this processor can be recovered, somehow. As advised from internet, several links, one has to use an external clock at XTAL1 (pin 9), to clock CPU and hence try programming it for new fuse values. It worked.

We used Arduino Kit to generate clock and used AVRuPro to program the fuses.

## Making external 16MHz clock work

In previous problem controller was not responding because, it was now dependent on external Crystal clock after changing fuse settings. Crystal though put in the circuit was not responding. Several cleaning, re-soldering were done but of no use. In the end, crystal was removed and tested independently on breadboard for it's healthy condition. It was ok.

Only option left was to try it on a different location. Earlier location on PCB was little crowded, which may have led to some stray resistances and capacitances at track level. So it was moved a little bit away at cleaner place and processor started to respond at 16MHz.

With this another problem of USART not working as per UBRR calculation also started working.

## Heating up of MAX232, when powered with USB

Still unresolved.
Strangely enough, this heats up all of a sudden and new chip when placed, works well. After few hours, the chip that was heated, when again placed on circuit also works. Again, all possible tracks cleaning, connection re-check was done, but of not much use.

### Passing String or Array argument in a subroutine corrupts

Whenever a function was called with an argument, it was causing the processor to run wierdly. This weird behaviour was visible in terms of traffic lights running irregularly and weird characters coming on the serial terminal.

After long debugging, it was found that initially what was thought as relevant flag i.e. -mmcu=avr5 is not correct, -mmcu=atmega328p. Use of internet to solve one of the problems had led to induction of this fault and was never doubted in the whole process of debugging.

Now after this, even the UBRR of 51 is also working perfectly, 41 does not work any more.

### Intermittent behaviour of circuit when powered on

At times, processor was not able to run program as expected. It was suspected that it has to do with power supply quality, which was taken from regular phone charger. To eliminate this, we put up 7805 regulator with polarity protection diode and a filter circuit with 100uF capacitor. With this addition, circuit was 100% responding to our requests.

Another side effect of poor quality power supply was failure of flash programming at times.

### Mistakes in hardware, Software Workaround

There were two instances, where hardware mistake occurred. One - LEDs for traffic lights were not in logical sequence. Second - Shift register output lowest bit (D0) was left unused for LCD data input. In both cases, software was enhanced to deal with situation. Clearly, it gives a performance penalty because of additional code. Code extract is captured below:
```c
void sendDataToLCD(unsigned char data, int delay) {
    unsigned int i, bit;
    char cmds[10];
    sprintf(cmds, "%02x\r\n", data);
    data = data << 1; /* workaround for the Q0 bit missed out in wiring */
    for(i=0;i<8;i++) { 
    /* though only 4bits are relevant, lets do it all */
      /* extract bit - highest bit first on shift, 
      it goes to MSB, after 8 shifts */
```

```c
void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0,val=0;
     char msg[10];

     unsigned int chgByte = (dat1 & 0x00F0) ;
     /* traffic lights in wiring is out of sequence, so fix them here */    
     if(chgByte == 0x10) {
        dat1 = (dat1 & 0xFF0F) | 0x80;      
     } else if (chgByte == 0x20) {
        dat1 = (dat1 & 0xFF0F) | 0x40;      
     } else if (chgByte == 0x40) {
        dat1 = (dat1 & 0xFF0F) | 0x20;
     }
