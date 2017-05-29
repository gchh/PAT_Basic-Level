#include <stdio.h>
#include <string.h>

int main()
{
	char n[1001];
	gets(n);
	char sz[10]={'0','1','2','3','4','5','6','7','8','9'};
	int s[10]={0,0,0,0,0,0,0,0,0,0};
	int i,j;
	for(i=0;i<strlen(n);i++)
	{
		for(j=0;j<10;j++)
		{
			if(n[i]==sz[j])
			{
				s[j]++;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(s[i]!=0)
		{
			printf("%d:%d\n",i,s[i]);
		}
	}
	return 0;
} 
