#include <stdio.h>
int main()
{ 
int a[7][5], i, j;
	
	
	for(i=0;i<7;i++)
	{      
       for(j=0;j<5;j++)
	{
       		
       		scanf("%d",&a[i][j]);
	}	
	}
	for(i=0;i<7;i++)
	{      
       for(j=0;j<5;j++)
	{
		printf("%d",a[i][j]);  
    		printf("\t"); 
	}
	 	printf("\n");
	} 
}