#include <stdio.h>
#include <commonemittermake.h>
float main()
{
	float b,vb,rb,rc,ic,ib,vc;
	printf("Enter current gain\n");
	scanf("%f",&b);
	printf("Enter base voltage\n");
	scanf("%f",&vb);
	printf("Enter base resistance\n");
	scanf("%f",&rb);
	printf("Enter collector resistance\n");
	scanf("%f",&rc);
vc=ce(b,vb,rb,rc);
printf("vc=%f volt\n",vc);
return 0;
}