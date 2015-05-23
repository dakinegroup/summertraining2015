#Electronics
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

14. 


                
  
