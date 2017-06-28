#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,d[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&d[i]);
	}
	int t=N,dt=0;
	while(t>=dt)
	{
		dt=0;
		for(i=0;i<N;i++)
		{
			if(d[i]>t)dt++;
		}
		t--;
	}
	printf("%d\n",t+1);
	return 0;
}
