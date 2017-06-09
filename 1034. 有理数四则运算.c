#include <stdio.h>
#include <math.h> 
#include <string.h> 

char* intTOstring(char *s,int z,int a,int b)
{
	if(z>0)
	{
		if(a>0)
		{
			sprintf(s,"%d %d/%d",z,a,b);
		}
		else if(a==0)
		{
			sprintf(s,"%d",z);
		}
	} 
	else if(z<0)
	{
		if(a>0)
		{
			sprintf(s,"(%d %d/%d)",z,a,b);
		}
		else if(a==0)
		{
			sprintf(s,"(%d)",z);
		}		
	} 
	else //z==0
	{
		if(a>0)
		{
			sprintf(s,"%d/%d",a,b);
		}
		else if(a<0)
		{
			sprintf(s,"(%d/%d)",a,b);
		}
		else if(a==0)
		{
			sprintf(s,"%d",a);
		}		
	}	
	return s;
}

int zuidagongyueshu(int a,int b)
{
	if(a==0||b==0)return 1;//如果a=0或b=0，可能会出现x%0的情况，造成报浮点错误 
#if 0
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
	int r,max,min;
	if(abs(a)<abs(b))
	{
		max=abs(b);
		min=abs(a);
	}
	else
	{
		max=abs(a);
		min=abs(b);
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
	int a1,b1,a2,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	int z1,a1_1,z2,a2_1;
	z1=a1/b1;
	if(z1==0)a1_1=a1%b1;
	else a1_1=abs(a1)%b1;
	z2=a2/b2;
	if(z2==0)a2_1=a2%b2;
	else a2_1=abs(a2)%b2;
	char s1[10],s2[10];
	intTOstring(s1,z1,a1_1,b1);
	intTOstring(s2,z2,a2_1,b2);
	
	int a,b,z,a_1,zdgys;
	char rs[10];
	//加
	a=a1*b2+a2*b1;
	b=b1*b2;
	z=a/b;
	if(z==0)a_1=a%b;
	else a_1=abs(a)%b;
	zdgys=zuidagongyueshu(a_1,b);
	a_1/=zdgys;
	b/=zdgys;
	intTOstring(rs,z,a_1,b);
	printf("%s + %s = %s\n",s1,s2,rs);
	//减
	a=a1*b2-a2*b1;
	b=b1*b2;
	z=a/b;
	if(z==0)a_1=a%b;
	else a_1=abs(a)%b;
	zdgys=zuidagongyueshu(a_1,b);
	a_1/=zdgys;
	b/=zdgys;
	intTOstring(rs,z,a_1,b);
	printf("%s - %s = %s\n",s1,s2,rs);	
	//乘
	a=a1*a2;
	if(a==0)printf("%s * %s = 0\n",s1,s2);	
	else
	{
		b=b1*b2;
		z=a/b;
		if(z==0)a_1=a%b;
		else a_1=abs(a)%b;
		zdgys=zuidagongyueshu(a_1,b);
		a_1/=zdgys;
		b/=zdgys;
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
		z=a/b;
		if(z==0)a_1=a%b;
		else a_1=abs(a)%b;
		zdgys=zuidagongyueshu(a_1,b);
		a_1/=zdgys;
		b/=zdgys;
		intTOstring(rs,z,a_1,b);
		printf("%s / %s = %s\n",s1,s2,rs);		
	}	
	return 0;
}
//测试点2 3，答案错误 
