#include <stdio.h>

int main()
{
	int n,d;
	float kc[1000],sj[1000];
	scanf("%d %d",&n,&d);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%f",&kc[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%f",&sj[i]);
	}
	float dj[n];
	for(i=0;i<n;i++)
	{
		dj[i]=sj[i]/kc[i];
	}	
	//�����۴Ӹߵ������� 
	float t1,t2,t3;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(dj[j]<dj[j+1])
			{
				t1=dj[j];
				dj[j]=dj[j+1];
				dj[j+1]=t1;

				t2=kc[j];
				kc[j]=kc[j+1];
				kc[j+1]=t2;
				
				t3=sj[j];
				sj[j]=sj[j+1];
				sj[j+1]=t3;								
			}
			else if(dj[j]==dj[j+1])//������ͬ����� 
			{
				if(kc[j]<kc[j+1])
				{
					t1=dj[j];
					dj[j]=dj[j+1];
					dj[j+1]=t1;
	
					t2=kc[j];
					kc[j]=kc[j+1];
					kc[j+1]=t2;
					
					t3=sj[j];
					sj[j]=sj[j+1];
					sj[j+1]=t3;								
				}
			}
		}
	}
	//Ϊ�˻��������棬����Խ�ߵ��±�������Ҫ�����ܴ�
	float max=0;
	j=0;
	while(d>0&&j<n)
	{
		if(d>kc[j])
		{
			max+=sj[j];			
		}
		else
		{
			max+=dj[j]*d;
		}
		d-=kc[j];
		j++;
	} 
	printf("%.2f\n",max);
	return 0;
} 
