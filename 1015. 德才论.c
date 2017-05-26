#include <stdio.h>

typedef struct{
	int id;
	int dscore;
	int cscore;
}Student;
 
int main()
{
	Student student[100000];
	int n,l,h;
	scanf("%d %d %d",&n,&l,&h);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&student[i].id,&student[i].dscore,&student[i].cscore);
	}
	int c[n],cs[4]={0,0,0,0};//c1=0,c2=0,c3=0,c4=0;
	for(i=0;i<n;i++)c[i]=-1;
	for(i=0;i<n;i++)
	{
		if(student[i].dscore>=h&&student[i].cscore>=h)//才德兼备 
		{
			c[i]=0; 
			cs[0]++;
		}
		else if(student[i].dscore>=h&&student[i].cscore>=l)//德胜才 
		{
			c[i]=1; 
			cs[1]++;
		}
		else if(student[i].dscore>=l&&student[i].cscore>=l&&student[i].dscore>=student[i].cscore)//“才德兼亡”但尚有“德胜才”
		{
			c[i]=2; 
			cs[2]++;
		}		
		else if(student[i].dscore>=l&&student[i].cscore>=l)//“才德兼亡”但尚有“才胜德”
		{
			c[i]=3; 
			cs[3]++;
		}
	}	
	printf("%d\n",cs[0]+cs[1]+cs[2]+cs[3]);
	int sum,max,max_n,j;
#if 1
	for(j=0;j<cs[0];j++)
	{
		max=0;
		for(i=0;i<n;i++)
		{	
			if(c[i]==0)
			{
				sum=student[i].dscore+student[i].cscore;
				if(max<sum)
				{
					max=sum;
					max_n=i;				
				}
				else if(max==sum)
				{
					if(student[max_n].dscore<student[i].dscore) 
					{
						max_n=i;
					}
					else if(student[max_n].dscore==student[i].dscore)
					{
						if(student[max_n].id>student[i].id) 
						{
							max_n=i;	
						}
					}
				}
			}
		}
		printf("%d %d %d\n",student[max_n].id,student[max_n].dscore,student[max_n].cscore);
		//student[max_n].dscore=0;
		//student[max_n].cscore=0;
		c[max_n]=-1;
	}
	for(j=0;j<cs[1];j++)
	{
		max=0;
		for(i=0;i<n;i++)
		{	
			if(c[i]==1)
			{
				sum=student[i].dscore+student[i].cscore;
				if(max<sum)
				{
					max=sum;
					max_n=i;				
				}
				else if(max==sum)
				{
					if(student[max_n].dscore<student[i].dscore) 
					{
						max_n=i;
					}
					else if(student[max_n].dscore==student[i].dscore)
					{
						if(student[max_n].id>student[i].id) 
						{
							max_n=i;	
						}
					}
				}
			}
		}
		printf("%d %d %d\n",student[max_n].id,student[max_n].dscore,student[max_n].cscore);
		//student[max_n].dscore=0;
		//student[max_n].cscore=0;
		c[max_n]=-1;
	}
	for(j=0;j<cs[2];j++)
	{
		max=0;
		for(i=0;i<n;i++)
		{	
			if(c[i]==2)
			{
				sum=student[i].dscore+student[i].cscore;
				if(max<sum)
				{
					max=sum;
					max_n=i;				
				}
				else if(max==sum)
				{
					if(student[max_n].dscore<student[i].dscore) 
					{
						max_n=i;
					}
					else if(student[max_n].dscore==student[i].dscore)
					{
						if(student[max_n].id>student[i].id) 
						{
							max_n=i;	
						}
					}
				}
			}
		}
		printf("%d %d %d\n",student[max_n].id,student[max_n].dscore,student[max_n].cscore);
		//student[max_n].dscore=0;
		//student[max_n].cscore=0;
		c[max_n]=-1;
	}
	for(j=0;j<cs[3];j++)
	{
		max=0;
		for(i=0;i<n;i++)
		{	
			if(c[i]==3)
			{
				sum=student[i].dscore+student[i].cscore;
				if(max<sum)
				{
					max=sum;
					max_n=i;				
				}
				else if(max==sum)
				{
					if(student[max_n].dscore<student[i].dscore) 
					{
						max_n=i;
					}
					else if(student[max_n].dscore==student[i].dscore)
					{
						if(student[max_n].id>student[i].id) 
						{
							max_n=i;	
						}
					}
				}
			}
		}
		printf("%d %d %d\n",student[max_n].id,student[max_n].dscore,student[max_n].cscore);
		//student[max_n].dscore=0;
		//student[max_n].cscore=0;
		c[max_n]=-1;
	}
#else
	int s,tt=0;
	for(j=0;j<cs[tt];j++)
	{
		max=0;
		s=tt;
		for(i=0;i<n;i++)
		{	
			if(c[i]==s)
			{
				sum=student[i].dscore+student[i].cscore;
				if(max<sum)
				{
					max=sum;
					max_n=i;				
				}
				else if(max==sum)
				{
					if(student[max_n].dscore<student[i].dscore) 
					{
						max_n=i;
					}
					else if(student[max_n].dscore==student[i].dscore)
					{
						if(student[max_n].id>student[i].id) 
						{
							max_n=i;	
						}
					}
				}
			}
		}
		printf("%d %d %d\n",student[max_n].id,student[max_n].dscore,student[max_n].cscore);
		c[max_n]=-1;
		if(j==cs[tt]-1)
		{
			j=-1;
			tt++;
		}
	}
#endif
	return 0;
} 
