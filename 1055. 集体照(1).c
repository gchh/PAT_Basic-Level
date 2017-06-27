#include <stdio.h>
#include <string.h>

struct po{
	char name[9];
	int height;
};

int cmp(const void* v1, const void* v2);

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	struct po p[n];
	int i,j,ph,pph;
	char pn[9],ppn[9];
	for(i=0;i<n;i++)
	{
		scanf("%s %d",&p[i].name,&p[i].height);
	#if 0 //使用此法排序，测试点3和5运行超时 
		scanf("%s %d",&pn,&ph);
		//身高从高到低 
		for(j=0;j<i;j++)
		{
			if(ph>p[j].height||ph==p[j].height&&strcmp(pn,p[j].name)<0)
			{
				pph=p[j].height;
				strcpy(ppn,p[j].name);
				p[j].height=ph;
				strcpy(p[j].name,pn);
				ph=pph;
				strcpy(pn,ppn);
			}
		}
		p[i].height=ph;
		strcpy(p[i].name,pn);	
	#endif	
	}
	qsort(p,n,sizeof(struct po),cmp);//使用qsort函数排序，全部通过 
	int m,mk;
	m=n/k;
	mk=n-m*(k-1);
	int t,c,s[mk],kn;
	t=mk;
	c=t/2+1;
	int cnt=0;
	for(kn=0;kn<k;kn++)
	{
		while(cnt<t)
		{
			if(kn>=1)s[c-1]=mk+(kn-1)*m+cnt;
			else s[c-1]=cnt;
			cnt++;
			if((cnt%2)!=0)c-=cnt;
			else c+=cnt;
		}
		for(j=0;j<t;j++)
		{
			if(j==t-1)printf("%s\n",p[s[j]].name);
			else printf("%s ",p[s[j]].name);
		}			
		cnt=0;
		t=m;
		c=t/2+1;
	}
	return 0;
}

int cmp(const void* v1, const void* v2)//降序排列
{
    if(((struct po*)v1)->height - ((struct po*)v2)->height > 0)return -1;
    else if(((struct po*)v1)->height - ((struct po*)v2)->height < 0)return 1;
    else return strcmp(((struct po*)v1)->name, ((struct po*)v2)->name);
}
