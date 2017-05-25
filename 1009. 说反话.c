#include <stdio.h>
#include <string.h>

int main()
{
	char str[81];
	gets(str);
    //printf("%s\n",str);
	strtok(str," ");
    char* p[81];
    p[0]=str;
    int i=1;
    while(p[i]=strtok(NULL," "))
    {
    	i++;
    }
    int j;
    for(j=i-1;j>=0;j--)
    {
    	if(j==0)printf("%s\n",p[j]);
		else printf("%s ",p[j]);
	}
	return 0;	
} 
