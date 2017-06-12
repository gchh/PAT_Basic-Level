#include <stdio.h>
#include <string.h>

struct student{
	char num[15];
	int zhuowei;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct student st[n+1];
	int i,c,t;
	char number[15];
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d",&number,&c,&t);
		strcpy(st[c].num,number);
		st[c].zhuowei=t;
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&c);
		printf("%s %d\n",st[c].num,st[c].zhuowei);
	}
	return 0;
}
