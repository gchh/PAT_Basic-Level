#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int score[101];
	int i;
	for(i=0;i<101;i++)
	{
		score[i]=0;
	}
	int c;
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		score[c]++;
	}
	int k;
	scanf("%d",&k);
	int sc[k];
	for(i=0;i<k;i++)
	{
		scanf("%d",&sc[i]);
	}
	for(i=0;i<k;i++)
	{
		if(i==k-1)printf("%d\n",score[sc[i]]);
		else printf("%d ",score[sc[i]]);
	}
	return 0;
}
