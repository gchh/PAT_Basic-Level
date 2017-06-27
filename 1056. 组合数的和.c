#include <stdio.h>

int main()
{
	int N,i,cnt=0,n[10],sum=0;
	scanf("%d",&N);
	while(cnt<N)
	{
		scanf("%d",&n[cnt]);
		for(i=0;i<cnt;i++)
		{
			sum+=n[i]*10+n[cnt];
			sum+=n[cnt]*10+n[i];
		}
		cnt++;
	}
	printf("%d\n",sum);
	return 0;
}
