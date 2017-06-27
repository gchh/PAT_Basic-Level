#include <stdio.h>
#include <string.h>

struct po{
	char name[9];
	int height;
};

int cmp(const void* v1, const void* v2)//降序排列
{
    if(((struct po*)v1)->height - ((struct po*)v2)->height > 0)return -1;
    else if(((struct po*)v1)->height - ((struct po*)v2)->height < 0)return 1;
    else return strcmp(((struct po*)v1)->name, ((struct po*)v2)->name);
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	struct po p[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%s %d",&p[i].name,&p[i].height);
	}
	int m,mk;
	m=n/k;
	mk=n-m*(k-1);
	int t,c,s[mk],kn=0;
	t=mk;
	c=t/2+1;
	int max=0,max_i,cnt=0;
	qsort(p,n,sizeof(struct po),cmp);//使用qsort函数排序，全部通过 
	for(i=0;i<n;i++)
	{
	#if 0
		for(j=0;j<n;j++)//测试点5 运行超时 
		{
			if(max<p[j].height||max==p[j].height&&strcmp(p[max_i].name,p[j].name)>0)
			{
				max=p[j].height;
				max_i=j;
			}
		}
		s[c-1]=max_i;
		p[max_i].height=-1;
		max=0;		
	#else//使用qsort函数降序排列后 
		s[c-1]=i;
	#endif
		cnt++;
		if((cnt%2)!=0)c-=cnt;
		else c+=cnt;
		if(cnt>=t)
		{
			for(j=0;j<t;j++)
			{
				if(j==t-1)printf("%s\n",p[s[j]].name);
				else printf("%s ",p[s[j]].name);
			}			
			cnt=0;
			t=m;
			kn++;
			c=t/2+1;
		}
	}
	return 0;
}

