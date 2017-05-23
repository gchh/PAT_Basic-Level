#include <stdio.h>
#include <string.h>
int main()
{
    char c[10][100]={};
    int i,j,n;
    int count_P,count_A,count_T,pos_P,pos_T;
    scanf("%d\n",&n);
#if 0 
    i=0;
    while(i<n)
    {
		gets(c[i]);
		i++;
		//printf("%d\n",i);
	}
#else
	for(i=0;i<n;i++)
	{
		gets(c[i]);
	}
#endif
    //for(i=0;i<n;i++)
    //{
    //    printf("%s\n",c[i]);//gets(c[i]);
    //}    
    for(i=0;i<n;i++)
    {    
        count_P = 0;
        count_A = 0;
        count_T = 0; 
        pos_P = 0;
        pos_T = 0;
        for(j=0;j<strlen(c[i]);j++)
        {
            if(c[i][j]=='P')
            {
          		count_P++;
                pos_P = j;
            }
            if(c[i][j]=='A')
            {
				count_A++;
			}
            if(c[i][j]=='T')
            {
                count_T++;
                pos_T = j;
            }
        }
        if(count_P+count_A+count_T != strlen(c[i]) || pos_T-pos_P<=1 || count_P>1 || count_T>1 || pos_P*(pos_T-pos_P-1)!=strlen(c[i])-pos_T-1)
            printf("NO\n");
        else
            printf("YES\n");
    }
} 
