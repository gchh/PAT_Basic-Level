#include <stdio.h>

int main()
{
	int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	int s;
	s=a+b;
	int quotient,remainder,cnt=0,r[33];
	do
	{
		quotient=s/d;
		remainder=s%d;
		s=quotient;
		r[cnt]=remainder;
		cnt++;
	}while(s!=0);//先do，是为了处理输入a和b都是0的情况 
	int i;
	for(i=cnt-1;i>=0;i--)
	{
		printf("%d",r[i]);
	}
	printf("\n");
	return 0;
} 
