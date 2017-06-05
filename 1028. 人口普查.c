#include <stdio.h>
#include <string.h>

struct pepole{
	char name[6];
	int year;
	int month;
	int  day;
};

int main()
{
	int n;
	scanf("%d",&n);
	struct pepole Pepole[n];
	int i,right=0;
	for(i=0;i<n;i++)
	{
		scanf("%s %d/%d/%d",Pepole[right].name,&Pepole[right].year,&Pepole[right].month,&Pepole[right].day);
		if(Pepole[right].year<1814
		   ||Pepole[right].year==1814&&Pepole[right].month<9
		   ||Pepole[right].year==1814&&Pepole[right].month==9&&Pepole[right].day<6
		   ||Pepole[right].year>2014
		   ||Pepole[right].year==2014&&Pepole[right].month>9
		   ||Pepole[right].year==2014&&Pepole[right].month==9&&Pepole[right].day>6
		   )
		   continue;
		   right++;
	}
	printf("%d ",right);
	char nm[6];
	int y,m,d,j;
	for(i=0;i<right;i++)
	{
		for(j=0;j<right-1;j++)
		{
			strcpy(nm,Pepole[j].name);
			y=Pepole[j].year;
			m=Pepole[j].month;
			d=Pepole[j].day;
			
			if(Pepole[j].year>Pepole[j+1].year
			   ||Pepole[j].year==Pepole[j+1].year&&Pepole[j].month>Pepole[j+1].month
			   ||Pepole[j].year==Pepole[j+1].year&&Pepole[j].month==Pepole[j+1].month&&Pepole[j].day>Pepole[j+1].day)
			{
				strcpy(Pepole[j].name,Pepole[j+1].name);
				Pepole[j].year=Pepole[j+1].year;
				Pepole[j].month=Pepole[j+1].month;
				Pepole[j].day=Pepole[j+1].day;
				
				strcpy(Pepole[j+1].name,nm);
				Pepole[j+1].year=y;
				Pepole[j+1].month=m;
				Pepole[j+1].day=d;
			}
		}
	}
	//for(i=0;i<right;i++)
	//{
	//	printf("%s %d/%d/%d\n",Pepole[i].name,Pepole[i].year,Pepole[i].month,Pepole[i].day);
	//}
	printf("%s ",Pepole[0].name);
	printf("%s\n",Pepole[right-1].name);
	return 0;
}
