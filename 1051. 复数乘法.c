#include <stdio.h>
#include <math.h>

int main()
{
	double R1,P1,R2,P2;
	scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
	double A,B;
	A=R1*R2*cos(P1+P2);
	B=R1*R2*sin(P1+P2);
	//����ʵ�����鲿��������λС�������Ե�A��B��ֵ����-0.01��0.01֮��ʱ�ͱ���Ҫ����������Ϊ�㣬�����������2��3�޷�ͨ����
	if(A<0.01&&A>-0.01)A=0;
	if(B<0.01&&B>-0.01)B=0;
	//A,BΪ0ʱҲҪ��� 
	printf("%.2lf",A);
	if(B>=0)printf("+");
	printf("%.2lfi\n",B);
	return 0;
}
