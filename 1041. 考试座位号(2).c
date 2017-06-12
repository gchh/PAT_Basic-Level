#include <stdio.h>
#include <string.h>

struct student{
	char num[15];
	int shiji;
	int zhuowei;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct student st[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d",&st[i].num,&st[i].shiji,&st[i].zhuowei);
	}
	int m;
	scanf("%d",&m);
	int sj[m];
	for(i=0;i<m;i++)
	{
		scanf("%d",&sj[i]);
	}
	int j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(sj[i]==st[j].shiji)
			{
				printf("%s %d\n",st[j].num,st[j].zhuowei);
			}
		}
	}
	return 0;
}
