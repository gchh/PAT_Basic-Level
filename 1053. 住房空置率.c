#include <stdio.h>

int main()
{
	int n,d;
	double e;
	scanf("%d %lf %d",&n,&e,&d);
	int i,j,k,maybe=0,real=0,cnt;
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		double ex[k];
		cnt=0;
		for(j=0;j<k;j++)
		{
			scanf("%lf",&ex[j]);
			if(ex[j]<e)cnt++;
		}
		if(cnt>k/2&&k>d)
		{
			real++;
		}
		else if(cnt>k/2)maybe++;
	}
	printf("%.1lf%% %.1lf%%\n",(maybe*100.0)/n,(real*100.0)/n);
	return 0;
}
