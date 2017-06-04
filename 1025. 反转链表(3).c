#include <stdio.h>

struct node{
	int addr;
	int num;
    int next;
};

int main()
{
	int frist_node_address,node_number,fz_node_number;
	scanf("%d %d %d", &frist_node_address,&node_number,&fz_node_number);
	struct node LB[node_number];
	int i;
	for(i=0;i<node_number;i++)
	{
		scanf("%d %d %d", &LB[i].addr,&LB[i].num,&LB[i].next);
	} 

	if(frist_node_address==-1)
	{
		printf("-1\n");
		return 0;
	}

	int cnt=0,j=0;
	int caddr=frist_node_address,cnum,cnext;
	while(j<node_number)
	{
		for(i=0;i<node_number;i++)
		{
			if(caddr==LB[i].addr&&LB[i].addr!=-1)
			{
				caddr=LB[cnt].addr;
				cnum=LB[cnt].num;
				cnext=LB[cnt].next;
				LB[cnt].addr=LB[i].addr;
				LB[cnt].num=LB[i].num;
				LB[cnt].next=LB[i].next;
				LB[i].addr=caddr;
				LB[i].num=cnum;
				LB[i].next=cnext;
				caddr=LB[cnt].next;
				cnt++;
				break;
			}
		}
		if(caddr==-1)break;
		j++;
	}

	int k,t;
	for(k=0;k<cnt/fz_node_number;k++)
	{
		t=k*fz_node_number;
		j=t;
		for(i=t+fz_node_number-1;i>=t;i--)
		{
			caddr=LB[j].addr;
			cnum=LB[j].num;
			cnext=LB[j].next;
			
			LB[j].addr=LB[i].addr;
			LB[j].num=LB[i].num;
			LB[j].next=LB[i].addr;
			
			LB[i].addr=caddr;
			LB[i].num=cnum;
			LB[i].next=cnext;
			
			j++;
			if(i-j<=1)break;
		}
	}

  	for(i=0;i<cnt;i++)
  	{
  		if(i==cnt-1)printf("%05d %d -1\n", LB[cnt-1].addr,LB[cnt-1].num);//,LB[cnt-1].next);
  		else printf("%05d %d %05d\n", LB[i].addr,LB[i].num,LB[i+1].addr);
  	}
	return 0;
} 
