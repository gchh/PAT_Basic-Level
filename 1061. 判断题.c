#include <stdio.h>

struct Ti{
	int score;
	int daAn;
};
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	struct Ti ti[M];
	int i;
	for(i=0;i<M;i++)
	{
		scanf("%d",&ti[i].score);
	}
	for(i=0;i<M;i++)
	{
		scanf("%d",&ti[i].daAn);
	}
	int j,chengji[N],da;
	for(i=0;i<N;i++)chengji[i]=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d",&da);
			if(da==ti[j].daAn)chengji[i]+=ti[j].score;
		}
		printf("%d\n",chengji[i]);
	}
	return 0;
}
