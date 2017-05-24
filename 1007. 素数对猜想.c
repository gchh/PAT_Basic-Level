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
	int n;
	scanf("%d",&n);
	int prime[100000],isprime,count=0,i;
	for(i=2;i<=n;i++)
	{
		isprime=isPrime(i);
		if(isprime==1)
		{
			prime[count]=i;
			count++;
		}
	}
	//for(i=0;i<count;i++)
	//{
	//	printf("%d ",prime[i]);
	//}
	int num=0;
	for(i=0;i<count-1;i++)
	{
		if(prime[i+1]-prime[i]==2)num++;
	}
	printf("%d\n",num);
	return 0;	
} 
