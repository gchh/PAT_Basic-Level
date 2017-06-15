#include <stdio.h>
#include <stdlib.h>

#define Maxn 100001

typedef struct
{
	int data;
	int flag;		//用来标记是否为主元：1是，0否
}Num;

Num input[Maxn];

int compare(const void *a,const void *b);

int main(void)
{
	int N,i;
	int sum = 0,count = 0;
	int max,min;
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		scanf("%d",&(input[i].data));
		input[i].flag = 1;
	}

	max = input[0].data;
	min = input[N-1].data;

	for(i=0;i<N;++i)
	{
		if(input[i].data >= max)
			max = input[i].data;
		else
			input[i].flag = 0;
	}
	for(i=N-1;i>=0;--i)
	{
		if(input[i].data <= min)
			min = input[i].data;
		else
			input[i].flag = 0;
	}


	for(i=0;i<N;++i)
	{
		if(input[i].flag == 1)
			++sum;
	}

	qsort(input,N,sizeof(input[0]),compare);

	printf("%d\n",sum);
	if(sum>0)
	{
		for(i=0;i<N;++i)
		{
			if(input[i].flag == 1)
			{
				printf("%d",input[i].data);
				++count;
				if(count != sum)
					printf(" ");
				if(count == sum)
					break;
			}	
		}
	}
	printf("\n");
	return 0;
}

int compare(const void *a,const void *b)
{
	if((*(Num *)a).data == (*(Num *)b).data)
		return 0;
	else if((*(Num *)a).data < (*(Num *)b).data)
		return -1;
	else
		return 1;
}
//全部正确 
