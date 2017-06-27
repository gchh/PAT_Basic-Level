/*
算法：

1.算法开始。
2.设置结构体，包含char类型的数组，储存名字和int类型的变量储存身高。
3.读入n、k。
4.读入n个人的名字和身高。
5.对这n个人按身高非增序排序，如果身高一致，则按名字字典序升序排列。
6.m = n-int(n/k)*k，deviate=0，row_count=0，total_count=0。m表示某排人数，deviate表示目前与该排中央的偏移量，row_count表示某排已入队的人数，total_count表示总共入队的人数，row_number是已排好的队列数。
7.如果row_count<m继续，否则跳到第十二步。
8.新数组[m/2+deviate]=结构体数组[total_count]。
9.如果deviate<0，则deviate=-i。否则，deviate=-deviate-1。
10.row_count++。total_count++。
11.回到第七步。
12.按顺序输出新数组里的名字，并换行。
13.m = n / k。
14.row_number = 1。
15.如果row_number小于k，继续，否则跳到第二十四步。
16.deviate=0，row_count=0。
17.如果row_count < m就继续，否则跳到第二十二步。
18.新数组[m/2+deviate]=结构体数组[total_count]。
19.如果deviate < 0，则deviate = -deviate。否则，deviate = -deviate - 1。
20.arrow_count++，total_count++。
21.回到第十七步。
22.输出新数组里的名字，并换行。
23.row_number++。回到第十五步。
24.算法结束。
算法分析：这段程序的主要耗时在排序阶段，时间复杂度为O(nlogn)，空间复杂度为O(n)。
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9

typedef struct person{
    char name[MAX];
    int height;
}person;

int cmp(const void* v1, const void* v2);
void print(person* list, int n);

int main(int argc, const char * argv[]) 
{
    int n, k, deviate, row_count, row_number, m, total_count;
    person *array, *row;
    scanf("%d %d", &n, &k);
    m = n - (n / k) * (k - 1);
    array = (person*)calloc(n, sizeof(person));
    row = (person*)calloc(m, sizeof(person));
    for(total_count = 0; total_count < n; total_count++)
	{
        scanf("%s %d", array[total_count].name, &(array[total_count].height));
    }
    qsort(array, n,sizeof(person), cmp);
    for(row_count = 0, deviate = 0, row_number = 0, total_count = 0; row_count < m;)
	{
        row[m / 2 + deviate] = array[total_count++];
        row_count++;
        if(deviate < 0)
		{
            deviate = -deviate;
        }
        else
		{
            deviate = -deviate - 1;
        }
    }
    print(row, m);
    row_number++;
    m = n / k;
    for(; row_number < k; row_number++)
	{
        for(row_count=0, deviate = 0; row_count < m; row_count++)
		{
            row[m / 2 + deviate] = array[total_count++];
            if(deviate < 0)
			{
                deviate = -deviate;
            }
            else
			{
                deviate = -deviate - 1;
            }
        }
        print(row, m);
    }
    return 0;
}
int cmp(const void* v1, const void* v2)
{
    if(((person*)v1)->height - ((person*)v2)->height > 0)
	{
        return -1;
    }
    else if(((person*)v1)->height - ((person*)v2)->height < 0)
	{
        return 1;
    }
    else
	{
        return strcmp(((person*)v1)->name, ((person*)v2)->name);
    }
}
void print(person* list, int n)
{
    int i;
    printf("%s", list[0].name);
    for(i = 1; i < n; i++)
	{
        printf(" %s", list[i].name);
    }
    putchar('\n');
}
//全部正确 
