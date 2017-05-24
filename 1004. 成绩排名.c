#include <stdio.h>

typedef struct{
	char name[11];
	char ID[11];
	int score;
}Student;

int main()
{
	Student student[1000];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		//scanf("%s",&student[i].name);
		//scanf("%s",&student[i].ID);
		//scanf("%d",&student[i].score);
		scanf("%s %s %d",&student[i].name,&student[i].ID,&student[i].score);
	}	
	//for(i=0;i<n;i++)
	//{
	//	printf("%s ",student[i].name);
	//	printf("%s ",student[i].ID);
	//	printf("%d\n",student[i].score);
	//}
	int max,min,max_n=0,min_n=0;
	max=student[0].score;
	min=student[0].score;
	for(i=0;i<n;i++)
	{
		if(max<student[i].score)
		{
			max=student[i].score;
			max_n=i;
		}
		if(min>student[i].score)
		{
			min=student[i].score;
			min_n=i;
		}
	}
	//printf("%s ",student[max_n].name);
	//printf("%s\n",student[max_n].ID);	
	//printf("%s ",student[min_n].name);
	//printf("%s\n",student[min_n].ID);	
	printf("%s %s\n",student[max_n].name,student[max_n].ID);	
	printf("%s %s\n",student[min_n].name,student[min_n].ID);	
	return 0;
} 
