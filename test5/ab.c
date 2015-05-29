#include <stdio.h>
int main()
{
	int a=0x0801;
	int i, opser, srclk=0;
	for(i=0;i<16;i++)
	{
		opser = a & 0x01;
		printf("%d\t%0x\n",srclk,opser);
		srclk = 1;
		a = a>>1;
		opser = a & 0x01;
		printf("%d\t%0x\n",srclk,opser);
		srclk = 0;
	}
}