#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,num[1000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]); 
	}
	int a1=0,a2=0,a3=0,a5=0;
	float a4=0;
	int c1=0,c2=0,c4=0;
	for(i=0;i<n;i++)
	{
		if((num[i]%5==0)&&(num[i]%2==0))
		{
			a1+=num[i];
			c1++;
		}
		if(num[i]%5==1)
		{
			if(c2%2==0)a2+=num[i];
			else a2-=num[i]; 
			c2++;
		}
		if(num[i]%5==2)
		{
			a3++;
		}
		if(num[i]%5==3)
		{
			a4+=num[i];
			c4++;
		}		
		if(num[i]%5==4)
		{
			if(a5<num[i])a5=num[i];
		}		
	}
	if(c1==0)printf("N ");
	else printf("%d ",a1);
	if(c2==0)printf("N ");
	else printf("%d ",a2);	
	if(a3==0)printf("N ");
	else printf("%d ",a3);	
	if(c4==0)printf("N ");
	else printf("%.1f ",a4/c4);	
	if(a5==0)printf("N\n");
	else printf("%d\n",a5);
	return 0;	
} 
