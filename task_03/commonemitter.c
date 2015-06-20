#include <stdio.h>
float ce(float B,float Vb,float Rb,float Rc);
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
float ce(float B,float Vb,float Rb,float Rc)
{
	float Vc,Vbe=0.7,Ib,Ic,vcc=5;  
	Ib=(Vb-Vbe)/Rb;
	Ic=B*Ib;
	Vc=vcc-(Ic*Rc);
	return Vc;
}				