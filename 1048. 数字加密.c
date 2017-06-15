#include <stdio.h>
#include <string.h>

int main()
{
	char a[101],b[101];
	scanf("%s %s",a,b);
	int i,j=strlen(a)-1,k,t,s;
	for(i=strlen(b)-1;i>=0;i--)
	{
		k=strlen(b)-i;
		if(j>=0)t=a[j]-'0';
		else t=0;
		s=b[i]-'0';
		if(k%2>0)
		{
			s+=t;			
			if(s%13==10)b[i]='J';
			else if(s%13==11)b[i]='Q';
			else if(s%13==12)b[i]='K';
			else b[i]=s%13+'0';
		}
		else
		{
			if(s<t)
			{
				b[i]=s-t+10+'0';
			}
			else b[i]=s-t+'0';
		}
		j--;
	}
	int cnt=j;
	while(j>=0)//当A的长度大于B时
	{
		t=a[j]-'0';
		s=0;
		k=strlen(a)-j;
		if(k%2>0)
		{
			s+=t;			
			if(s%13==10)a[j]='J';
			else if(s%13==11)a[j]='Q';
			else if(s%13==12)a[j]='K';
			else a[j]=s%13+'0';
		}
		else
		{
			if(s<t)
			{
				a[j]=s-t+10+'0';
			}
			else a[j]=s-t+'0';
		}
		j--;
	}
	for(i=0;i<=cnt;i++)
	{
		printf("%c",a[i]);
	}
	puts(b);
	return 0;
}
