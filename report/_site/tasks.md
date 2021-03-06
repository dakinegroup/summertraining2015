#task1
checking out compilation etc..

#task2
checking out make

#task3
first program to find Vc in transitor circuit

#task4
implement truth table as per following

|Var A| Var B | Var C | Var D |Var E|Output|
|----|-----|----|------|----|----|
|0| 1 | 1| 0 |0| Red|
| 0 | 1 | 1| 1| 1| Red |
| 0 | 1 | 1| 0|1| Yellow|
| 0 | 1 | 1| 1|0| Yellow|
| 1 | 0 | 1| 0| 0| Green|
| 1 | 0 | 0 | 0| 0| Green|
| 0 | 0 | 1| 1|1| Yellow|



Other combinations by default give - Black as output

Using bit-wise operators, find out codes for following set of values in an array

Values are: 10, 11, 31, 52, 12, 4, 19
Also, using programmatically, first display how many possible input combinations are possible.

Lets complicate this a bit more, by inserting a state variable in above truth table..
Lets call it as S1. S1 becomes 0 if VarA stays 0 for 5 times. If S1 becomes 0, whatever was output, it moves to the next state and round robbin. for example if it was Red, it will change to Yellow, if it was Yellow --> it will change to Green, if it is Green, it will change to Red. If it was in Black, it will stay there till right conditions are reached. If this condition is detected and present output is non-black, than irrespective of new values of variables, state detection and output change shall take place.

#task5
Lets start to simulate a scenario where data is coming from an analog sensor. DAC is providing digital equivalent of this (source could be humidity sensor, teperature etc..). We assume that this vector data is available in the form of a file. Value is 32 bit data (i.e. 2 bytes for data point).

Install a timer in your code, to read this data every 100ms.

Create a trigger value which shall display - 'On' or 'Off' for a control based on the vector data read every 100ms. While it displays output, it should also display what was the data input at that point.



Above logic is to 
* stimulate state management thinking.. and digital logic
* learn timer
* understand emulation of external data inputs and system output
* evolving requirements
* organizing code into functions, files and make as is already learnt

#task6 - 7

Create software logic to simulate traffic lights, with following problem statement

* It is four roads crossing with each one two way
* Red light, Yellow and Green lights glow for durations which should be configurable through variable settings
* Green light gives way to all the three directions. For example: if traffic is coming from south, it shall be able to go to North, east and west.
* Green signal shall move in clock-wise direction i.e. if now traffic is coming from south, than next will be from west  and so on..
* Traffic adjacent to active (green) signal shall be able to move to it's left side freely
* while doing the above, keep in mind, the software so written should be able to support hardware, where we are limited by number of output pins
* for example: 4 nibbles or 2 bytes i.e. 16 bits should be sufficient to hold state of all the lights on four poles
* write a function to emit these two bytes in serial manner that complies with 74HC594. This will consume 3 pins.
* Draw circuit diagram capturing use of this IC
* Once a working circuit is created on breadboard and software is working, enhance it further as per following
* Put a DIP switch to change the timings of the traffic lights on the fly. These are as following:
   
    |SW 3 | SW 2 | SW 1 | SW 0 | Duration - Green | Duration - Yellow|
    |----|---|----|----|----|----|
    |1|1|1|0| 1000|300|
    |1|1|0|1| 5000|500|
    |1|1|0|0| 15000|1000|
    |1|0|1|1| 60000|2000|

* Once this is also done, further enhance the functionality, to do remote control of these lights for following things

  |#|Command (Hex)| Response (Hex) | Command Description |
  |---|---|---|---|
  |1|0x01| - | To resume traffic light sequence|
  |2|0x02| - | To stop traffic light sequence in state where it is, even if it is yellow somewhere|
  |3|0x03 #pole| - | To make green for the pole, defined by #pole. It can take values 0x01 - 0x04|
  |4|0x04| GREEN-MSB, GREEN-LSB, YELLOW-MSB, YELLOW-LSB | To get currently active duration setings. CPU shall respond with train of 4 bytes capturing the values of green and yellow light duration|
  |5|0x05| #status #optional-pole| Get Currrent status - Status -> can take values 0x01 - Normal, 0x02 - Emergency stop, 0x03 - Pole permanent Green followed by pole which is permanent green|
  
   For above, UART communication is required (partly discussed in task8), where from serial console, user shall give commands to the remote CPU and fetch status / change the status
   
Above needs to be replicated with raw unit (earlier it was Uno kit). Following challenges will need to be overcome:

* UART interface
* PIN support library not available in same format in regular gcc based project

Further extend this to support (optional)

* Make it four lights and 6 crossings. See if your software is scalable.

#task8

Implement echo loop with serial communication port of atmel controller.
Do serial out on one port, loop tx with Rx and read Rx register, if it is same as was transmitted. If yes, you are now able to use UART registers

Connect UART input to UART to USB connector and loop it up on the USB connector and conduct same test. If again results are good, proceed.

Now write windows driver (or pick from internet) to read serial data from USB and display it on the terminal. On windows, use hyperterm to read such data.

If above is successful, you understand serial communications and lets move further to make a communications application.

On controller board lets read voltage from analog source 0 - 5V and send to the machine the digital value, which should be displayed by the software.

Lets extend this further, we put up 4 such cards on a bus. What needs to be done now? Think about addressing, conflicts etc. There is no LAN port, we can't do LAN solution, however, is there any solution that can be deployed here? HInt: RS485, Master Slave, One-Wire

#task8

Visit to lajpat Rai Market to buy some components for project work
Create inventory of items in excel sheet
List of components to buy:
* 74HC594, 74HC164
* PCF 8574
* 74HC00, 74HC04, 74HC14, 74HC86, x 2 each
* 74HC390 - BCD counter
* 7 Segment Displays x 8
* ATMEL 328 chip
* More LEDs
* 9-pin d connector female x 4
* 9-pin d connector male x 4
* 16F887(pref) x 2, 16F886 or 16877 -- module
* 8051 kit
* Cordless battery
* max485 x 10
* max232 x 2
* 120ohm x 10
* 470ohm x 10
* 1uf x 5
* 100uf x 5
* LCD module x 2
* Wifi wifi shield
* xbee development kit / arduino shield, XBee 2mW Wire Antenna
* LED bulbs 11w
* 74FST3257 - De-Multiplexer
* 74HC153 x 2
* 74HC257 x 2
* 74HC85 x 2
* 74HC148 x 2
* 74HS48 x 2 - 7 segment LED decoder
* Transistors - NPN: BC182 x 10, BC184 x 10, 2N3055 x 2, BC107 x 2
* Female Connectors x 20
* Veroboard x 2
* 28 pin base
* Ribbon wire
* Potentio meter
* induction coil?? -- varying
* 

#task9
It was time to extend the USART synchronous implementation done so far to asynchronous one, with help of interrupt. A ping-pong buffer was used, which has it's limitations. Later it may be changed to circular buffer, an ideal solution for our use.

Also, timer interrupt handling was implemented. It was help get precise timing information for task scheduling in traffic light system.

#task10
Here the objective was to make LCD work in our hardware setup. RG1602A - 16x2 display was used. We put up shift register to minimize use of controller pins at the cost of performance. A dedicated driver code is required to make the text visible on LCD, by way of using clocks, serial data.

#task11
Here the objective is to detect pulse because of interruption in the reflected IR ray from our sensors. This is to be used later in project to count traffic load.