#include <stdio.h>
#include <math.h> 
#include <string.h> 

char* intTOstring(char *s,long z,long a,long b)
{
	if(z>0)
	{
		if(a>0)
		{
			sprintf(s,"%ld %ld/%ld",z,a,b);
		}
		else if(a==0)
		{
			sprintf(s,"%ld",z);
		}
	} 
	else if(z<0)
	{
		if(a>0)
		{
			sprintf(s,"(%ld %ld/%ld)",z,a,b);
		}
		else if(a==0)
		{
			sprintf(s,"(%ld)",z);
		}		
	} 
	else //z==0
	{
		if(a>0)
		{
			sprintf(s,"%ld/%ld",a,b);
		}
		else if(a<0)
		{
			sprintf(s,"(%ld/%ld)",a,b);
		}
		else if(a==0)
		{
			sprintf(s,"%ld",a);
		}		
	}	
	return s;
}

long zuidagongyueshu(long a,long b)
{
	if(a==0||b==0)return 1;//如果a=0或b=0，可能会出现x%0的情况，造成报浮点错误 
#if 0//测试点3会运行超时 
	int c;
	if(abs(a)<abs(b))c=abs(a);
	else c=abs(b);
	int i=1;
	for(i=c;i>=1;i--)
	{
		if(a%i==0&&b%i==0)break;
	}
	return i;
#else
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
#endif
}

int main()
{
	long a1,b1,a2,b2,zdgys;
	scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);
	if(b1==0||b2==0)return 0;//如果分母是0
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
	zdgys=zuidagongyueshu(a1,b1);
	a1/=zdgys;
	b1/=zdgys;
	zdgys=zuidagongyueshu(a2,b2);
	a2/=zdgys;
	b2/=zdgys;	
	
	long z1,a1_1,z2,a2_1;
	
	z1=a1/b1;
	if(z1==0)a1_1=a1;
	else a1_1=abs(a1%b1);
	
	z2=a2/b2;
	if(z2==0)a2_1=a2;
	else a2_1=abs(a2%b2);
	
	char s1[100],s2[100];
	intTOstring(s1,z1,a1_1,b1);
	intTOstring(s2,z2,a2_1,b2);
	
	long a,b,z,a_1;
	char rs[100];
	//加
	a=a1*b2+a2*b1;
	b=b1*b2;
	zdgys=zuidagongyueshu(a,b);
	a/=zdgys;
	b/=zdgys;
	
	z=a/b;
	if(z==0)a_1=a;
	else a_1=abs(a%b);

	intTOstring(rs,z,a_1,b);
	printf("%s + %s = %s\n",s1,s2,rs);
	//减
	a=a1*b2-a2*b1;
	b=b1*b2;
	zdgys=zuidagongyueshu(a,b);
	a/=zdgys;
	b/=zdgys;
	
	z=a/b;
	if(z==0)a_1=a;
	else a_1=abs(a%b);

	intTOstring(rs,z,a_1,b);
	printf("%s - %s = %s\n",s1,s2,rs);	
	//乘
	a=a1*a2;
	if(a==0)printf("%s * %s = 0\n",s1,s2);	
	else
	{
		b=b1*b2;
		zdgys=zuidagongyueshu(a,b);
		a/=zdgys;
		b/=zdgys;		
		
		z=a/b;
		if(z==0)a_1=a;
		else a_1=abs(a%b);

		intTOstring(rs,z,a_1,b);
		printf("%s * %s = %s\n",s1,s2,rs);	
	}
	//除
	if(a2<0)
	{
		a2=-a2;
		b2=-b2;
	}
	a=a1*b2;
	b=b1*a2;
	if(b==0)printf("%s / %s = Inf\n",s1,s2);
	else
	{
		zdgys=zuidagongyueshu(a,b);
		a/=zdgys;
		b/=zdgys;
				
		z=a/b;
		if(z==0)a_1=a;
		else a_1=abs(a%b);

		intTOstring(rs,z,a_1,b);
		printf("%s / %s = %s\n",s1,s2,rs);		
	}	
	return 0;
}
//全部正确，使用求最大公约数时用abs() ，可能求绝对值的参数超过int的范围，照成错误，测试点2和3通不过，不使用abs()求绝对值，就OK了 
