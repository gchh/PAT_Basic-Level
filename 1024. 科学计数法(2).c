#include "stdio.h"
#include"string.h"
#include <stdlib.h>
int main()
{
    int i,position_point=0,position_zheng=0,position_fu=0,count=0,length=0,position_e=0;
    char a[10000];
    gets(a);

    length=strlen(a);
    for(i=1;i<length;i++)
	{
    	if(a[i]=='.')   position_point=i;
        if(a[i]=='E')   position_e=i;
        if(a[i]=='+')    position_zheng=i;
        if(a[i]=='-')    position_fu=i;
	}
    if(a[0]=='-')printf("-");

	//��E���������ת��Ϊ%d
	for(i=position_e+2;i<length;i++)
	{
    	count=(a[i]-'0')+count*10;
	}

	if(count==0)
	{
   		for(i=1;i<position_e;i++)  
   			printf("%c",a[i] );
	}
	else
	{
		if(position_fu)//С��
		{
       		printf("0.");
       		for(i=0;i<count-1;i++)  //���0.0....
       			printf("0" );

        	for(i=1;i<position_point;i++)  //���С����ǰ����
        		printf("%c",a[i] );
        	for(i=position_point+1;i<position_e;i++)  //���С��������
            	printf("%c",a[i] );
		}
		else
		{
        	for(i=1;i<position_point;i++)  //���С����ǰ����
            	printf("%c",a[i] );
            if(count-(position_e-position_point-1)>=0) 
        	{
				for(i=position_point+1;i<position_e;i++)  //���С��������
             		printf("%c",a[i] );
      
        		for(i=0;i<count-(position_e-position_point-1);i++)  //���00....
            		printf("0" );
        	}
        	else
			{
				for(i=position_point+1;i<position_e;i++)  //���С��������
             	{
				 	printf("%c",a[i] );	
				 	if(i==position_point+count)printf(".");
				}
			} 
		} 
	}
	return 0;
}
