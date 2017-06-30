#include <stdio.h>
#include <string.h>

int main()
{
	char password[21];
	int n;
	scanf("%s %d",password,&n);
	char s[50];
	int wrong_cnt=0;
	getchar();//读入一个换行键，或者用gets(s)，不然执行下一条gets(s)时，会读入该换行键，即s="\0"，而读不到正确的字符串 
	gets(s);//gets 是读取换行符的，不过它会把换行符转换为'\0'
	while(strcmp(s,"#")!=0)
	{
		if(strcmp(s,password)==0)
		{
			printf("Welcome in\n");
			break;
		}
		else
		{
			printf("Wrong password: %s\n",s);
			wrong_cnt++;
		}
		if(wrong_cnt>=n)
		{
			printf("Account locked\n");
			break;
		}
		gets(s);
	}
	return 0;
}
