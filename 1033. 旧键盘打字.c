#include <stdio.h>
#include <string.h>
#if 1 //���Ե�4�����г�ʱ 
int main()
{
	char huai_key[68],wenzi[100001];
	gets(huai_key);
	gets(wenzi);
	int i,j,k,cnt;
	for(j=0;j<strlen(huai_key);j++)
	{
		cnt=0;
		//printf("%c ",huai_key[j]);
		//printf("%d ",strlen(wenzi));
		//puts(wenzi);
		//printf("\n");
		for(i=0;i<strlen(wenzi);i++)
		{
			if(huai_key[j]!='+'&&wenzi[i]!=huai_key[j]&&wenzi[i]!=huai_key[j]+32&&wenzi[i]!=huai_key[j]-32||huai_key[j]=='+'&&(wenzi[i]<'A'||wenzi[i]>'Z'))
			{
				wenzi[cnt]=wenzi[i];
				cnt++;
			}
		}
		wenzi[cnt]='\0';
	}
	puts(wenzi);
	return 0;
}
#else //ȫ����ȷ 
int main()
{
    int badkey[128]={0};//���滵��
    int i;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch>='A'&&ch<='Z')badkey[ch-'A'+'a']=1;//��ĸ��Сд������
        if(ch>='a'&&ch<='z')badkey[ch-'a'+'A']=1;//��ĸ��Сд������
        badkey[ch]=1;
    }
    if(badkey['+'])for(i='A';i<='Z';i++)badkey[i]=1;//�ϵ��������������д�д�޷����
    while((ch=getchar())!='\n')
    {
        if(badkey[ch])continue;
        printf("%c",ch);
    }
    printf("\n");
}
#endif
