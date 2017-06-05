#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int address;
	int data;
	int next;
}Node;
void reverse(Node *a,int k,int i)
{
	int j;
	Node temp;
	for(j=i*k;j<i*k+k/2;j++)
	{
		temp=a[j];
		a[j]=a[2*k*i+k-j-1];
		a[2*k*i+k-j-1]=temp;
	}
	a[i*k+k-1].next=a[i*k+k].address;
	for(j=i*k+k-2;j>=i*k;j--)
		a[j].next=a[j+1].address;
}
int main()
{
	int add,n,k,m;
	Node *a,temp;
	int i,j,num,length=0;
	while(~scanf("%d%d%d",&add,&n,&k))
	{
		a=(Node *)malloc((n+1)*sizeof(Node));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[length].address,&a[length].data,&a[length].next);
			if(a[length].address!=-1)length++;
		}
		if(add==-1)
		{
			free(a);
			printf("-1\n");
			break;
		}
		a[n].address=-1;
		num=0;
		while(add!=-1&&num<length)
		{
			j=num;
			while(a[j].address!=add&&j<length)
				j++;
			if(j>=length)break; 
			temp=a[num];
			a[num]=a[j];
			a[j]=temp;
			add=a[num].next;
			num++;
		}
		m=num/k;//m=length/k;测试点6 答案错误 
		for(i=m-1;i>=0;i--)
			reverse(a,k,i);
		for(i=0;i<num;i++)
		{
			if(i==num-1)printf("%05d %d -1\n",a[i].address,a[i].data);//,a[i].next);//printf("%05d %d %d\n",a[i].address,a[i].data,a[i].next);
			else printf("%05d %d %05d\n",a[i].address,a[i].data,a[i].next);
		}
		free(a);
		break;
	}
	return 0;
}
//全部正确 
