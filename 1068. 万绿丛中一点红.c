#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <string.h>

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
	int *unique=(int*)malloc(sizeof(int)*16777216);//�����unique[16777216]��δ��󣬿��Ա�����������޷�ִ�� 
	//memset(unique,0,sizeof(int)*16777216);//�ڴ泬��
	//int *unique=(int*)calloc(16777216,sizeof(int)); //�ڴ泬��
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&xs[i][j]);
			unique[xs[i][j]]++;
		}
	}
	int g,h,k,cnt=0,tol1,tol2,tol3,tol4,tol5,tol6,tol7,tol8;
	int choangfu;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(unique[xs[i][j]]==1)
			{
				//ǰ�� 
				if(j>0)tol1=xs[i][j]-xs[i][j-1];
				else tol1=tol+1;
				if(j+1<m)tol2=xs[i][j]-xs[i][j+1];
				else tol2=tol+1;
		
				//���� 			
				if(i>0)tol3=xs[i][j]-xs[i-1][j];
				else tol3=tol+1;
				if(i+1<n)tol4=xs[i][j]-xs[i+1][j];
				else tol4=tol+1;
				
				//ǰ�ϣ�����
				if(i>0&&j>0)tol5=xs[i][j]-xs[i-1][j-1];
				else tol5=tol+1;
				if(i+1<n&&j+1<m)tol6=xs[i][j]-xs[i+1][j+1];
				else tol6=tol+1;
		
				//���ϣ�ǰ��			
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
					h=i;
					k=j;
					//printf("(%d, %d): %d\n",k+1,h+1,xs[h][k]);
					cnt++;
				}
			}
		}
	}
	free(unique);
	if(cnt==0)printf("Not Exist\n");
	else if(cnt==1)printf("(%d, %d): %d\n",k+1,h+1,xs[h][k]);
	else printf("Not Unique\n");
	return 0;
}
//ȫ����ȷ 
