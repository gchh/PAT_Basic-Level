#include <stdio.h>

struct PL{
	int a_id;
	int b_id;
	int a_cnt;
	int b_cnt;
};
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	struct PL pl[N];
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&pl[i].a_id,&pl[i].b_id);
		pl[i].a_cnt=0;
		pl[i].b_cnt=0;
	}
	int M;
	scanf("%d",&M);
	int j,a,ds_cnt=0,ds_id[100000]={0};
	for(i=0;i<M;i++)
	{
		scanf("%d",&a);
		ds_id[a]++;
		ds_cnt++;
		for(j=0;j<N;j++)
		{
			if(a==pl[j].a_id)
			{
				pl[j].a_cnt++;
				break;
			}
			if(a==pl[j].b_id)
			{
				pl[j].b_cnt++;
				break;
			}
		}
		if(pl[j].a_cnt==pl[j].b_cnt&&pl[j].b_cnt>0&&j<N)
		{
			ds_id[pl[j].a_id]=0;
			ds_id[pl[j].b_id]=0;
			ds_cnt-=2;
		}
	}
	printf("%d\n",ds_cnt);
	for(i=0;i<100000;i++)
	{
		if(ds_id[i]>0)
		{
			if(ds_cnt==1)printf("%05d\n",i);
			else printf("%05d ",i);
			ds_cnt--;
		}
	}
	return 0;
}
//测试点3和4，运行超时 
