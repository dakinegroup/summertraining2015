#include <stdio.h>
int main()
{
	int duration[]={35,5,40};
	int i,j;
	int poles[]={0x09,0x01,0x01,0x04};
	int tick=0;
	while (true)
	{
		tick++;
		for (i = 0; i < poles[i]; i++)
		{
			if (poles[i] & 0x06 !=0)
			i=j;
				break;
			
		}
		if (poles[j]==0x02)
		{
			if (tick>=duration[1])
			{
				poles[j]=0x04;
				tick=0;
			}
			poles[j+1]%4=0x09;
		}
		else if (poles[j]==0x04)
		{
			if (tick>=duration[2])
			{
				poles[j]=0x01;
				tick=0;
			}
			poles[j+1]%4=0x02;
		}
		printf("%d",poles[j]);
	}
}
