#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	char st[28]="";
	char st1[2];//������1����Ҫ��һλ'\0'��Ϊ��������c�����ַ������Ȳ���'\0'���ڶ���ʱҪ����һ��'\0'����λ�á� 
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
			//itoa(i+1,st1,10);//itoa������һ����׼��C����������Windows���еģ����Ҫд��ƽ̨�ĳ�������sprintf��
			//printf("%d\n",sprintf(st1,"%d",i+1));
			sprintf(st1,"%d",i+1);
			strcat(st,st1);
		}
	}	
	printf("%s\n",st);
	return 0;	
}
