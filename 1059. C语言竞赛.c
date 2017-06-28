#include <stdio.h>
#include <math.h>

int isPrime(int x)//判断是否是素数 
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
	int N;
	scanf("%d",&N);
	int i,ID[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&ID[i]);
	}
	int K;
	scanf("%d",&K);
	int j,id,checked[N],kidding,isprime;
	for(i=0;i<N;i++)checked[i]=0;
	for(i=0;i<K;i++)
	{
		scanf("%d",&id);
		kidding=1;
		for(j=0;j<N;j++)
		{
			if(id==ID[j])
			{
				kidding=0;
				if(checked[j]==0)
				{
					if(j==0)printf("%04d: Mystery Award\n",id);
					else if(j>=1)
					{
						isprime=isPrime(j+1);
						if(isprime==1)printf("%04d: Minion\n",id);//素数 
						else printf("%04d: Chocolate\n",id);
					}
				}
				else printf("%04d: Checked\n",id);
				checked[j]=1;
				break;
			}
		}
		if(kidding==1)printf("%04d: Are you kidding?\n",id);
	}
	return 0;
}
