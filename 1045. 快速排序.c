#include <stdio.h>

int main() 
{
	int n;
	scanf("%d",&n);
	int i,j,c,zy[n],max=0,max_i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		if(c>max)//如果比现在最大值大 一定可以进来
		{
			zy[max_i]=c;
			max=c;
			max_i++;
		}
		else//不能成为主元 但却可以淘汰其他主元
		{
			for(j=max_i-1;j>=0;j--)
			{
				if(zy[j]>c)
				{
					zy[j]=0;
					max_i--;
				}
				else//else的部分，去掉答案也正确，但是用时会增加 
				{
					max_i=j+1;
					break;
				}
			}
		}
	}
	printf("%d\n",max_i);
	if(max_i>0)
	{
		for(i=0;i<max_i;i++)
		{
			if(i==max_i-1)printf("%d\n",zy[i]);
			else printf("%d ",zy[i]);
		}
	}
	else printf("\n");
	return 0;
}
//全部正确 
