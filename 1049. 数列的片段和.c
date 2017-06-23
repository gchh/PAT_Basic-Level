#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	double f,sum=0.0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f);
		sum+=(double)(n-i)*(double)(i+1)*f;//每个数字出现的次数为(N-i)*(i+1)次. 强制类型转换，避免精度损失 
	}
	printf("%.2lf\n",sum);
	return 0;
}
