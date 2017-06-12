#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	int i,n[128],max=0;
	for(i=0;i<128;i++)
	{
		n[i]=0;
	}
	while((c=getchar())!='\n')
	{
		if(c>='A'&&c<='Z')c='a'+c-'A';
		n[c]++;
		if(max<n[c]&&c>='a'&&c<='z')
		{
			max=n[c];
		}
	}
	for(i=97;i<=122;i++)
	{
		if(n[i]==max)
		{
			printf("%c %d\n",i,max);
			break;
		}
	}
	
	return 0;
}
