#include <stdio.h>
#include <unistd.h>
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
  int i=0,counter=0,ctr1,ctr2,st,glt,b,c;
  unsigned int tState;
  shiftOutClockedData(startingState);   
  int tick = 0;                  
  int duration[]= {5,4,8};                         
do {
    tick++;

   for(i=0; i < 4; i ++) { 
     tState  = (startingState >> (i*4)) & 0x0F;
     if(tState & 0x01) {
       
     } else if(tState & 0x02) 
                 {
                 
              if (tick>=duration[1])
                {
                 startingState = (startingState & ~(0x0F << i*4)) | (0x04 << i*4) ;
                 tick=0;
                 if(i == 0) {

         startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x09 << ((i+3)*4)) ;
       } else {
        
         startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x09 <<( (i-1)*4)) ;
  
                }  
                shiftOutClockedData(startingState);
        
        
      }
     } else if(tState & 0x04) {
      printf("enter sleep time\n");
                  scanf("%d",&st); 
                  do
                  {
                    sleep(st);
                    counter++;
                    ctr1=counter;
                    tick++;
                  }while(counter<((duration[2])/st));
                  printf("%d\n",ctr1);
                  counter=0;
                   printf("enter sleep time2\n");
                  scanf("%d",&st); 
                  do
                  {
                    sleep(st);
                    counter++;
                    ctr2=counter;
                    
                    tick++;
                  }while(counter<((duration[2])/st));
                  printf("%d\n",ctr2);
                  counter = 0;
       
       if (tick>=duration[2])
      {
       if (ctr1 > ctr2)
        {
          b = 0x02;
          if (i==0 || i==1 || i==2)
          {
            startingState = ((b<<(i*4+4)) | ~(0xEEEE)) ^ ((0x01)<<(i*4+4));
          }
          else if (i==3)
          {
            startingState = (b | ~(0xEEEE)) ^ (0x01);
          }
          
        }
        else if (ctr1 < ctr2)
        {
          c = 0x02;
          if (i==0 || i==1)
          {
            startingState = ((c<<(i*4+8)) | ~(0xEEEE)) ^ ((0x01)<<(i*4+8));
          }
          else if (i==2)
          {
            startingState = (c | ~(0xEEEE)) ^ (0x01);
          }
          else if (i==3)
          {
            startingState = ((c<<4) | ~(0xEEEE)) ^ (0x01<<4); 
          }
          
        } 
  shiftOutClockedData(startingState);
  
      }

      } else if(tState & 0x08) {
        
     }
   }

   sleep(1);  
  } while (1);
}




