#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char ge[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	char shi[13][5]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	int n;
	scanf("%d",&n);
	char s[n][10];
	int i;
	for(i=0;i<=n;i++)//s[0]ÊÇ»»ÐÐ·û'\n' 
	{
		gets(s[i]);
	}
	int j,t;
	char *p,*q;
	for(i=1;i<=n;i++)
	{
		t=0;
		if(s[i][0]>='0'&&s[i][0]<='9')//Êý×Ö
		{
			for(j=0;j<strlen(s[i]);j++)
			{
				t+=(s[i][j]-'0')*pow(10,strlen(s[i])-j-1);
			}
			if(t>168)break;
			else if(t/13>0&&t%13>0)printf("%s %s\n",shi[t/13],ge[t%13]);
			else if(t/13>0&&t%13==0)printf("%s\n",shi[t/13]);
			else printf("%s\n",ge[t%13]);
		}
		else if(s[i][0]>='a'&&s[i][0]<='z')//×Ö·û
		{
			strtok(s[i]," ");
			p=strtok(NULL," ");
			q=strtok(NULL," ");
			if(q!=NULL)break;
			for(j=0;j<13;j++)
			{
				if(strcmp(s[i],ge[j])==0)
				{
					t+=j;
				}
				if(p!=NULL)
				{
					if(strcmp(p,ge[j])==0)
					{
						t+=j;
					}	
				}
			}
			for(j=0;j<13;j++)
			{
				if(strcmp(s[i],shi[j])==0)
				{
					t+=j*13;
				}
				if(p!=NULL)
				{
					if(strcmp(p,shi[j])==0)
					{
						t+=j*13;
					}
				}
			}
			if(t<169)printf("%d\n",t);
			else break;
		} 
	}
	return 0;
}
