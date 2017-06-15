#include <stdio.h>

int main()
{
	int n,as,ah,bs,bh;
	scanf("%d",&n);
	int i,afail=0,bfail=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&as,&ah,&bs,&bh);
		if(as+bs==ah&&as+bs!=bh)bfail++;
		if(as+bs==bh&&as+bs!=ah)afail++;	
	}
	printf("%d %d\n",afail,bfail);
	return 0;
}
