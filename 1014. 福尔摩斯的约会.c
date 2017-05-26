#include <stdio.h> 
#include <string.h>

int main()
{
	char st[4][62];
	int i;
	for(i=0;i<4;i++)
	{
		gets(st[i]);
	}
	char Ci[10]={'0','1','2','3','4','5','6','7','8','9'};
	char CA[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char Ca[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char* Week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int j,day=-1,h=-1;
	for(i=0;i<strlen(st[0])&&i<strlen(st[1]);i++)
	{
		if(st[0][i]==st[1][i])
		{
			if(day==-1)
			{
				for(j=0;j<7;j++)//A-G
				{
					if(st[0][i]==CA[j])
					{
						day=j;//day
						break;
					}
				}
			}
			else
			{
				for(j=0;j<14;j++)//A-N
				{
					if(st[0][i]==CA[j])
					{
						h=10+j;//h
						break;
					}
				}				
				if(h==-1)
				{
					for(j=0;j<10;j++)
					{
						if(st[0][i]==Ci[j])
						{
							h=j;//h
							break;
						}
					}	
				}
			}
		}
		if(h!=-1)break;
	}
	int min=-1;
	for(i=0;i<strlen(st[2])&&i<strlen(st[3]);i++)
	{
		if(st[2][i]==st[3][i])
		{
			for(j=0;j<26;j++)
			{
				if(st[2][i]==Ca[j]||st[2][i]==CA[j])
				{
					min=i;
					break;
				}
			}			
		}
		if(min!=-1)break;
	}
	printf("%s ",Week[day]);
	printf("%02d:",h);
	printf("%02d\n",min);
	return 0;
}
