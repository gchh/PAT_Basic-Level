#include <stdio.h>

int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	int i,num[n],max=0;//,min=1000000000;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if(max<num[i])max=num[i];
		//if(min>num[i])min=num[i];
	}
	int s1,s2;
	s1=max/p;
	s2=s1+1;
	int cnt1=0,cnt2=0;
	for(i=0;i<n;i++)
	{
		if(num[i]>=s1&&num[i]<=s1*p)
		{
			cnt1++;
		}
		if(num[i]>=s2&&num[i]<=s2*p)
		{
			cnt2++;
		}		
	}
	if(cnt1>=cnt2)printf("%d\n",cnt1);
	else printf("%d\n",cnt2);
	return 0;
} 
