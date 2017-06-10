#include <stdio.h>
#include <math.h>

void InsertionSort(int n,int *num,int *temp)
{
	int i,j,t,isInsertSort,flag_print=0;
	//�ӵڶ�������ʼ��ǰ��������н��в��룬ÿ����һ�������ѭ����ǰ��Ͳ���һ���Ӻ���ȡ����ֵ��
	//���ÿ����һ�����ѭ�����������еĳ��Ⱦ�����һ
	for(i=1;i<n;i++)
	{
		isInsertSort=1;
		//�ݴ潫Ҫ���뵽ǰ��������
		t=num[i];
		//ѭ�������������У�Ѱ�Һ��ʵ����ݲ���λ�ã��ڴ˹����У�Ϊ���ݵĲ����ڳ�λ�ã�
		//Ҳ���ǰѱȽ�Ҫ�ݴ�����ݴ��Ԫ������ƶ�
		for(j=i-1;j>=0&&num[j]>t;j--)//j=i-1 ��ȡ�����������һ��Ԫ�ص��±�
		{
			num[j+1]=num[j];
		}
		//��������
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
		printf("��%d��������: ",i);
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
	while(n1>1)//����һ��������Ҫ�������򣬵õ����յĽ�������ָ�������и���=1ʱ��������������� 
	{
		isMergeSort=1;
		for(i=0;i<n-1;i+=pow(2,cnt+1))//�ָ�ɼ��������У�������������Ԫ�ظ������ϴ�������Ԫ�ظ�����2����ѭ�����ϸ������е����¸������� 
		{
			for(j=i;j<i+pow(2,cnt+1)&&j<n;j++)//��ÿ������������
			{
				for(k=i;k<i+pow(2,cnt+1)-1&&k<n-1;k++)//��ÿ�������������ڵ�����������
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
		if(t%2==1)n1+=1;//�´�ѭ���ָ�������и��� 
		cnt++;//�ڼ���ѭ��
		
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
		printf("��%d��������: ",cnt);
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
