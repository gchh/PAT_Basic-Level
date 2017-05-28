#include <stdio.h>
//#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char a[n],b[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("\n%c %c",&a[i],&b[i]);//加个换行符，不然会先接收一个换行符 
	}
	int as=0,ap=0,af=0;
	int asc=0,asb=0,asj=0;
	int bsc=0,bsb=0,bsj=0;
	for(i=0;i<n;i++)
	{
		if(a[i]=='C')
		{
			if(b[i]=='J')
			{
				as++;
				asc++;
			}
			if(b[i]=='C')ap++;
			if(b[i]=='B')
			{
				af++;
				bsb++;
			}
		}
		if(a[i]=='B')
		{
			if(b[i]=='C')
			{
				as++;
				asb++;
			}
			if(b[i]=='B')ap++;
			if(b[i]=='J')
			{
				af++;
				bsj++;
			}
		}
		if(a[i]=='J')
		{
			if(b[i]=='B')
			{
				as++;
				asj++;
			}
			if(b[i]=='J')ap++;
			if(b[i]=='C')
			{
				af++;
				bsc++;
			}
		}
	}	
	printf("%d %d %d\n",as,ap,af);
	printf("%d %d %d\n",af,ap,as);
	if(asb>=asc&&asb>=asj)printf("B ");
	if(asc>asb&&asc>=asj)printf("C ");
	if(asj>asb&&asj>asc)printf("J ");
	
	if(bsb>=bsc&&bsb>=bsj)printf("B\n");
	if(bsc>bsb&&bsc>=bsj)printf("C\n");
	if(bsj>bsb&&bsj>bsc)printf("J\n");	
	return 0;
} 
