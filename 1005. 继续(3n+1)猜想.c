#include <stdio.h>

int main()
{
	int n,num[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//把每个数推导过程中的数据都记录起来 
	int mem[2500],a,cnt=0;//mem[3000]长度小会报段错误(>=2000就会报) 
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
		    mem[cnt]=a;//记录计算中的每一个数 
		    cnt++;
		}	
		mem[cnt]=a;
	}
	//找出num数组中和mem数据中相同的数，置零 
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<cnt;j++)
		{
			if(num[i]==mem[j])num[i]=0;
		}
	}
	//排序，从大到小 
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
	//去掉为0的数 
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
