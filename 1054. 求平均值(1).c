#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,r_cnt=0,dot_cnt,dot,fuhao_cnt,right_num;
	double t,sum=0.0;
	char s[20];
	for(i=0;i<n;i++)
	{
		scanf("%s",&s);
		dot_cnt=0;
		fuhao_cnt=0;
		right_num=0;
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]=='-')
			{
				fuhao_cnt++;
				if(j>0||fuhao_cnt>1)//负号不在第一位上 或有不止一个负号 
				{
					right_num=1;
					break;
				}
			}
			else if(s[j]=='.')
			{
				dot_cnt++;
				dot=j;
				if(j==0||s[j-1]=='-'&&j>=1||dot_cnt>1)//小数点在第一位或小数点前面是负号 或有2个及以上小数点 
				{
					right_num=1;
					break;
				}
			}
			else if(s[j]<'0'||s[j]>'9')//有非数字字符 
			{
				right_num=1;
				break; 
			}
		}
		if(right_num==0)
		{
			t=atof(s);
			if(t>1000||t<-1000)right_num=1;//不是[-1000，1000]区间内的数
			else if(dot_cnt==1&&strlen(s)-dot-1>2)right_num=1;//小数点后有2位以上 
			else
			{
				r_cnt++;
				sum+=t; 				
			}
		}
		if(right_num==1)printf("ERROR: %s is not a legal number\n",s);
	}
	if(r_cnt==0)printf("The average of 0 numbers is Undefined\n");
	else if(r_cnt==1)printf("The average of 1 number is %.2lf\n",sum);
	else printf("The average of %d numbers is %.2lf\n",r_cnt,sum/r_cnt);
	return 0;
}
//全部正确 
