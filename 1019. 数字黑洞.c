#include <stdio.h> 

int main()
{
	int n;
	scanf("%d",&n);
	int g,s,b,q;
	q=n/1000;
	b=(n%1000)/100;
	s=(n%100)/10;
	g=n%10;
	if(0)//(g==s&&s==b&&b==q)
	{
		printf("%04d - %04d = %04d",n,n,n-n);
	}
	else
	{
		int i,j,t;
		int jx,sx,jg;
		do
		{
			for(i=0;i<4;i++)
			{
				for(j=0;j<3;j++)
				{
					if(q<b)
					{
						t=q;
						q=b;
						b=t;
					}
					if(b<s)
					{
						t=b;
						b=s;
						s=t;
					}	
					if(s<g)
					{
						t=s;
						s=g;
						g=t;
					}			
				}
			}
			jx=q*1000+b*100+s*10+g;
			sx=g*1000+s*100+b*10+q;
			jg=jx-sx;
			q=jg/1000;
			b=(jg%1000)/100;
			s=(jg%100)/10;
			g=jg%10;		
			printf("%04d - %04d = %04d\n",jx,sx,jg);
			if(jg==0)break;
		}while(jg!=6174);
	}
	return 0;
}
