#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char s[10010];
	gets(s);
	
	int zhengshu,xiaoshu,zhishu; 
	sscanf(s,"%d.%dE%d",&zhengshu,&xiaoshu,&zhishu);
	
	int xiaoshulength=0;
	int n,i,t;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			t=i;
		}
		if(s[i]=='E')break;
		if(i>t)xiaoshulength++;
	}
	int shishu,shishulength=xiaoshulength;//+1;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')break;
		if(s[i]!='+'&&s[i]!='-')
		shishulength++;
	}

	if(s[0]=='-')
	{
		shishu=zhengshu*(int)pow(10,xiaoshulength)-xiaoshu;
		printf("-");
		shishu=abs(shishu);
	}
	else shishu=zhengshu*(int)pow(10,xiaoshulength)+xiaoshu;
	
	if(zhishu>=0)
	{
		if(zhishu>=xiaoshulength)
		{
			printf("%d",shishu);
			for(i=0;i<zhishu-xiaoshulength;i++)
				printf("0");
			printf("\n");
		}
		else
		{
			n=shishu;
			for(i=0;i<xiaoshulength+1;i++)//for(i=0;i<shishulength;i++)
			{
				t=n;
				n=t/(int)pow(10,xiaoshulength-i);
				if(n!=0||i>=zhishu)printf("%d",n);
				if(i==zhishu)printf(".");
				n=t%(int)pow(10,xiaoshulength-i);
			} 
			printf("\n");
		}
	}
	else
	{
		printf("0.");
		for(i=1;i<abs(zhishu)-(shishulength-xiaoshulength-1);i++)//for(i=1;i<abs(zhishu);i++)
		{
			printf("0");
		}
		n=shishu;
		for(i=0;i<xiaoshulength+1;i++)//for(i=0;i<shishulength;i++)
		{
			t=n;
			n=t/(int)pow(10,xiaoshulength-i);
			printf("%d",n);
			n=t%(int)pow(10,xiaoshulength-i);
		}
		printf("\n");
	} 
	return 0;
} 
