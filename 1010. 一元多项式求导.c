#include <stdio.h>
#include <ctype.h>

int main()
{
	int s[2010];
	int length=0,i;
	char t; 
	while(1)
	{
		t=getchar();
		if(isdigit(t))
		{
			ungetc(t,stdin);//ungetc()�������ڽ�һ���ַ��˻ص��������У�����˻ص��ַ�������һ����ȡ�ļ����ĺ���ȡ�á�
			scanf("%d",&s[length]);
			length++;
		}
		else if(t=='-')//��������ⲿ�֣������������ 
		{
			ungetc(t,stdin);//ungetc()�������ڽ�һ���ַ��˻ص��������У�����˻ص��ַ�������һ����ȡ�ļ����ĺ���ȡ�á�
			scanf("%d",&s[length]);
			length++;
		}
		else if(t=='\n')break;
		//scanf("%d",&s[length]);
		//length++;
		//if(getchar()=='\n')
		//	break;
	};
	int j;
	for(i=0;i<length;i+=2)
	{
		j=length;
    	if(s[i+1]==0)
		{
			j=i;
			if(length==2)break;
		}
    	s[i]=s[i]*s[i+1];
    	s[i+1]-=1;
  	}
  	if(j==0)
  	{
    	printf("0 0\n");
  	}
  	else
  	{
    	for(i=0;i<j;i++)
    	{
    		if(s[i]==0&&i%2==0)
			{
				i++;
				continue;
			}
      		if(i==j-1)printf("%d\n",s[i]);
      		else printf("%d ",s[i]);
    	}
  	}
	return 0;	
} 
