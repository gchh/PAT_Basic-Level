#include <stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    return *(double*) a-*(double*) b;
}

int main()
{
	int n;
	double p;
	scanf("%d %lf",&n,&p);
	int i,j;
	double num[n],max=0;//,min=1000000000;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&num[i]);
		//if(max<num[i])max=num[i];
		//if(min>num[i])min=num[i];
	}
#if 0 //测试点4 运行超时 
	double t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(num[j]>num[j+1])
			{
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}
	}
#else
	qsort(num,n,sizeof(num[0]),cmp);
#endif

#if 0 //测试点4 运行超时 
	int s1,s2;
	s1=(int)(max/p);
	s2=s1+1;	
	int cnt1=0,cnt2=0,c1=-1,c2=-1;
	for(i=0;i<n;i++)
	{
		if(num[i]>=s1&&num[i]<=s1*p)
		{
			if(c1==-1)c1=i;
			cnt1++;
		}
		if(num[i]>=s2&&num[i]<=s2*p)
		{
			if(c2==-1)c2=i;
			cnt2++;
		}		
	}
	
	int c3;
	if(cnt1>=cnt2)c3=c1;
	else c3=c2;
	int cnt3,cnt_max=0;
	for(i=0;i<c3;i++)
	{
		cnt3=0;
		for(j=0;j<n;j++)
		{
			if(num[j]>=num[i]&&num[j]<=num[i]*p)
			{
				cnt3++;
			}
		}
		if(cnt_max<cnt3)cnt_max=cnt3;
	}
	
	if(cnt_max>=cnt1&&cnt_max>=cnt2)printf("%d\n",cnt_max);
	else if(cnt1>=cnt2)printf("%d\n",cnt1);
	else printf("%d\n",cnt2);
#else
#if 0 //测试点4 运行超时 
	int cnt3,cnt_max=0;
	for(i=0;i<n;i++)
	{
		cnt3=0;
		for(j=i;j<n&&num[j]<=num[i]*p;j++)
		{
			cnt3++;
		}
		if(cnt_max<cnt3)cnt_max=cnt3;
	}
	
	printf("%d\n",cnt_max);
#else
	int cnt3=0,cnt_max=0;
	for(i=0;i<n;i++)
	{
		for(j=cnt3;j<n;j++)
		{
			if(num[j]>num[i]*p)break;
			if(j-i>=cnt_max)cnt_max = j-i+1;
		}
		cnt3=j;
	}
	
	printf("%d\n",cnt_max);
#endif
#endif	
	return 0;
} 

