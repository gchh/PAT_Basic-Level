#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct p{
	char name[21];
	int t;//�Ƿ��н� 
};
int main()
{
	int m,n,s;
	scanf("%d %d %d",&m,&n,&s);
	if(s>m)
	{
		printf("Keep going...\n");
		return 0;
	}
	int i,j,cnt=1;
	//struct p nm[1001];
	//for(i=1;i<=m;i++)nm[i].t=0;//δ�н� 
	struct p *nm=(struct p*)malloc(sizeof(struct p)*(m+1));	
	int flag=0;
	for(i=1;i<=m;i++)
	{
		scanf("%s",&nm[i].name);
#if 0//���Ե�3���𰸴��� 
		if((cnt-s)%n==0&&n>0)
		{
			nm[i].t=1;//�н�
		}
		for(j=1;j<i;j++)
		{
			if(strcmp(nm[i].name,nm[j].name)==0&&nm[j].t==1)
			{
				//cnt--;
				if(nm[i].t==1)nm[i].t=0;//���ظ��н� 
				break;
			}
		}
		if(j==i)cnt++;
#else//ȫ����ȷ 
		if(cnt==s&&flag==0||cnt==n&&flag==1)
		{
			for(j=1;j<i;j++)
			{
				if(strcmp(nm[i].name,nm[j].name)==0&&nm[j].t==1)
				{
					cnt--;//�ظ��н����������� 
					break;
				}
			}
			if(j==i)
			{
				if(cnt==s&&flag==0)flag=1;
				nm[i].t=1;//�н�
				cnt=1;
			}
		}		
		if(nm[i].t==0)
		{
			cnt++;
		}
#endif
	}
	for(i=s;i<=m;i++)
	{ 
		if(nm[i].t==1)puts(nm[i].name);
	}
	free(nm);
	return 0;
}
