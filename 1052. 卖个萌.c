#include <stdio.h>
#include <string.h>

int main() 
{
	char s[100],y[100],k[100],shou[10][5]={0},yan[10][5]={0},kou[10][5]={0};
	gets(s);
	gets(y);
	gets(k);
	int i,fuhao=0,shou_cnt=0,yan_cnt=0,kou_cnt=0,cnt=0;
	for(i=0; i<strlen(s); i++) 
	{
		if(s[i]=='[') 
		{
			cnt=0;
			fuhao=1;
			continue;
		}
		if(s[i]==']') 
		{
			shou_cnt++;
			cnt=0;
			fuhao=0;
		}
		if(fuhao==1) 
		{
			shou[shou_cnt][cnt]=s[i];
			cnt++;
		}
	}
	cnt=0;
	fuhao=0;	
	for(i=0; i<strlen(y); i++) 
	{
		if(y[i]=='[') 
		{
			cnt=0;
			fuhao=1;
			continue;
		}
		if(y[i]==']') 
		{
			yan_cnt++;
			cnt=0;
			fuhao=0;
		}
		if(fuhao==1) 
		{
			yan[yan_cnt][cnt]=y[i];
			cnt++;
		}
	}
	cnt=0;
	fuhao=0;	
	for(i=0; i<strlen(k); i++) 
	{
		if(k[i]=='[') 
		{
			cnt=0;
			fuhao=1;
			continue;
		}
		if(k[i]==']') 
		{
			kou_cnt++;
			cnt=0;
			fuhao=0;
		}
		if(fuhao==1) 
		{
			kou[kou_cnt][cnt]=k[i];
			cnt++;
		}
	}
	for(i=0; i<shou_cnt; i++) 
	{
		printf("%s",shou[i]);
	}
	printf("\n");
	for(i=0; i<yan_cnt; i++) 
	{
		printf("%s",yan[i]);
	}
	printf("\n");
	for(i=0; i<kou_cnt; i++) 
	{
		printf("%s",kou[i]);
	}
	printf("\n");
	return 0;
}
