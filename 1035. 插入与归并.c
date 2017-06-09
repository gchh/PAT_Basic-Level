#include <stdio.h>

void InsertionSort(int n,int *num)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		t=num[i];
		for(j=i+1;j<n;j++)
		{
			if(t<=num[j])break;
		}
		printf("%d: ",i);
		for(j=0;j<n;j++)
		{
			printf("%d ",num[j]);
		}
		printf("\n");		
	}
}

void MergeSort(int n,int *num)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n-1;j+=2)
		{
			if(num[j]>num[j+1])
			{
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}
		printf("%d: ",i);
		for(j=0;j<n;j++)
		{
			printf("%d ",num[j]);
		}
		printf("\n");	
	}	
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,num[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//InsertionSort(n,num);
	MergeSort(n,num);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}		
	return 0;
} 
