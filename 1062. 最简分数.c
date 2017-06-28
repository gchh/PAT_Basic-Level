#include <stdio.h>

int gcd(int a,int b)
{
	int n=a<b?a:b;//从ab中的最小值开始计算。
	while(n>=1)
	{
		if(a%n==0&&b%n==0)break;//最大公约数。
		n--;
	}
	return n;
}

int main()
{
	int N1,M1,N2,M2,K;
	scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
	double d1,d2;
	int n;
	d1=N1*1.0/M1;
	d2=N2*1.0/M2;
	if(d1>d2)//如果第一个分数比第二个分数大
	{
		n=N1;
		N1=N2;
		N2=n;
		n=M1;
		M1=M2;
		M2=n;
	} 
	int f1,f2;
	f1=(N1*K)/M1+1;
	if((N2*K)%M2!=0)f2=(N2*K)/M2;
	else f2=(N2*K)/M2-1;
	int i,g,f[f2-f1+1],cnt=0;
	for(i=f1;i<=f2;i++)
	{
		g=gcd(i,K);
		if(g>1)continue;
		f[cnt]=i;
		cnt++;
	}
	for(i=0;i<cnt;i++)
	{
		if(i==cnt-1)printf("%d/%d\n",f[i],K);
		else printf("%d/%d ",f[i],K);
	}
	return 0;
}
