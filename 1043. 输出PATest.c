#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	int cnt_P=0,cnt_A=0,cnt_T=0,cnt_e=0,cnt_s=0,cnt_t=0;
	while((c=getchar())!='\n')
	{
		if(c=='P')cnt_P++;
		if(c=='A')cnt_A++;
		if(c=='T')cnt_T++;
		if(c=='e')cnt_e++;
		if(c=='s')cnt_s++;
		if(c=='t')cnt_t++;
	}
	while(cnt_P>0||cnt_A>0||cnt_T>0||cnt_e>0||cnt_s>0||cnt_t>0)
	{
		if(cnt_P>0)
		{
			printf("P");
			cnt_P--;
		}
		if(cnt_A>0)
		{
			printf("A");
			cnt_A--;
		}	
		if(cnt_T>0)
		{
			printf("T");
			cnt_T--;
		}	
		if(cnt_e>0)
		{
			printf("e");
			cnt_e--;
		}
		if(cnt_s>0)
		{
			printf("s");
			cnt_s--;
		}	
		if(cnt_t>0)
		{
			printf("t");
			cnt_t--;
		}							
	}
	printf("\n");
	return 0;
}
