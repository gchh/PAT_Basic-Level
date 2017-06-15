#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,dui,ren,score,sc[1001]={0},max=0,maxi;
	for(i=0;i<n;i++)
	{
		scanf("%d-%d %d",&dui,&ren,&score);
		sc[dui]+=score;
		if(max<sc[dui])
		{
			max=sc[dui];
			maxi=dui;
		}
	}
	printf("%d %d\n",maxi,sc[maxi]);
	return 0;
} 
