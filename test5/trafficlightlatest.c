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
   int i=0,counter=0,st,glt; long int ctr1,ctr2;
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
              printf("set duration for green light");
              scanf("%d",&glt);
              duration[2]=glt;
                }  
                shiftOutClockedData(startingState);
        
        
      }
     } else if(tState & 0x04) {
      printf("enter sleep time\n");
                  scanf("%d",&st); 
                  do
                  {
                    usleep(st);
                    counter++;
                    ctr1=counter;
                    tick++;
                  }while(counter<((duration[2]*1000000)/st));
                  printf("%ld\n",ctr1);
                  counter=0;
                   printf("enter sleep time2\n");
                  scanf("%d",&st); 
                  do
                  {
                    usleep(st);
                    counter++;
                    ctr2=counter;
                    
                    tick++;
                  }while(counter<((duration[2]*1000000)/st));
                  printf("%ld\n",ctr2);
                  counter = 0;
       
       if (tick>=duration[2])
      {
        startingState = (startingState & ~(0x0F << i*4)) | (0x01 << i*4) ;
        tick=0;
       if (ctr1 > ctr2)
        {
          if (i==0 || i==1 || i==2)
          {
            startingState = (startingState & ~(0x0F<<((i*4)+4))) | (0x02<<((i*4)+4));
            if(i == 0)
              {
              startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x01 << ((i+3)*4)) ;
              }
            else 
              {
              startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x01 << ((i-1)*4)) ;
              }   
          }
          else if (i==3)
          {
            startingState = (startingState & ~(0x0F)) | 0x02 ;
            if(i == 0)
              {
              startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x01 << ((i+3)*4)) ;
              }
            else 
              {
              startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x01 << ((i-1)*4)) ;
              }   
            
          }
          
        }
        else if (ctr1 < ctr2)
        {
          if (i==0 || i==1)
          {
            startingState = (startingState & ~(0x0F<<((i*4)+8))) | (0x02<<((i*4)+8));
            if(i == 0)
              {
              startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x01 << ((i+3)*4)) ;
              }
            else 
              {
              startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x01 << ((i-1)*4)) ;
              }   
          }
          else if (i==2)
          {
            startingState = (startingState & ~(0x0F)) | 0x02;
            if(i == 0)
              {
              startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x01 << ((i+3)*4)) ;
              }
            else 
              {
              startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x01 << ((i-1)*4)) ;
              }   
          }
          else if (i==3)
          {
            startingState = (startingState & ~(0x0F<<4)) | (0x02<<4);
            if(i == 0)
              {
              startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x01 << ((i+3)*4)) ;
              }
            else 
              {
              startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x01 << ((i-1)*4)) ;
              }   
          }
          
        }
        else if(ctr1 == ctr2) 
        {
           if(i == 0)
            {
            startingState = (startingState & ~(0x0F << ((i+3)*4))) | (0x02 << ((i+3)*4)) ;
            }
        else 
            {
            startingState = (startingState & ~(0x0F << ((i-1)*4))) | (0x02 << ((i-1)*4)) ;
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









          /*  if(i==0 || i==1)
            {
              b=(startingState>>(i*4+4)) & 0x0F;
              c=(startingState>>(i*4+8)) & 0x0F;
            }

            else if(i==2)
            {
              b=(startingState>>(i*4+4)) & 0x0F;
              c=startingState & 0x0F;
            }
            else if(i==3)
            {
              b=startingState & 0x0F;
              c=startingState>>4 & 0x0F; 
            }*/
