#include <stdio.h>

int main()
{
	int n,num[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//��ÿ�����Ƶ������е����ݶ���¼���� 
	int mem[2500],a,cnt=0;//mem[3000]����С�ᱨ�δ���(>=2000�ͻᱨ) 
	for(i=0;i<n;i++) 
	{
		a=num[i];
		while(a!=1)
		{
		    if(a%2==0)
		    {
		        a = a/2;
		    }
		    else
		    {
		        a = (3*a+1)/2;
		    }
		    mem[cnt]=a;//��¼�����е�ÿһ���� 
		    cnt++;
		}	
		mem[cnt]=a;
	}
	//�ҳ�num�����к�mem��������ͬ���������� 
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<cnt;j++)
		{
			if(num[i]==mem[j])num[i]=0;
		}
	}
	//���򣬴Ӵ�С 
	int t;
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-1;j++)
		{
			if(num[j]<num[j+1])
			{
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}		
	}
	//ȥ��Ϊ0���� 
	int result[100],count=0;
	for(i=0;i<n;i++)
	{
		if(num[i]!=0)
		{
			result[count]=num[i];
			count++;
		}
	}
	for(i=0;i<count;i++)
	{
		if(i==count-1)printf("%d\n",result[i]);
		else printf("%d ",result[i]);
	}
	return 0;
}
