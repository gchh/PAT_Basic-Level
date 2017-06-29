#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int M, N, S;
    char names[1000][32];
    char tmp[20];
    int i, j = 0, k;
    int cnt = 0;
    int flag, flag1 = 0;
    scanf("%d%d%d", &M, &N, &S);
    for (i = 1; i < S; i++)
    {
		scanf("%s", tmp);
	}
    i = 1;
    cnt = N - 1;
    while(i+S-1 <= M)
    {
        scanf("%s", tmp);
        cnt++;
        if (cnt == N)
        {
            flag = 0;
            for (k = 0; k < j; k++)
            {
                if (!strcmp(names[k], tmp))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                flag1 = 1;
                printf("%s\n", tmp);
                strcpy(names[j], tmp);
                j++;
                cnt = 0;
            }
            else cnt = N - 1;
        }
        i++;
    }
    if (flag1 == 0)printf("Keep going...\n");
    return 0;
}
//全部正确 
