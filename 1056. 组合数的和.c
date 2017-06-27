#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	int i,cnt=0,n[10],sum=0;
	while((c=getchar())!='\n')
	{
		if(c==' ')continue;
		n[cnt]=c-'0';
		for(i=0;i<cnt;i++)
		{
			sum+=n[i]*10+n[cnt];
			sum+=n[cnt]*10+n[i];
		}
		cnt++;
	}
	printf("%d",sum);
	return 0;
}
