#include <stdio.h>
char * getBinaryString(unsigned int);
void runTrafficLight(unsigned int);
int main()
{
	unsigned int a=0x9114;
	runTrafficLight(a);
}

char binaryString[50];
char * getBinaryString(unsigned int bytes) {
	int i = 0;
	for(;i<16; i++) {
		binaryString[i*2] =  ((bytes << i)&0x8000)?'1':'0';
		binaryString[i*2+1] = ' ';
	}
	binaryString[i*2] = 0;
	return &binaryString[0];
}

void shiftOutClockedData(data) {
	printf("%s\n", getBinaryString(data));
}
void runTrafficLight(unsigned int startingState) {
	int i=0;
	unsigned int tState;
	shiftOutClockedData(startingState);
do {
   for(i=0; i < 4; i ++) { /* go over all the traffic poles */
     /* which is green right now */
     /* first get the pole */
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) {/* Red is on */
       
     } else if(tState & 0x02) {/*Yellow is on*/
        //delay(duration[1]);
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
       //delay(duration[0]);
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
   sleep(1);  
  } while (1);
}