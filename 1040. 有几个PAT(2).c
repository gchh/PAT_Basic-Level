#include <stdio.h>
#include <string.h>
int main() 
{
	char str[100001];
	gets(str);
	int numT = 0;
	int numAT = 0;
	int numPAT = 0;
	int i;
	for(i=strlen(str)-1; i>=0;i--)//���ַ���������ǰ���� 
	{
		if(str[i]=='T')//����T����¼��T����T���ܸ������������T�� 
			numT++;
		else if(str[i]=='A')//����A����¼��A����AT��ϵ��ܸ��������а���֮ǰͳ�Ƶ�A����AT���ܸ����������A�����ȫ��T��ϵĸ�������֮ǰͳ�Ƶ�T���ܸ����� 
			numAT=(numAT+numT)%1000000007;
		else //����P����¼��P����PAT��ϵ��ܸ�����ͬ�� 
		{
			numPAT=(numPAT+numAT)%1000000007;
		}
	}
	printf("%d", numPAT);
	return 0;
}
//ȫ����ȷ
