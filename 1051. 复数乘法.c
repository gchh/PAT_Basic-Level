#include <stdio.h>
#include <math.h>

int main()
{
	double R1,P1,R2,P2;
	scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
	double A,B;
	A=R1*R2*cos(P1+P2);
	B=R1*R2*sin(P1+P2);
	//由于实部、虚部都保留两位小数，所以当A、B的值介于-0.01与0.01之间时就必须要把它们设置为零，否则会有用例2和3无法通过。
	if(A<0.01&&A>-0.01)A=0;
	if(B<0.01&&B>-0.01)B=0;
	//A,B为0时也要输出 
	printf("%.2lf",A);
	if(B>=0)printf("+");
	printf("%.2lfi\n",B);
	return 0;
}
