#include <stdio.h>
#include <string.h>

int main()
{
	int i, s[128],p[128];
	for(i=0;i<128;i++)
	{
		s[i]=0;
		p[i]=0;
	}
	char c;
	while((c=getchar())!='\n')
	{
		s[c]++;
	};
	while((c=getchar())!='\n')
	{
		p[c]++;
	};	
	
	int duo=0,shao=0;
	for(i=48;i<=122;i++)
	{
		if(p[i]>0)
		{
			if(s[i]>=p[i])
			{
				s[i]=s[i]-p[i];
			}
			else
			{
				shao+=p[i]-s[i];
			}
		}
	}
	if(shao>0)printf("No %d",shao);
	else
	{
		for(i=48;i<=122;i++)
		{
			if(s[i]>0)duo+=s[i];
		}
		printf("Yes %d",duo);
	}
	return 0;
} 
