#include <stdio.h>

int main()
{
	int length,shr;
	scanf("%d %d",&length,&shr);
	int num[101];
	int i,j;
	for(i=0;i<length;i++)
	{
		scanf("%d",&num[i]);
	} 
	int t;
	for(i=0;i<shr;i++)
	{
		t=num[length-1];
		for(j=length-1;j>0;j--)
		{
			num[j]=num[j-1];
		}
		num[0]=t;
	}
	for(i=0;i<length;i++)
	{
		if(i==length-1)printf("%d\n",num[i]);
		else printf("%d ",num[i]);
	} 		
	return 0;	
}
