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
  pinMode(7,INPUT);
  digitalWrite(13, LOW); 
  
  Serial.begin(9600);
  
}

void shiftOutClockedData(unsigned int dat1) {
     unsigned int i, opser, srclk=0,val=0;
     unsigned int data = 0xFFFF - dat1;
    val=digitalRead(7);
    Serial.println(val);
    if (val==1){
    for(i=0;i<16;i++) {
      digitalWrite(8, data & 0x01);
      data = data >>1;
      //delay(500); 
      digitalWrite(13, HIGH); 
     // delay(500); 
      digitalWrite(13, LOW); 
    }
    }else{digitalWrite(8,LOW);}
      //delay(10000);  
}
void loop() {
  /* main logic of traffic light shall work from here */
  int duration[2] = {2000, 500}; 
  //int tick = 0;
  int i = 0, tState = 0;
  /* 0th pole is BIT:0-3, 1st pole: BIT:4-7, 2nd pole: BIT:8:11, 3rd pole: BIT:12:15*/
  unsigned int startingState = 0x9114;
   shiftOutClockedData(startingState);
do {
  Serial.println("startingState");
   for(i=0; i < 4; i ++) { /* go over all the traffic poles */
     /* which is green right now */
     /* first get the pole */
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) {/* Red is on */
       
     } else if(tState & 0x02) {/*Yellow is on*/
        delay(duration[1]);
        startingState = (startingState & ~(0x0F << i*4)) | (0x04 << i*4) ;
        if(i == 0) {
         /* Glow yellow led for 0th pole*/
       startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x09 << ((i+3)*4)) ;
       } else {
         /* Glow yellow led for next pole in sequence */
         startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x09 <<( (i-1)*4)) ;
      }
        shiftOutClockedData(startingState);
      printf("%0x",startingState);
     } else if(tState & 0x04) {/*Green is on */
       delay(duration[0]);
       startingState = (startingState & ~(0x0F << i*4)) | (0x01 << i*4) ;
       if(i == 0) {
         /* Glow yellow led for 0th pole*/
        	startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x02 << ((i+3)*4)) ;
       } else {
         /* Glow yellow led for next pole in sequence */
         startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x02 << ((i-1)*4)) ;
       }
  shiftOutClockedData(startingState);
  printf("%0x",startingState);
    } else if(tState & 0x08) {/* Left is on */
        
     }
   }  
  } while (1);
  
  /*
  
  */
}
