#include <stdio.h>
#include <string.h>

struct node{
	char addr[6];
	int num;
    char next[6];
};

int main()
{
	int node_number,fz_node_number;
	char frist_node_address[6];
	scanf("%s %d %d", &frist_node_address,&node_number,&fz_node_number);
	struct node LB[node_number];
	int i;
	struct node rs[node_number];
	strcpy(rs[0].addr,frist_node_address);
	for(i=0;i<node_number;i++)
	{
		scanf("%s %d %s", &LB[i].addr,&LB[i].num,&LB[i].next);
		if(strcmp(LB[i].addr,rs[0].addr)==0)
		{
			rs[0].num=LB[i].num;
			strcpy(rs[0].next,LB[i].next);
		}		
	} 

	int j=1;
	while(j<node_number)
	{
		for(i=0;i<node_number;i++)
		{
			if(strcmp(rs[j-1].next,LB[i].addr)==0)//(rs[j].next==LB[i].addr)
			{
				strcpy(rs[j].addr,LB[i].addr);
				rs[j].num=LB[i].num;
				strcpy(rs[j].next,LB[i].next);
				j++;
				break;
			}
		}
	}
	
	struct node fz[node_number];
	j=0;
	int k,t;
	for(k=0;k<node_number/fz_node_number;k++)
	{
		t=k*fz_node_number;
		for(i=t+fz_node_number-1;i>=t;i--)
		{
			strcpy(fz[j].addr,rs[i].addr);
			fz[j].num=rs[i].num;
			if(i==t)strcpy(fz[j].next,rs[t+fz_node_number-1].next);
			else strcpy(fz[j].next,rs[i-1].addr);
			j++;
		}
	}
	for(i=j;i<node_number;i++)
	{
		strcpy(fz[i].addr,rs[i].addr);
		fz[i].num=rs[i].num;
		strcpy(fz[i].next,rs[i].next);
	}

	for(i=0;i<node_number-1;i++)
	{
		if(strcmp(fz[i].next,fz[i+1].addr)!=0)strcpy(fz[i].next,fz[i+1].addr);
	} 

	for(i=0;i<node_number;i++)
	{
		printf("%s %d %s\n", fz[i].addr,fz[i].num,fz[i].next);
	} 
	return 0;
} 
