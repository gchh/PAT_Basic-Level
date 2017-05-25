#include <stdio.h>
#include <math.h>

int isPrime(int x)//ÅĞ¶ÏÊÇ·ñÊÇËØÊı 
{
	int isPrime,i;
	isPrime=1;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			isPrime=0;
			break;
		}
	}
	return isPrime;
}
int main()
{
	int prime[10001],isprime;
	int i=2,cnt=0;
	while(cnt<10001)
	{
		isprime=isPrime(i);
		if(isprime==1)
		{
			prime[cnt]=i;
			cnt++;
		}
		i++;
	}
	int m,n;
	scanf("%d %d",&m,&n);
	for(i=m-1;i<n;i++)
	{
		if(((i-(m-1)+1)%10==0)||(i==n-1))printf("%d\n",prime[i]);
		else printf("%d ",prime[i]);
	}
	return 0;
} 
