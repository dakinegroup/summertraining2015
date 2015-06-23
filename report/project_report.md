#Training Report (Summer 2015, Abhinav Ghai)

##Organization Overview

###About Organization

da Kine Technologies pvt. ltd. (DKTPL), started in 2010. It started with an idea to create a product in education which can help connect tutors to remote students. Later it ventured into various other projects and products in the domain of automation - ERP, CRM and System Solutions. Embedded is one of the important aspects to connect to the data sensing and control components of the solutions offered.

###Technologies

DKTPL current focus area is internet technologies, though the abilities cover quite a vast area in terms of creating a full-fledged solution with knowledge of electronics and software. In their projects, they use different frameworks like PhoneGap, Ionic, Android - SDK, NodeJs, AngularJs and several other frameworks from PHP to create solutions for small businesses to manage their resources, delivering services.

###Products

DKTPL is a research and development organization, enaged in creating products that enable SME (small and medium scale industries) to automate e.g. ComLiive (customer - vendor networking solution), dietician providing diet services through mobile apps, automation solutions around micro-controllers.

##Synopsis of Training
6 weeks of training at DKT enabled exposure to mix of software and hardware practical knowledge. During this period, there were couple of visits to Industries to see use of electronics and software. Electronics and software are interdependent disciplines and together serve several industries, via control systems, data sensing, data recording, analysis. Electronics enables the capturing, access to the real world, while software is much bigger pie as it explores various possibilities of application of data and controls on the same hardware.

Electronics advances in low powered devices, smaller footprints and revolution in addressability is enabling to dumb physical devices like watches, shoes as intelligent devices. Software is able to reach and collect data from remotest possible items that human being may be using. This is generating exabytes of data and hence throwing lot of information which is being analysed through advanced statistical techniques using software to make predictions and optimizations in operations.

Knowledge in C-Language and digital electronics was mostly used in the training and further strengthened while trying to implement new things. Logical reasoning and conceptualising / doing things on paper is key to design and solving problems using software and hardware.

Traffic Lights was a project used as a means to get exposed to all the ground level work for creating systems. We started from experimenting with individual components, integrating them as single system and evolving software to deal with complex situations. It was interesting to see, how things can become complex from seemingly a simple solutions.

Overall, world of software and hardware, when fused together to open new world of possibilities is quite exciting. For me it is just a beginning.

##Learnings - Software

### Learning - Linux
[Click here](learning_linux.md)
### Make Utility
[Click here](learning_linux.md)

### Object Oriented Design

[Click here](oops.md)

#### Example Testing Code

##Learnings - Electronics

### Learning ATMEL328 Controller
[Click here](learning_atmega8.md)

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

#### Scheduler
A major challenge for the system to operate without operating system and having multiple tasks at hand was to make sure how all can be done without compromising the timing requirements. For example: every second, status for incoming traffic should be checked and also status for all traffic lights to be updated. Other tasks that were to be performed are:
* Sending display information to remote terminal
* Receiving user commands and process when a valid command is received
* Display to LCD terminal
* Read configuration switch for any changes

Using 16-bit timer and function pointers above requirement was fulfilled. A code extract to explain this is captured below.

```c
  // in main code, this is the way a task was scheduled.
  // it says.. in 1 second repeat task called toggleDebugLed
  repeat(1000, toggleDebugLed);

  // here is how in a infinite loop, scheduled items are triggered for invocation
  while(1) {
    asm("nop");
    invokeScheduledItem(); // includes - TL updat

  // this is the call back called in above 'repeat'
  int toggleDebugLed(int x) {
    if(debug_led == 0) {
      debug_led = 0x01;
      PORTB = PORTB | _BV(1);
    } else {
      debug_led = 0;
      PORTB = PORTB & ~(_BV(1));
    }
    return 0;
  }

  // structure used to store task information
  struct {
    int empty;
    int timestamp[2];
    tTimedCallBack cb;
    int recurrence;
  } scheduledItems[10];

  // register a task for repetition after ms interval
  void repeat(int ms, tTimedCallBack cb) {
  int i = 0;

    //add scheduled item to the queue
    for (i = 0; i < 10; i++) {
        if(scheduledItems[i].empty) {
            cli();
            scheduledItems[i].timestamp[0] = timestamp[0];
            scheduledItems[i].timestamp[1] = timestamp[1];
            sei();
            scheduledItems[i].timestamp[0] += ms;
            scheduledItems[i].recurrence = ms;
            scheduledItems[i].cb = cb;
            
            scheduledItems[i].empty = 0;
            break;
        }
    }
  }


  void invokeScheduledItem() {
    int ts[2], i;
    char bytes[30];
    cli();
            ts[0] = timestamp[0];
            ts[1] = timestamp[1];
    sei();
    
    //retrieve scheduled item from queue and mark it free for reuse
    for (i = 0; i < 10; i++) {
        if(!scheduledItems[i].empty) {
            if(ts[0] > scheduledItems[i].timestamp[0]) {
                /*sprintf(bytes,"%02x%02x: Thr: %02d, CB: %04x\r\n", timestamp[1], timestamp[0], i, scheduledItems[i].cb);
                USART_Transmit_String2(bytes);*/
             if(scheduledItems[i].cb != 0) {
                (*scheduledItems[i].cb)(0);
            }
            scheduledItems[i].timestamp[0] += scheduledItems[i].recurrence;
            }                           
        }
    }
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

