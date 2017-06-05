#include <stdio.h> 

int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int ceng=0,n1=n,t=1+2*ceng;
	while(n1>=t)
	{
		if(t==1)
		{
			if(n1-t<0)break;
			n1=n1-t;
		}
		else 
		{
			if(n1-2*t<0)break;
			n1=n1-2*t;
		}
		ceng++;
		t=1+2*ceng;
	}
	int i,j,t1=1+2*(ceng-1);
	for(i=ceng-1;i>=0;i--)
	{
		t=1+2*i;
		for(j=0;j<(t1-t)/2;j++)
		{
			printf(" ");
		}
		for(j=0;j<t;j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}
	for(i=1;i<ceng;i++)
	{
		t=1+2*i;
		for(j=0;j<(t1-t)/2;j++)
		{
			printf(" ");
		}
		for(j=0;j<t;j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}
	printf("%d\n",n1);
	return 0;
}
