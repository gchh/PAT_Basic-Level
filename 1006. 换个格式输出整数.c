#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	char st[28]="";
	char st1[2];//不能是1，需要留一位'\0'作为结束符；c语言字符串长度不算'\0'，在定义时要多留一个'\0'符的位置。 
	int a,i;
	if(n/100>0)
	{
		a=n/100;
		for(i=0;i<a;i++)
		{
			strcat(st,"B");
		}
	}
	if((n%100)/10>0)
	{
		a=(n%100)/10;
		for(i=0;i<a;i++)
		{
			strcat(st,"S");
		}
	}
	if(n%10>0)
	{
		a=n%10;
		for(i=0;i<a;i++)
		{
			//itoa(i+1,st1,10);//itoa并不是一个标准的C函数，它是Windows特有的，如果要写跨平台的程序，请用sprintf。
			//printf("%d\n",sprintf(st1,"%d",i+1));
			sprintf(st1,"%d",i+1);
			strcat(st,st1);
		}
	}	
	printf("%s\n",st);
	return 0;	
}
