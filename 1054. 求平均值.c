#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char s[n][20];
	for(i=0;i<n;i++)
	{
		scanf("%s",&s[i]);
	}
	int j,shuzi_cnt=0,zero,dot,fu;
	double t,t1,avg=0.0;
	char *pEnd;
	for(i=0;i<n;i++)
	{
		zero=0;
		dot=0;
		fu=0;
		for(j=0;j<strlen(s[i]);j++)
		{
			if(s[i][j]!='0'&&s[i][j]!='.')
			{
				zero=1;
			}
			if(s[i][j]=='.')
			{
				if(strlen(s[i])-1-j>2)zero=1;
				if(j>1&&zero==0||j==0||j==strlen(s[i])-1||s[i][0]=='-'&&s[i][1]=='.')dot=2;
				dot++;
			}
			if(s[i][j]=='-'&&j>0)
			{
				fu=2;
			}
		}
		t=strtod(s[i],&pEnd);
		t1=strtod(pEnd,NULL);
		if(t1!=0||dot>1||fu>1)printf("ERROR: %s is not a legal number\n",s[i]);
		else if(t==0&&zero==1)printf("ERROR: %s is not a legal number\n",s[i]);
		else if(t>1000||t<-1000)printf("ERROR: %s is not a legal number\n",s[i]);
		else if(t*100-(int)(t*100)!=0)printf("ERROR: %s is not a legal number\n",s[i]);
		else
		{
			avg+=t;
			shuzi_cnt++;
		}
	}
	if(shuzi_cnt==0)printf("The average of 0 numbers is Undefined\n");
	else if(shuzi_cnt==1)printf("The average of 1 number is %.2lf\n",avg);
	else printf("The average of %d numbers is %.2lf\n",shuzi_cnt,avg/shuzi_cnt);
	return 0;
}
//²âÊÔµã2 3 ´ð°¸´íÎó 
