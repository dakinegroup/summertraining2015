#include <stdio.h>
int main()
{
	long int bn, dn=0, n=1, remainder;
	printf("enter binary number");
	scanf("%ld",&bn);
	while(bn!=0)
	{
		remainder=bn%10;
		dn=dn+(remainder*n);
		n=n*2;
		bn=bn/10;
	}
	printf("decimal number is=%ld\n",dn);
	if ((dn==12)||(dn==15))
	{
		printf("Red will blink");
	}
	else if ((dn==13)||(dn==14)||(dn==7))
	{
		printf("yellow will blink\n");
	}
	else if ((dn==20)||(dn==16))
	{
		printf("green will blink\n");
	}
	else
	{
		printf("black will blink\n");
	}
}
