#include <stdio.h>
#include <commonemittermake.h>
float ce(float B,float Vb,float Rb,float Rc)
{
	float Vc,Vbe=0.7,Ib,Ic,vcc=5;  
	Ib=(Vb-Vbe)/Rb;
	Ic=B*Ib;
	Vc=vcc-(Ic*Rc);
	return Vc;
}		