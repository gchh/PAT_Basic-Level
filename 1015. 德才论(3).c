#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	int dscore;
	int cscore;
}Student;

int get_type(Student p);
int compar(const void *pa, const void *pb);
int l,h;
int main()
{
	Student student[100000];
	int n;
	scanf("%d %d %d",&n,&l,&h);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&student[i].id,&student[i].dscore,&student[i].cscore);
	}
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(student[i].dscore>=l&&student[i].cscore>=l)//“才德兼亡”
		{
			cnt++;
		}
	}	
	printf("%d\n",cnt);
	qsort(student, n, sizeof(student[0]), compar);//sizeof(student[0])就是12，3X4 
	for(i = 0; i < cnt; i++)
	{
		printf("%d %d %d\n", student[i].id, student[i].dscore, student[i].cscore);
	}	
	return 0;
} 
int get_type(Student p)
{
	int type=4;
	if(p.dscore>=h&&p.cscore>=h)//才德兼备 
	{
		type=0; 
	}
	else if(p.dscore>=h&&p.cscore>=l)//德胜才 
	{
		type=1; 
	}
	else if(p.dscore>=l&&p.cscore>=l&&p.dscore>=p.cscore)//“才德兼亡”但尚有“德胜才”
	{
		type=2; 
	}		
	else if(p.dscore>=l&&p.cscore>=l)//“才德兼亡”但尚有“才胜德”
	{
		type=3; 
	}
	return type;		
} 
int compar(const void *pa, const void *pb)
{
	Student a = *(Student *)pa;
	Student b = *(Student *)pb;
	int ret,type1,type2;
	type1=get_type(a);
	type2=get_type(b);
	if (type1 == type2) 
	{
		if (a.dscore+a.cscore == b.dscore+b.cscore) 
		{
			if (a.dscore == b.dscore)
			{
				ret = a.id - b.id;
			} 
			else 
			{
				ret = b.dscore - a.dscore;
			}
		} 
		else 
		{
			ret = b.dscore + b.cscore - a.dscore - a.cscore;
		}
	} 
	else 
	{
		ret = type1 - type2;
	}
	return ret;
}
