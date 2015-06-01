#Training Report (Summer 2015, Abhinav Ghai)

##Organization Overview

###About Organization

da Kine Technologies pvt. ltd. (DKTPL), started in 2010, was founded by 3 technology people. It started with an idea to create a product in education which can help connect tutors to remote students. Later it ventured into various other projects and products in the domain of automation - ERP, CRM and System Solutions.

###Technologies

DKTPL current focus area is internet technologies, though the abilities cover quite a vast area in terms of creating a full-fledged solution with knowledge of electronics and software. Currently, in their projects, they use different frameworks like PhoneGap, Ionic, Android - SDK, NodeJs, AngularJs and several other frameworks from PHP to create solutions for small businesses in managing their resources, delivering services to their end customers.

###Products

DKTPL is a research and development organization, enaged in creating products that enable SME (small and medium scale industries) to automate e.g. ComLiive (customer - vendor networking solution), dietician providing diet services through mobile apps, embedded automation solutions around micro-controllers, sensors.

##Synopsis of Training
6 weeks of training at DKT enabled exposure to mix of software and hardware practical knowledge. During this period, there were couple of visits to Industries to see use of electronics and software. Electronics and software are interdependent disciplines and together serve several industries, via automation, recording, anutioalysis etc. Electronics enables the capturing, access to the real world, while software is much bigger pie as it explores various possibilities of application of data and controls.

Knowledge in C-Language and digital electronics was heavily used and further strengthened while trying to implement new things. Logical reasoning and conceptualising / doing things on paper is key to design and solving problems using software and hardware.

Electronics advances in low powered devices, smaller footprints and revolution in addressability is enabling to dumb physical devices like watches, shoes as intelligent devices. Software is able to reach and collect data from remotest possible items that human being may be using. This is generating exabytes of data and hence throwing lot of information which is being analysed through advanced statistical techniques using software to make predictions and optimizations in operations.

Overall, world of software and hardware, when fused together to open new world of possibilities is quite exciting. For me it is just a beginning.

##Learnings - Software

### Learning - Linux
[Click here](learning_linux.md)
### Make Utility
[Click here](learning_linux.md)

### Object Oriented Design
TODO: Write a separate document for this topic and sub-topics
#### Objects and Classes
**Objects** - These are the things with independent runtime existance. These are entities in object oriented systems.  
At run time objects interact with each other by sending messages.  
**Class** - Class is a collection of objects of same type.  
For example - there are fruits in a basket like banana, orange and apple. In this example fruit is a class and banana , orange and apple are its objects.
#### Inheritance 
It is the property in oop in which sub classes  inherit or acquire the properties of its main class.

#### Polymorphism
Means the ability to take more than on form.  
Consider a situation. There is a class names Area. It has three objects circle, square & triangle with functions area(circle), area(square) & area(triangle) respectively. But the operation area is different for all three figures. So polymorphism will be helpful in objects with different internal functions to show same external functions. 

#### Operator Overloading
It is the process in which a operator is asked to do different tast at different instances.  
For example - operation of addition adds two integers. But wern this operator is used in strings it forms a new string by concatenation.
#### Example Testing Code

##Learnings - Electronics

### Learning ATMEL328 Controller
[Click here](learning_atmel328.md)

### Learning 8051 Controller

### Learning AM335

### Learning Peripherals

**74HC595 - Serial in Paralle Out shift register**

**UART Chip**

**ULN2003 - Motor Driver**

##Learnings - Processes

##Learnings - New Technologies

### Internet of things

### High Speed Networks

##Learnings - Visit to Industries

### Factories visited

### Processes and Automation

### Scope of electronics and software in operations

##Learnings - Procurement

Following steps followed:

+ Solution Design
+ Prepare Bill Of Materials
+ Vendor Selection - research through internet and other known sources
+ In-Market research for costly items
+ Procurement
+ Components Entry / Management in ERP

##Learnings - CAD Design

KiCAD is an open source software on Ubuntu, which can be used for schematic design, routing PCB and sending the gerber files to manufacturer for getting the developed PCBs.

**TODO:** Capture various features within schematic design that you have learnt.

##Project - Traffic Lights

### Problem Statement
**Implement a logic for traffic lights of square.**  
Suppose there

### Solution Overview


### Schematic Diagram

### Snap of actual circuitry

#### Working on breadboard
![ATmega8 and Traffic Lights](images/IMG_20150601_110247.jpg)

![Arduino Uno and Traffic Lights](images/IMG_20150601_153505.jpg)

#### Working on PCB, hard-wired

### Extracts of code and explanation
#### Pushing data to shift register
```c
void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0;
     unsigned int data = 0xFFFF - dat1;
    for(i=0;i<16;i++) {
      
      digitalWrite(8, data & 0x01);
      data = data >>1;
      digitalWrite(13, HIGH); 
      digitalWrite(13, LOW); 
    }
}
```

```c
if(tState & 0x02) {/*Yellow is on*/
        delay(duration[1]);
        startingState = (startingState & ~(0x0F << i*4)) | (0x04 << i*4) ;
       ...
} 
```

```
 if(i == 3) {
         /* Glow yellow led for 0th pole*/
         startingState = (startingState & ~0x0F) | (0x09) ;
       } else {
         /* Glow yellow led for next pole in sequence */
         startingState = (startingState & ~(0x0F << ((i+1)*4))) | (0x09 <<( (i+1)*4)) ;
         ...
}
```

##Project - Remote Monitor for analog levels

### Problem Statement

### Solution Overview

### Schematic Diagram

### Extracts of code and explanation

##Small Learning Projects

### Shifting bits

### Calculating Current voltage at collector for a transistor

