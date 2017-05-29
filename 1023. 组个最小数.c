#include <stdio.h>

int main()
{
	int s[10];
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&s[i]);
	}
	int length=0;
	for(i=0;i<10;i++)
	{
		length+=s[i];
	}	
	int r[length],j;
	for(i=0;i<length;i++)
	{
		if(i==0)j=1;
		else j=0;
		for(;j<10;j++)
		{
			if(s[j]>0)
			{
				s[j]--;
				break;
			}
		}
		r[i]=j;
	}
	for(i=0;i<length;i++)
	{
		printf("%d",r[i]);
	}
	printf("\n");
	return 0;
} 
