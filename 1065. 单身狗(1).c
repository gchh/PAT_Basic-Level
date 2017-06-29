#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,a,b,pl[100000]={-1};
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		pl[a]=b;
		pl[b]=a;
	}
	int M;
	scanf("%d",&M);
	int j,k,c,pl_id[50000],ds_cnt=0,ds_id[100000]={0},cnt=0,max=0,min=100000,couple;//定义成pl_id[N]，当输入中有00000或00001时，得到的结果错误 
	for(i=0;i<M;i++)
	{
		scanf("%d",&c);
		ds_id[c]++;
		ds_cnt++;
		if(pl[c]>=0)
		{
			pl_id[cnt]=c;
			couple=0;
			for(k=0;k<cnt;k++)
			{
				if(c==pl[pl_id[k]])
				{
					couple=1;
					break;
				}
			}
			if(couple==1)
			{
				ds_id[c]=0;
				ds_id[pl[c]]=0;
				ds_cnt-=2;
			}
			cnt++;
		}
		if(max<c)max=c;
		if(min>c)min=c;
	}
	printf("%d\n",ds_cnt);
	for(i=min;i<=max&&ds_cnt>0;i++)
	{
		if(ds_id[i]>0)
		{
			if(ds_cnt==1)
			{
				printf("%05d\n",i,ds_id[i]);
				break;
			}
			else printf("%05d ",i,ds_id[i]);
			ds_cnt--;
		}
	}
	return 0;
}
//全部正确 
