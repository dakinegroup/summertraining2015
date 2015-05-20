#test1
checking out compilation etc..

#test2
checking out make

#test3
first program to find Vc in transitor circuit

#test4
implement truth table as per following

| Var A | Var B | Var C | Var D  |Var E | Output |
|----|---|----|---|--|----|
| 0 | 1 | 1| 0| 0| Red |
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

#test5
Lets start to simulate a scenario where data is coming from an analog sensor. DAC is providing digital equivalent of this (source could be humidity sensor, teperature etc..). We assume that this vector data is available in the form of a file. Value is 32 bit data (i.e. 2 bytes for data point).

Install a timer in your code, to read this data every 100ms.

Create a trigger value which shall display - 'On' or 'Off' for a control based on the vector data read every 100ms. While it displays output, it should also display what was the data input at that point.



Above logic is to 
* stimulate state management thinking.. and digital logic
* learn timer
* understand emulation of external data inputs and system output
* evolving requirements
* organizing code into functions, files and make as is already learnt

#
