#include <stdio.h>
#include <string.h>

int main()
{
	char password[21];
	int n;
	scanf("%s %d",password,&n);
	char s[50];
	int wrong_cnt=0;
	getchar();//����һ�����м���������gets(s)����Ȼִ����һ��gets(s)ʱ�������û��м�����s="\0"������������ȷ���ַ��� 
	gets(s);//gets �Ƕ�ȡ���з��ģ���������ѻ��з�ת��Ϊ'\0'
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
