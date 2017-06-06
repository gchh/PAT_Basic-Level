#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,nm[n+1],cj=0,max_xbianhao=0,max_cj=0;
	for(i=0;i<=n;i++)
	{
		nm[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&j,&cj);
		nm[j]+=cj;
		if(max_cj<nm[j])
		{
			max_cj=nm[j];
			max_xbianhao=j;
		}
	} 
	printf("%d %d\n",max_xbianhao,max_cj);
	return 0;
} 
