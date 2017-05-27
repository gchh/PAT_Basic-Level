#include <stdio.h>
#include <string.h>

int main()
{
	char a[1002];
	int b;
	scanf("%s %d",a,&b);
	int s[1002];
	int i,t=0,cnt=0;
	for(i=0;i<strlen(a);i++)
	{
		t+=a[i]-48;
		if(t/b!=0)
		{
			s[cnt]=t/b;
			cnt++;
			if(t%b!=0)t=(t%b)*10;
			else t=0;
		}
		else
		{
			if(i!=0||strlen(a)==1)//如果是0除以某个正整数的话，就要让s[0]=0 
			{
				s[cnt]=0;
				cnt++;	
			}
			if(t>0)t=(a[i]-48)*10;
		}
	}
	for(i=0;i<cnt;i++)
	{
		printf("%d",s[i]);
	}
	printf(" %d\n",t/10);
	return 0;
} 
