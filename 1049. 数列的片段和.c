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
		sum+=(double)(n-i)*(double)(i+1)*f;//ÿ�����ֳ��ֵĴ���Ϊ(N-i)*(i+1)��. ǿ������ת�������⾫����ʧ 
	}
	printf("%.2lf\n",sum);
	return 0;
}
