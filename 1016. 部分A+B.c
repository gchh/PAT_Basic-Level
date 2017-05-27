#include <stdio.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	char a[11],pa,b[11],pb;
	scanf("%s %c %s %c",a,&pa,b,&pb);
	int i,cnt1=0,cnt2=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==pa)cnt1++;
	}
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]==pb)cnt2++;
	}
	int pai=0,pbi=0;
	for(i=0;i<cnt1;i++)
	{
		pai+=(pa-48)*pow(10,i);
	}
	for(i=0;i<cnt2;i++)
	{
		pbi+=(pb-48)*pow(10,i);
	}	
	printf("%d\n",pai+pbi);
	return 0;
}
