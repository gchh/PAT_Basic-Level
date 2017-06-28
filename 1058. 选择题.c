#include <stdio.h>
#include <string.h>

struct ti{
	int FenZhi;
	int XuanXiangGeShu;
	int ZhengQueXuanXiangGeShu;
	char ZhengQueXuanXiang[6];
};
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j;
	struct ti T[M];
	for(i=0;i<M;i++)
	{
		//scanf会将空格作为一个字符读入 
		scanf("%d %d %d ",&T[i].FenZhi,&T[i].XuanXiangGeShu,&T[i].ZhengQueXuanXiangGeShu);
		for(j=0;j<T[i].ZhengQueXuanXiangGeShu;j++)
		{
			if(j==T[i].ZhengQueXuanXiangGeShu-1)scanf("%c",&T[i].ZhengQueXuanXiang[j]);
			else scanf("%c ",&T[i].ZhengQueXuanXiang[j]);
		}
	}
	int k,flag_daAn,flag_daAnCuoWu,daAnGeShu,deFen[N],cuoWuCiShu[M],max=0;
	for(i=0;i<N;i++)deFen[i]=0;
	for(i=0;i<M;i++)cuoWuCiShu[i]=0;
	char c;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			k=0;
			flag_daAn=0;
			flag_daAnCuoWu=0;
			while((c=getchar())!=')')
			{
				if(c=='(')flag_daAn=1;
				if(flag_daAn==1&&c>='0'&&c<='9')
				{
					daAnGeShu=c-'0';
					if(daAnGeShu!=T[j].ZhengQueXuanXiangGeShu)flag_daAnCuoWu=1;				
				}
				if(daAnGeShu==T[j].ZhengQueXuanXiangGeShu&&c>='a'&&c<='z')
				{
					if(c!=T[j].ZhengQueXuanXiang[k])flag_daAnCuoWu=1;
					k++;
				}
			}
			if(flag_daAnCuoWu==1)cuoWuCiShu[j]++;
			else deFen[i]+=T[j].FenZhi;
			if(max<cuoWuCiShu[j])max=cuoWuCiShu[j];
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d\n",deFen[i]);
	}
	if(max==0)printf("Too simple\n");
	else
	{
		printf("%d",max);
		for(i=0;i<M;i++)
		{
			if(max==cuoWuCiShu[i])printf(" %d",i+1);
		}	
		printf("\n");
	}
	return 0;
}
