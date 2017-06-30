#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
	int lie;
	int hang;
	int yanse;
};
int main()
{
	int m,n,tol;
	scanf("%d %d %d",&m,&n,&tol);
	int i,j,xs[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&xs[i][j]);
		}
	}
	int g,h,k,cnt=0,tol1,tol2,tol3,tol4,tol5,tol6,tol7,tol8;
	struct Point *point=(struct Point*)malloc(sizeof(struct Point));;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//前后 
			if(j>0)tol1=xs[i][j]-xs[i][j-1];
			else tol1=tol+1;
			if(j+1<m)tol2=xs[i][j]-xs[i][j+1];
			else tol2=tol+1;
	
			//上下 			
			if(i>0)tol3=xs[i][j]-xs[i-1][j];
			else tol3=tol+1;
			if(i+1<n)tol4=xs[i][j]-xs[i+1][j];
			else tol4=tol+1;
			
			//前上，后下
			if(i>0&&j>0)tol5=xs[i][j]-xs[i-1][j-1];
			else tol5=tol+1;
			if(i+1<n&&j+1<m)tol6=xs[i][j]-xs[i+1][j+1];
			else tol6=tol+1;
	
			//后上，前下			
			if(i>0&&j+1<m)tol7=xs[i][j]-xs[i-1][j+1];
			else tol7=tol+1;
			if(i+1<n&&j>0)tol8=xs[i][j]-xs[i+1][j-1];
			else tol8=tol+1;
				
			tol1=abs(tol1);	
			tol2=abs(tol2);
			tol3=abs(tol3);
			tol4=abs(tol4);
			tol5=abs(tol5);
			tol6=abs(tol6);
			tol7=abs(tol7);
			tol8=abs(tol8);
			if(tol1>tol&&tol2>tol&&tol3>tol&&tol4>tol&&tol5>tol&&tol6>tol&&tol7>tol&&tol8>tol)
			{
				point[cnt].hang=i+1;
				point[cnt].lie=j+1;
				point[cnt].yanse=xs[i][j];
				for(g=0;g<cnt;g++)
				{
					if(point[cnt].yanse==point[g].yanse)
					{
						
					}
				}
				//h=i;
				//k=j;
				//printf("(%d, %d): %d\n",k+1,h+1,xs[h][k]);
				cnt++;
			}
		}
	}
	for(i=0;i<cnt;i++)
	{
		for(j=1;j<cnt;j++)
		{
			if(point[i].yanse==point[j].yanse)
			{
				
			}
		}
	}
	if(cnt==0)printf("Not Exist\n");
	else if(cnt==1)printf("(%d, %d): %d\n",k+1,h+1,xs[h][k]);
	else printf("Not Unique\n");
	free(point);
	return 0;
}
