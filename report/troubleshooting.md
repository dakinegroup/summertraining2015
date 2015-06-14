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

### USART Not working

It is dependent on the UBRRR value to be calculated depending on the crystal placed with ATMEga. Appropriate value as per calculation and information also available from various calculators was put. Circuit failed to respond on serial interface. With deeper reading on configuration of ATmega328, it was discovered, that by default, processor runs on 8MHz internal clock, scaled down by 8 internally for all practical purposes. Also, it is not a precise clock. This also correlated with response on serial interface, when baud was made 1200 on terminal side, while configuration in UBRR mapped to 9600.

As per specifications, 51 as UBRR worked, but still the desired output was not there. Tailoring it further both sides, 51 till 56 and 40 till 56. Accuracy of transmission was achieved at UBRR of 41.

### Fuse Bits bricked processor

As we discovered processor works at 8MHz because of unprogrammed fuse bits. So next step was to fuse them with desired bit status using AVRDude. As we fused high byte with 0xFF, it stopped interacting even with AVRdude, and even our running program of traffic lights stopped working. Now the task at hand was to see if this processor can be recovered, somehow. As advised from internet, several links, one has to use an external clock at XTAL1 (pin 9), to clock CPU and hence try programming it for new fuse values. It worked.

### Making external 16MHz clock work

Still unresolved.

### Heating up of MAX232, when powered with USB

Still unresolved

### Passing String or Array argument in a subroutine corrupts

Still unresolved
