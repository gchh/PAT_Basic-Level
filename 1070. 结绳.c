#include <stdio.h>
#include <stdlib.h>

int comp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;//ÉıĞò 
}

int main()
{
	int n,a[10000];
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),comp);
	int b=a[0];
	for(i=1;i<n;i++)
	{
		b=(b+a[i])/2;
	}
	printf("%d\n",b);
	return 0;
}
