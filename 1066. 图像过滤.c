#include <stdio.h>

int main()
{
	int n,m,a,b,c;
	scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
	int i,j,d;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&d);
			if(d>=a&&d<=b)d=c;
			if(j==m-1)printf("%03d\n",d);
			else printf("%03d ",d);			
		}
	}
	return 0;
}
