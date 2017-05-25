#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	long s[10][3];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%ld %ld %ld",&s[i][0],&s[i][1],&s[i][2]);
	}
	for(i=0;i<n;i++)
	{
		printf("Case #%d: ",i+1);
		if(s[i][0]+s[i][1]>s[i][2])printf("true\n");
		else printf("false\n");
	}	
	return 0;	
} 
