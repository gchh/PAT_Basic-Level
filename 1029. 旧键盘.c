#include <stdio.h>
#include <string.h>

int main()
{
	char in[81],out[81];
	gets(in);
	gets(out);
	int i,j,k=0,cnt=0;
	char huai[81]="";
	for(i=0;i<strlen(out);i++)
	{
		for(j=k;j<strlen(in);j++)
		{
			if(in[j]!=out[i])
			{
				if(in[j]>='a'&&in[j]<='z')huai[cnt]=in[j]-32;
				else huai[cnt]=in[j];
				cnt++;
			}
			else 
			{
				k=j+1;
				break;
			}
		}
	}
	for(i=0;i<strlen(huai)-1;i++)
	{	
		for(j=i+1;j<strlen(huai);j++)
		{
			if(huai[i]==huai[j])
			{
				for(k=j;k<strlen(huai);k++)
				{
					if(k==strlen(huai)-1)huai[k]='\0';
					else huai[k]=huai[k+1];
				}
				j--;//jλ�����µ��ַ���Ҳ������ huai[i]��ͬ������j--���´ν���ѭ����������jλ�ñȽϡ� 
			}
		}
	}
	puts(huai);
	return 0;
} 
