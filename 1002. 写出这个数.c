#include <stdio.h> 
#include <string.h>
#if 1
int main()
{
	char n[101];
	int a[5],sum=0;
	char* pinyin[11]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	scanf("%s",n);
	//printf("%s\n",n);
	//printf("%d\n",n[1]-48);
	//printf("%d\n",strlen(n));
	int i;
	for(i=0;i<strlen(n);i++)
	{
		sum+=n[i]-48;
	}
	printf("%d\n",sum);
	int t=0;
	while(sum/10!=0)
	{
		a[t]=sum%10;
		sum/=10;
		t++;
	}
	a[t]=sum;
	for(i=t;i>=0;i--)
	{
		if(i==t)printf("%s",pinyin[a[i]]);
		else printf(" %s",pinyin[a[i]]);
	}
	return 0;
}
#else
int main()
{
    char c[100];
    int a[5];
    char pinyin[][9] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    int i,n,t;
    n = 0;
    t = 0;
    gets(c);
    printf("%d\n",c[0] - 48);
    for(i=0;i<strlen(c);i++)
        n = n + c[i] - 48;
    printf("%d\n",n);
    while (n!=0)
    {
        a[t] = n%10;
        n = n/10;
        t++;
    }
    printf("%s",pinyin[a[t-1]]);
    for(i=t-2;i>=0;i--)
        printf(" %s",pinyin[a[i]]);
} 
#endif

