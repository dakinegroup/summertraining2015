#include <stdio.h>
int main()
{

	int led=0, count[1000], i=0, sum=0;
	
	while(led==0)
	{ 
		printf("on/off\n");
		scanf("%d",&led);
		//pres 0 to put led off...that will count 1...if no object is passed count is 0 then press 1.....to end loop press anything else.
		if (led==1)
		{ 
			count[i]=led;
			printf("%d",count[i]);
			sum=sum+count[i];
			i=i+1;
			led = 0;
		}

			
	}
			printf("%d",sum);
		

}
