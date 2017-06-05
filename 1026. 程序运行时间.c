#include <stdio.h> 
#include <time.h>

int main()
{
	clock_t start,finish;
	start=clock();
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int c3=c2-c1;
	if((c3%100)>=50)c3=c3/100+1;
	else c3=c3/100;
	int h,min,sec;
	h=c3/3600;
	min=(c3%3600)/60;
	sec=c3%60;
	printf("%02d:%02d:%02d\n",h,min,sec);
	finish=clock();
	printf("%d\n",(finish-start)/CLK_TCK);//CLOCKS_PER_SEC);
	return 0;
}
/*
ISO/IEC 9899:1999 标准中有一个宏: CLOCKS_PER_SEC
<1> tc2 中的 time.h：没有 CLOCKS_PER_SEC，有一个 CLK_TCK 
											#define  CLK_TCK  18.2
<2> gcc 中的 time.h：#define CLOCKS_PER_SEC ((clock_t)1000) 
					 #define CLK_TCK CLOCKS_PER_SEC
*/
