#include <stdio.h>
#include <math.h>

void InsertionSort(int n,int *num,int *temp)
{
	int i,j,t,isInsertSort,flag_print=0;
	//从第二个数开始往前面的数据中进行插入，每经过一轮外面的循环，前面就插入一个从后面取出的值，
	//因此每经过一轮外层循环，有序序列的长度就增加一
	for(i=1;i<n;i++)
	{
		isInsertSort=1;
		//暂存将要插入到前方的数据
		t=num[i];
		//循环遍历有序序列，寻找合适的数据插入位置，在此过程中，为数据的插入腾出位置，
		//也就是把比将要暂存的数据大的元素向后移动
		for(j=i-1;j>=0&&num[j]>t;j--)//j=i-1 获取有序序列最后一个元素的下标
		{
			num[j+1]=num[j];
		}
		//插入数据
		num[j+1]=t;
		
		if(flag_print==1)
		{
			flag_print=0;
			printf("Insertion Sort\n");
			for(j=0;j<n;j++)
			{
				if(j==n-1)printf("%d\n",num[j]);
				else printf("%d ",num[j]);
			}		
			break;		
		}
		for(j=0;j<n;j++)
		{
			if(num[j]!=temp[j])
			{
				isInsertSort=0;
				break;
			}
		}
		if(isInsertSort==1)
		{
			flag_print=1;
		}
	#if 0
		printf("第%d轮排序结果: ",i);
		for(j=0;j<n;j++)
		{
			printf("%d ",num[j]);
		}
		printf("\n");		
	#endif
	}
}

void MergeSort(int n,int *num,int *temp)
{
	int t,cnt=0,n1=n;
	int i,j,k,tem;
	int isMergeSort,flag_print=0;
	while(n1>1)//对于一个数列需要几次排序，得到最终的结果，当分割的子数列个数=1时，即数列已排序好 
	{
		isMergeSort=1;
		for(i=0;i<n-1;i+=pow(2,cnt+1))//分割成几个子数列，本次子数列里元素个数是上次子数列元素个数的2倍，循环从上个子数列调到下个子数列 
		{
			for(j=i;j<i+pow(2,cnt+1)&&j<n;j++)//对每个子数列排序
			{
				for(k=i;k<i+pow(2,cnt+1)-1&&k<n-1;k++)//对每个子序列里相邻的两个数排序
				{
					if(num[k]>num[k+1])
					{
						tem=num[k];
						num[k]=num[k+1];
						num[k+1]=tem;
					}
				}
			}
		}
		t=n1;
		n1/=2;
		if(t%2==1)n1+=1;//下次循环分割的子数列个数 
		cnt++;//第几次循环
		
		if(flag_print==1)
		{
			flag_print=0;
			printf("Merge Sort\n");
			for(j=0;j<n;j++)
			{
				if(j==n-1)printf("%d\n",num[j]);
				else printf("%d ",num[j]);
			}	
			break;		
		}
		for(j=0;j<n;j++)
		{
			if(num[j]!=temp[j])
			{
				isMergeSort=0;
				break;
			}
		}
		if(isMergeSort==1)
		{
			flag_print=1;
		}
	#if 0
		printf("第%d轮排序结果: ",cnt);
		for(j=0;j<n;j++)
		{
			printf("%d ",num[j]);
		}
		printf("\n");
	#endif
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,num[n],num1[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		num1[i]=num[i];
	}
	int temp[n]; 
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp[i]);
	}
	InsertionSort(n,num,temp);
	MergeSort(n,num1,temp);	
	return 0;
} 
