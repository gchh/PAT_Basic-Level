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
            //�Ȳ�������Ҳ���Ǹ��ź�С���㣬�϶��ǷǷ��ġ� 
            if((a[j]<'0'||a[j]>'9')&&a[j]!='-'&&a[j]!='.')
			{
                k = 1;
                break;
            }
            //�Ǹ��ŵ����Ų�λ�ڵ�һλ
            else if(a[j]=='-')
			{
                if(j!=0)
				{
                    k = 1;
                    break;
                }
            }
            //��С���㣬��С����λ�ڵ�һλ�����ߵ�һλ�Ǹ��ţ��ڶ�λ��С����
            //ע�ⲻҪ�������һλ��С���������������һ�����Ե㲻ͨ�� 
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
            //����λ����λ���ϵ�С���� 
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
            //С���������λ���� 
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
