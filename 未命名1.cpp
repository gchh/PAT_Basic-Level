#include <stdio.h>

int main()
{
	int n;
	double p;
	scanf("%d %lf",&n,&p);
	int i;
	double num[n],max=0.0;//,min=1000000000;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&num[i]);
		if(max<num[i])max=num[i];
		//if(min>num[i])min=num[i];
	}
	double s1,s2;
	s1=max/p;
	s2=s1+1;
	double cnt1=0.0,cnt2=0.0;
	for(i=0;i<n;i++)
	{
		if(num[i]>=s1&&num[i]<=s1*p)
		{
			cnt1=cnt1+1;
		}
		if(num[i]>=s2&&num[i]<=s2*p)
		{
			cnt2=cnt2+1;
		}		
	}
	if(cnt1>=cnt2)printf("%.0lf\n",cnt1);
	else printf("%.0lf\n",cnt2);
	return 0;
} 
