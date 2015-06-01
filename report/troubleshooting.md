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
