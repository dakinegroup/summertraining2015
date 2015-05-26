#include <stdio.h>
int main()
{
	int duration[]={5,2,3};
	int i,j, k;
	int poles[4]={0x09,0x01,0x01,0x04};
	int tick=0;
	while (1)
	{
		tick++;
		for (i = 0; i < sizeof(poles) / sizeof(int); i++)
		{
			if ((poles[i] & 0x06) !=0) {
				j=i;
				break;
			}
		}
		if (poles[j]==0x02)
		{
			if (tick>=duration[1])
			{
				poles[j]=0x04;
				tick=0;
			    poles[(j+1)%4]=0x09;
			}
		}
		else if (poles[j]==0x04)
		{
			if (tick>=duration[2])
			{
				poles[j]=0x01;
				tick=0;
			    poles[(j+1)%4]=0x02;
			}
		}
		for( k=0; k < sizeof(poles)/sizeof(int); k++){
			printf("%0x ",poles[k]);			
		}
		printf("\n");
		sleep(1);
	}
}
