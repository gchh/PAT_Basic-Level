#include <stdio.h>
#include <string.h>

struct po{
	char name[9];
	int height;
};

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	struct po p[n];
	int i,j,pp[n];
	for(i=0;i<n;i++)
	{
		scanf("%s %d",&p[i].name,&p[i].height);
		pp[i]=p[i].height;
	}
	int m,mk;
	m=n/k;
	mk=n-m*(k-1);
	int t,c,s[k][mk],kn=0;
	t=mk;
	c=t/2+1;
	int max=0,max_i,cnt=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max<pp[j]||max==pp[j]&&strcmp(p[max_i].name,p[j].name)>0)
			{
				max=pp[j];
				max_i=j;
			}
		}
		s[kn][c-1]=max_i;
		pp[max_i]=-1;
		max=0;
		cnt++;
		if((cnt%2)!=0)c-=cnt;
		else c+=cnt;
		if(cnt>=t)
		{
			for(j=0;j<t;j++)
			{
				if(j==t-1)printf("%s\n",p[s[kn][j]].name);
				else printf("%s ",p[s[kn][j]].name);
			}			
			cnt=0;
			t=m;
			kn++;
			c=t/2+1;
		}
	}
	return 0;
}
//测试点5 运行超时 
