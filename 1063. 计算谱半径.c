#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,sb,xb;
	double db,max=0;
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&sb,&xb);
		db=pow(sb,2);
		db+=pow(xb,2);
		db=sqrt(db);
		if(max<db)max=db;
	}
	printf("%.2lf\n",max);
	return 0;
}
