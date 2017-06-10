#include <stdio.h>

int main()
{
	int p_g,p_s,p_k,a_g,a_s,a_k;
	scanf("%d.%d.%d %d.%d.%d",&p_g,&p_s,&p_k,&a_g,&a_s,&a_k);
	int r_g,r_s,r_k;
	if(a_g>p_g||a_g==p_g&&a_s>p_s||a_g==p_g&&a_s==p_s&&a_k>=p_k)//付的钱多或刚好够 
	{
		if(a_k>=p_k)r_k=a_k-p_k;
		else
		{
			r_k=a_k+29-p_k;
			a_s-=1;
		}
		if(a_s>=p_s)r_s=a_s-p_s;
		else
		{
			r_s=a_s+17-p_s;
			a_g-=1;
		}		
		r_g=a_g-p_g;
	}
	else//付的钱不够 
	{
		if(p_k>=a_k)r_k=p_k-a_k;
		else
		{
			r_k=p_k+29-a_k;
			p_s-=1;
		}
		if(p_s>=a_s)r_s=p_s-a_s;
		else
		{
			r_s=p_s+17-a_s;
			p_g-=1;
		}		
		r_g=p_g-a_g;
				
		printf("-");
	} 
	printf("%d.%d.%d\n",r_g,r_s,r_k);
	return 0;
} 
