#ATmega 8
##Basic Terminology
1. **EPROM** - Erasable Programmable Read Only Memory.  
                It is erased by exposing to strong UV light source.  
                It is Non Volatile.  
                It was used in microcontrollers like _Itel 8048_ and _C versions of PIC Microcontrollers_.

2. **EEPROM** - Electrically Erasable Programmable ROM.  
It is used to store small amount of data.  
While _EPROM_ is removed for erasing and programming, _EEPROM_ can be erased and programmed by applying **special programming signals.**  
I is used in _AVR_ for semi permanent data storage.

3. **Flash Memory** - It is developed from EEPROM. It was first Developed by _Toshiba_.  
                      It is of two types - 1.NAND 2. NOR.
                      It is used in memory cards, USB flashdrives, SSDs.

4. **Microcontroller** - Its a small computer on single integrated circuit.  
It contains processor core, memory and input output peripherals.  

5. **AVR** - It is single chip _bit microcontroller_.  
It was developed by _Atmel_ in 1996.  
It uses **flash memory**.

6. **GPIO** - General Purpose Input/ Output.  
GPIO in AVR is controlled by 3 **8-bit registers**.  
 * _DDRx_ - Data Direction Register. It configures pins as i/p or o/p.
 * _Portx_ - Output Port Register. It sets output value on pins configured.
 * _PINx_ - It is input register. It is used for pin toggling. It is used to read input signal.  
 * x is **Pin Identifier.**  

7. **MPU** - Memory Protection Unit.  
Memory protection is a way to prevent process from accessing memory that hasn't been allocated to it.  
It prevents a _bug_ or _malware_ within a process from affecting other processes.  

8. **Watchdog Timer(_WDT_)** - It is used to detect and recover from computer malfunction.  
During normal operation, the computer regularly restarts the watchdog timer to prevent from elapsing or timing out. If due to a hardware fault or programme error, the computer fails to restart the watchdog, the timer will elapse and generate a timeout signal. It generates timeout signal to initiate corrective measures.
**TODO**: write about other timers. please read the user manual of this chip.

9. **SPI** - Serial Peripheral Interface.  
It is used for short communication primarily in embedded system. Communication is in full duplex mode.

10. **CAN** - Control Area Network Bus.  
It aloows to communicate without host computer.

11. **I2S** - Integrated Interchip Sound.  
It is used for connecting digital audio devices together.  
_PCM_ audio data is communicated between _ICs_.

12. **Time Stamp** - Sequence of characters or encoded information identifying when an event occured is called _time stamp_.

13. **Input Capture** - Method of dealing with input.  
Embedded system using input capture will record a timestamp in memory when a input signal is received.

14. **Output Compare** - Capability to trigger an output at specific time, based on a timestamp in memory, is called _output compare_.

15. **UART** - Universal Asynchronous Receiver and Transmitter.
**TODO**: write about the sync, data, stop, start, parity/error bits here, what is the difference between synchronoous and asynchronous communication channels, what is the maximum speed that can be achieved on this?

16. **I2C** - Inter-Integrated Circuit.  
These are used for attaching lower speed peripherals to computers.


**TODO:** write more about it.

**TODO:** write about RS485 as well as other buses that work outside controller interfacing with UART

17. **RTC** - Real Time Clock

## Features of ATmega 8##

 1. Flash - 8kb
 2. Pin Count - 32
 3. Max. Operating Frequency - 16 MHz
 4. CPU - 8-bit AVR
 5. I/O Pins - 23
 6. SPI - 1
 7. I2C - 1
 8. UART - 1
 9. ADC Channels - 8
 10. Analog Comparators - 1
 11. SRAM - 1
 12. EEPROM - 512 bytes
 13. Operating Voltage - 2.7v to 5.5v
 14. O/P Compare Channels - 3
 15. I/P Capture Channels - 1
 16. PWM Channels - 3
 17. RTC - Counter
 18. Timers - 3

## Setting up development environment

 **TODO:** Attach photograph of the connected circuitry, jumpers..
 
 **TODO:** Attach photograph of the glowing LEDs when being programmed (Green LED)
 
### Connecting Programmer to Kit
 
 **TODO:** Refer to MISO, MOSI PIN functionality
 
### Connecting Programmer to Ubuntu
 **TODO:** Refer to the URLs, from where avrdued was downloaded and some 2-3 lines about it
 
 
 
### Write a simple program
 
 **TODO:** Refer to the URLs, from where GCC tool chain for AVR was downloaded
 
 **TODO:** Refer to the URLs, from where the simple program for testing is reused
 

### Make 
 
 **TODO:** Write your understanding about different intermediate files being generated, .lst, .hex, .map
 
### Flash

Command used for flashing code to ATMEGA8

 `sudo avrdude -p atmega8 -U flash:w:demo.hex -c usbasp`

## Hardware
 
 * [Datasheet] (http://www.atmel.com/Images/Atmel-8159-8-bit-AVR-microcontroller-ATmega8A_datasheet.pdf)
    * [Programmer User Manual](http://www.elesof.com/electronics/data/admin-files/AVRUPro+_V02.pdf)
 * [PIN Mapping of Arduino UNO with ATMEGA 328] (http://www.arduino.cc/en/Hacking/PinMapping168)
 * [Programmer Used for flashing ATMEGA8A](http://www.elesof.com/electronics/product/avrupro_plus)
 * Buses
     - [I2C](http://www.nxp.com/documents/user_manual/UM10204.pdf)
     - [UART/232]()
     - [SPI]()
     - [RS485]()
 * MAX RS232 Interface -  [(Datasheet)](http://www.ti.com/lit/ds/symlink/max232.pdf), [(Example Circuitry)](https://arduinodiy.files.wordpress.com/2012/03/max232.jpg)

## Software

 Useful URLs to read:
 * [Tool Chain](http://nongnu.org/avr-libc/user-manual)
    * specifically this project [Simple Project](http://nongnu.org/avr-libc/user-manual/group__demo__project.html)
 * CAD Tools - KiCAD (for Schematic Design, PCB Design, Net List, Gerber file) [Software](http://www.kicad-pcb.org/display/KICAD/KiCad+EDA+Software+Suite)

## Useful Tutorials
* [Learning about electronics - Digital](http://www.learnabout-electronics.org/Digital)
* [Transistors](http://www.electronics-tutorials.ws/transistor)
* [Using make with Arduino Uno](https://www.ashleymills.com/node/327)
 



                
  
