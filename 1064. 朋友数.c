#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,a,b,cnt=0,p[40]={0};//输入最大的数是9999，其朋友数是36 
	for(i=0;i<N;i++)
	{
		scanf("%d",&a);
		b=0;
		while(a>0)
		{
			b+=a%10;
			a/=10;
		}
		p[b]++;
		if(p[b]==1)cnt++;
	}
	printf("%d\n",cnt);
	for(i=0;i<40;i++)
	{
		if(p[i]>0)
		{
			if(cnt==1)printf("%d\n",i);
			else printf("%d ",i);
			cnt--;
		}
	}
	return 0;
}
