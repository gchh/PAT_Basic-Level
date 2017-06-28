#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,n[N][2];
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&n[i][0],&n[i][1]);
	}
	int M;
	scanf("%d",&M);
	int j,k,a,db[N],cnt=0,id[100000]={0};
	for(i=0;i<N;i++)db[i]=0;
	for(i=0;i<M;i++)
	{
		scanf("%d",&a);
		id[a]++;
		for(j=0;j<N;j++)
		{
			for(k=0;k<2;k++)
			{
				if(a==n[j][k])
				{
					db[j]++;
					break;
				}
			}
			if(db[j]>0)break;
		}
		if(db[j]==2)
		{
			cnt++;
			id[a]++;
			id[n[j][1-k]]++;
		}
	}
	int dcnt=M-cnt;
	printf("%d\n",dcnt);
	for(i=0;i<100000;i++)
	{
		if(id[i]==1)
		{
			if(dcnt==1)printf("%05d\n",i);
			else printf("%05d ",i);
			dcnt--;
		}
	}
	return 0;
}
