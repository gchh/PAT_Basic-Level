#include <stdio.h>
#include <math.h>

int main()
{
	char s[10010];
	gets(s);
	
	int zhengshu,xiaoshu,zhishu; 
	sscanf(s,"%d.%dE%d",&zhengshu,&xiaoshu,&zhishu);
	
	int xiaoshulength=0,n=xiaoshu;
	do
	{
		n=n/10;
		xiaoshulength++;
	}while(n!=0);
	int shishu,shishulength=xiaoshulength+1;
	if(zhengshu>=0)shishu=zhengshu*pow(10,xiaoshulength)+xiaoshu;
	else shishu=zhengshu*pow(10,xiaoshulength)-xiaoshu;
	//printf("%d\n",shishu);
	//printf("%d\n",shishulength);
	
	if(shishu<0)
	{
		printf("-");
		shishu=abs(shishu);
	}
	//printf("%f\n",pow(10,zhishu));
	int i;
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
			
		}
	}
	return 0;
} 
