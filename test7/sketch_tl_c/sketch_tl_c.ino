/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);  
  pinMode(8, OUTPUT);    
  digitalWrite(13, LOW); 
  
}

void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0;
     unsigned int data = 0xFFFF - dat1;
    for(i=0;i<16;i++) {
      
      digitalWrite(8, data & 0x01);
      data = data >>1;
      //delay(500); 
      digitalWrite(13, HIGH); 
     // delay(500); 
      digitalWrite(13, LOW); 
    }
      delay(10000);  
}
void loop() {
  /* main logic of traffic light shall work from here */
  int duration[2] = {3000, 1000}; 
  //int tick = 0;
  int i = 0, tState = 0;
  /* 0th pole is BIT:0-3, 1st pole: BIT:4-7, 2nd pole: BIT:8:11, 3rd pole: BIT:12:15*/
  unsigned int startingState = 0x9114;
   shiftOutClockedData(startingState);
do {
   for(i=0; i < 4; i ++) { /* go over all the traffic poles */
     /* which is green right now */
     /* first get the pole */
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) {/* Red is on */
       
     } else if(tState & 0x02) {/*Yellow is on*/
        delay(duration[1]);
        startingState = (startingState & ~(0x0F << i*4)) | (0x04 << i*4) ;
        if(i == 3) {
         /* Glow yellow led for 0th pole*/
         startingState = (startingState & ~0x0F) | (0x09) ;
       } else {
         /* Glow yellow led for next pole in sequence */
         startingState = (startingState & ~(0x0F << ((i+1)*4))) | (0x09 <<( (i+1)*4)) ;
  shiftOutClockedData(startingState);
      }
     } else if(tState & 0x04) {/*Green is on */
       delay(duration[0]);
       startingState = (startingState & ~(0x0F << i*4)) | (0x01 << i*4) ;
       if(i == 3) {
         /* Glow yellow led for 0th pole*/
         startingState = (startingState & ~0x0F) | (0x02) ;
       } else {
         /* Glow yellow led for next pole in sequence */
         startingState = (startingState & ~(0x0F << ((i+1)*4))) | (0x02 << ((i+1)*4)) ;
       }
  shiftOutClockedData(startingState);
    } else if(tState & 0x08) {/* Left is on */
        
     }
   }  
  } while (1);
  
  /*
  
  */
}
