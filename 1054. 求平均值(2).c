#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main()
{
    int n;
    char a[20];
    char split[] = ".";
    char temp1[10];
    char temp2[10];
    int h;
    int h1;
    int k;
    double p;
    int i,j,n1=0;
    double sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%s",a);
        k = 0;
        h = 0;
        for(j=0;j<strlen(a);j++)
		{
            //既不是数字也不是负号和小数点，肯定是非法的。 
            if((a[j]<'0'||a[j]>'9')&&a[j]!='-'&&a[j]!='.')
			{
                k = 1;
                break;
            }
            //是负号但负号不位于第一位
            else if(a[j]=='-')
			{
                if(j!=0)
				{
                    k = 1;
                    break;
                }
            }
            //是小数点，但小数点位于第一位，或者第一位是负号，第二位是小数点
            //注意不要考虑最后一位是小数点的情况否则最后一个测试点不通过 
            else if(a[j]=='.')
			{
                if(a[0]=='-'&&j==1)
				{
                    k = 1;
                }
                if(j==0)
				{
                    k = 1;
                    break;
                }
            }
            //有两位及两位以上的小数点 
            if(a[j]=='.')
			{
                h++;
                h1 = j;
                if(h>1)
				{
                    k = 1;
                    break;
                }
            }
        }
        if(k)printf("ERROR: %s is not a legal number\n",a);
        else
		{
            p = atof(a);
            if(p>1000||p<-1000)printf("ERROR: %s is not a legal number\n",a);
            //小数点后有两位以上 
            else if(h==1&&(strlen(a)-h1)>3)printf("ERROR: %s is not a legal number\n",a);
            else
			{
                n1++;
                sum = sum+p;
            }
        }
    }
    if(n1>1)printf("The average of %d numbers is %.2lf",n1,sum/n1);
    else if(n1==0)printf("The average of 0 numbers is Undefined");
    else if(n1==1)printf("The average of 1 number is %.2lf",sum/n1);
}
