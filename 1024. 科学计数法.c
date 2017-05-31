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
	int shishu,shishulength=xiaoshulength+1;
	if(zhengshu>=0)shishu=zhengshu*pow(10,xiaoshulength)+xiaoshu;
	else shishu=zhengshu*pow(10,xiaoshulength)-xiaoshu;

	if(s[0]=='-')
	{
		printf("-");
		shishu=abs(shishu);
	}
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
			for(i=0;i<shishulength+1;i++)
			{
				if(i==zhishu+1)printf(".");
				if(i<zhishu+1)
				{
					t=n;
					n=t/(int)pow(10,xiaoshulength-i);
					printf("%d",n);
					n=t%(int)pow(10,xiaoshulength-i);
				}
				if(i>zhishu+1)
				{
					t=n;
					n=t/(int)pow(10,xiaoshulength-i+1);
					printf("%d",n);
					n=t%(int)pow(10,xiaoshulength-i+1);					
				}
			} 
			printf("\n");
		}
	}
	else
	{
		printf("0.");
		for(i=1;i<abs(zhishu);i++)
		{
			printf("0");
		}
		n=shishu;
		for(i=0;i<shishulength;i++)
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
