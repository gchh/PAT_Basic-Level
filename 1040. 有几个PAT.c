#include <stdio.h>
#include <string.h>

int main()
{
	char s[100001];
	gets(s);
	char *p,*t;
	p=strchr (s,'P');
	t=strrchr(s,'T');
	//puts(p);
	//puts(t);
	int l1,l2;
	l1=strlen(s)-strlen(p);
	l2=strlen(p)-strlen(t)+1;
	//printf("%d %d\n",l1,l2);
	int i,j,k,cnt=0;
	for(i=l1;i<l2+l1-2;i++)
	{
		if(s[i]=='P')
		{
			for(j=i+1;j<l2+l1-1;j++)
			{
				if(s[j]=='A')
				{
					for(k=j+1;k<l2+l1;k++)
					{
					 	if(s[k]=='T')
						{
						 	cnt++;
						 	cnt=cnt%1000000007;
						}
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
//测试点3和4，运行超时 
