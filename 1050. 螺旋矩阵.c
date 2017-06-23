#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d",&N);
	int i,c,num[10001]={0};
	for(i=0;i<N;i++)
	{
		scanf("%d",&c);
		num[c]++;
	}
	double d;
	int m,n;
	m=(int)sqrt(N);
	n=N/m;
	while(m*n!=N)
	{
		m++;
		n=N/m;
	}
	int t;
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
	int nn[m][n],j=0,k=0,cnt=0,n1=n,m1=m;
	for(i=10000;i>0;i--)
	{
		while(num[i]>0)
		{
			nn[j][k]=i;
			cnt++;
			//矩阵的外围一圈数据 
			if(cnt<n1)
			{
				k++;
			}
			else if(cnt<m1+n1-1)
			{
				j++; 
			}
			else if(cnt<m1+2*n1-2)
			{
				k--;
			}
			else if(cnt<2*m1+2*n1-4)
			{
				j--;
			}
			else
			{
				//除去矩阵的外围一圈数据，剩下的矩阵 
				k++;
				cnt=0;
				m1-=2;
				n1-=2;
			}
			num[i]--;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)printf("%d\n",nn[i][j]);
			else printf("%d ",nn[i][j]);
		}
	}
	return 0;
}
