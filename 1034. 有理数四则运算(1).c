#include <stdio.h>
//#include <math.h> 
#include <string.h> 

void print(long long z,long long a,long long b)
{
	if(z>0)
	{
		if(a>0)
		{
			printf("%lld %lld/%lld",z,a,b);
		}
		else if(a==0)
		{
			printf("%lld",z);
		}
	} 
	else if(z<0)
	{
		if(a>0)
		{
			printf("(%lld %lld/%lld)",z,a,b);
		}
		else if(a==0)
		{
			printf("(%lld)",z);
		}		
	} 
	else //z==0
	{
		if(a>0)
		{
			printf("%lld/%lld",a,b);
		}
		else if(a<0)
		{
			printf("(%lld/%lld)",a,b);
		}
		else if(a==0)
		{
			printf("%lld",a);
		}		
	}	
}

long long zuidagongyueshu(long long a,long long b)
{
	if(a==0||b==0)return 1;//如果a=0或b=0，可能会出现x%0的情况，造成报浮点错误 
	long long r,max,min;
	if(a<0)a*=-1;
	if(b<0)b*=-1;	
	if(a<b)
	{
		max=b;
		min=a;
	}
	else
	{
		max=a;
		min=b;
	}
	r=max%min;
	while(r)
	{
		max=min;
		min=r;
		r=max%min;
	}
	return min;		
}

int main()
{
	long long a1,b1,a2,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	if(b1==0||b2==0)return 0;//如果分母是0
	printf("%ld %ld\n",a2,b2);
	if(b1<0)//如果分母是负数 
	{
		b1*=-1;
		a1*=-1;
	}
	if(b2<0)//如果分母是负数 
	{
		b2*=-1;
		a2*=-1;
	}
	long long z1,a1_1,z2,a2_1;
	z1=a1/b1;
	if(z1==0)a1_1=a1;//a1%b1;
	else //a1_1=abs(a1%b1);
	{
		a1_1=a1%b1;
		if(a1_1<0)a1_1*=-1;
	}
	z2=a2/b2;
	if(z2==0)a2_1=a2;//a2%b2;
	else //a2_1=abs(a2%b2);
	{
		a2_1=a2%b2;
		if(a2_1<0)a2_1*=-1;
	}
	printf("%ld %ld %ld\n",z2,a2_1,b2);
	long long a,b,z,a_1,zdgys;
	
	//加
	a=a1*b2+a2*b1;
	b=b1*b2;
	z=a/b;
	if(z==0)a_1=a;//a%b;
	else //a_1=abs(a%b);
	{
		a_1=a%b;
		if(a_1<0)a_1*=-1;
	}
	zdgys=zuidagongyueshu(a_1,b);
	a_1/=zdgys;
	b/=zdgys;

	print(z1,a1_1,b1);
	printf(" + ");
	print(z2,a2_1,b2);
	printf(" = ");
	print(z,a_1,b);
	printf("\n");
	//减
	a=a1*b2-a2*b1;
	b=b1*b2;
	z=a/b;
	if(z==0)a_1=a;//a%b;
	else //a_1=abs(a%b);
	{
		a_1=a%b;
		if(a_1<0)a_1*=-1;
	}
	zdgys=zuidagongyueshu(a_1,b);
	a_1/=zdgys;
	b/=zdgys;

	print(z1,a1_1,b1);
	printf(" - ");
	print(z2,a2_1,b2);
	printf(" = ");
	print(z,a_1,b);
	printf("\n");
	//乘
	a=a1*a2;
	if(a==0)
	{
		print(z1,a1_1,b1);
		printf(" * ");
		print(z2,a2_1,b2);
		printf(" = ");
		printf("0\n");
	}
	else
	{
		b=b1*b2;
		z=a/b;
		if(z==0)a_1=a;//a%b;
		else //a_1=abs(a%b);
		{
			a_1=a%b;
			if(a_1<0)a_1*=-1;
		}		
		zdgys=zuidagongyueshu(a_1,b);
		a_1/=zdgys;
		b/=zdgys;

		print(z1,a1_1,b1);
		printf(" * ");
		print(z2,a2_1,b2);
		printf(" = ");
		print(z,a_1,b);
		printf("\n");
	}
	//除
	if(a2<0)
	{
		a=a1*b2;
		b=b1*a2;
		a*=-1;
		b*=-1;
	}
	else
	{
		a=a1*b2;
		b=b1*a2;
	}
	if(b==0)
	{
		print(z1,a1_1,b1);
		printf(" / ");
		print(z2,a2_1,b2);
		printf(" = ");
		printf("Inf\n");
	}
	else
	{
		z=a/b;
		if(z==0)a_1=a;//a%b;
		else //a_1=abs(a%b);
		{
			a_1=a%b;
			if(a_1<0)a_1*=-1;
		}		
		zdgys=zuidagongyueshu(a_1,b);
		a_1/=zdgys;
		b/=zdgys;
		print(z1,a1_1,b1);
		printf(" / ");
		print(z2,a2_1,b2);
		printf(" = ");
		print(z,a_1,b);
		printf("\n");	
	}
	return 0;
}
//测试点2，答案错误 -1073741824/513 92160/40960
