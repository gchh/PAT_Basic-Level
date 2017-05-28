#include <stdio.h>
//#include <string.h>

int main()
{
	int n;
	char s[106][4];
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%s\n",s[i]);
	}	
	return 0;
} 
