#include <stdio.h>

int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int h=n/2;
	if(n%2==1)h+=1;
	int i,j;
	for(i=0;i<h;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0||i==h-1)printf("%c",c);
			else
			{
				if(j==0||j==n-1)printf("%c",c);
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
