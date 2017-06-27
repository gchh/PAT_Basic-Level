#include <stdio.h> 
#include <string.h>

int main()
{
	char c;
	int sum=0;
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z')
		{
			sum+=c-'a'+1;
		}
		else if(c>='A'&&c<='Z')
		{
			sum+=c-'A'+1;
		}
	}
#if 0//itoa是非标准C函数，所以不是所有编译器都能编译 
	char s[33];
	itoa(sum,s,2);
	//puts(s);
	int i,cnt0=0,cnt1=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='0')cnt0++;
		else cnt1++;
	}
	printf("%d %d\n",cnt0,cnt1);
#endif
#if 1//全部通过 
	int t,cnt0=0,cnt1=0;
	while(sum!=0)
	{
		t=sum%2;
		if(t==0)cnt0++;
		else cnt1++;
		sum/=2;
	};
	printf("%d %d\n",cnt0,cnt1);
#endif 
#if 0 //全部通过 
	int i,cnt0=0,cnt1=0;
	unsigned int ibit=0x80000000; //必须定义成无符号整型 
	for(i=0;i<32;i++)
	{
		if((sum&ibit)==0&&cnt1>=1)cnt0++;
		if((sum&ibit)!=0)
		{
			cnt1++;
		}
		ibit=ibit>>1;
	}
	printf("%d %d\n",cnt0,cnt1);	
#endif 
#if 0//全部通过 
	int i,ibit=0x01,a[32],cnt0=0,cnt1=0;
	for(i=31;i>=0;i--)
	{
		a[i]=(sum&ibit)==0?0:1;
		ibit=ibit<<1;
	}
	for(i=0;i<32;i++)
	{
		//printf("%d",a[i]);
		if(a[i]==0&&cnt1>=1)cnt0++;
		if(a[i]==1)cnt1++;
	}
	printf("%d %d\n",cnt0,cnt1);
#endif
	return 0;
}
