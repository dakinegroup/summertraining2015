#include <stdio.h>
#include <unistd.h>
int main()
{	int counter=0,a,dur=20;
	int b;
     printf("enter sleep time");
     scanf("%d",&b);
    /* do
     {
 	usleep(b);
    counter++;
    a=counter;
    printf("%d\n",a);
   }while(counter!=20);*/
    do
    {
    	usleep(b);
    	counter++;
    	a=counter;
    	
	}while(counter<((dur*1000000)/b));
     printf("%d\n",a);
    
}