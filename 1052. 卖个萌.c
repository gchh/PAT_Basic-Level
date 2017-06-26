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
	if(fuhao==1)shou_cnt--;//遇到尾部，有 [ 但是没有 ] 时 
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
	if(fuhao==1)yan_cnt--;
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
	if(fuhao==1)kou_cnt--;
	int n;
	scanf("%d",&n);
	int zs[n],zy[n],kk[n],yy[n],ys[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d %d",&zs[i],&zy[i],&kk[i],&yy[i],&ys[i]);
	}
	for(i=0;i<n;i++)
	{
		if(zs[i]>shou_cnt||ys[i]>shou_cnt||zy[i]>yan_cnt||yy[i]>yan_cnt||kk[i]>kou_cnt
		   ||zs[i]<1||ys[i]<1||zy[i]<1||yy[i]<1||kk[i]<1)
			printf("Are you kidding me? @\\/@\n");
		else
		{
			printf("%s(%s%s%s)%s\n",shou[zs[i]-1],yan[zy[i]-1],kou[kk[i]-1],yan[yy[i]-1],shou[ys[i]-1]);
		}
	}
	return 0;
}
