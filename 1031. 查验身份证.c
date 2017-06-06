#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char sf[n][19];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",sf[i]);
	}
	int qz[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char m[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int j,crc,pass=0;
	for(i=0;i<n;i++)
	{
		crc=0;
		for(j=0;j<strlen(sf[i])-1;j++)
		{
			if(sf[i][j]>='0'&&sf[i][j]<='9')
			{
				crc+=(sf[i][j]-'0')*qz[j];
			}
			else
			{
				printf("%s\n",sf[i]);//前17位有非数字字符 
				break;
			}
		}
		if(j==strlen(sf[i])-1)
		{
			if(sf[i][j]!=m[crc%11])
			{
				printf("%s\n",sf[i]);//校验码不对 
			}
			else pass++;
		}
	}
	if(pass==n)printf("All passed\n");
	return 0;
} 
