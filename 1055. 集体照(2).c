/*
�㷨��

1.�㷨��ʼ��
2.���ýṹ�壬����char���͵����飬�������ֺ�int���͵ı���������ߡ�
3.����n��k��
4.����n���˵����ֺ���ߡ�
5.����n���˰���߷���������������һ�£��������ֵ����������С�
6.m = n-int(n/k)*k��deviate=0��row_count=0��total_count=0��m��ʾĳ��������deviate��ʾĿǰ����������ƫ������row_count��ʾĳ������ӵ�������total_count��ʾ�ܹ���ӵ�������row_number�����źõĶ�������
7.���row_count<m����������������ʮ������
8.������[m/2+deviate]=�ṹ������[total_count]��
9.���deviate<0����deviate=-i������deviate=-deviate-1��
10.row_count++��total_count++��
11.�ص����߲���
12.��˳�����������������֣������С�
13.m = n / k��
14.row_number = 1��
15.���row_numberС��k�����������������ڶ�ʮ�Ĳ���
16.deviate=0��row_count=0��
17.���row_count < m�ͼ��������������ڶ�ʮ������
18.������[m/2+deviate]=�ṹ������[total_count]��
19.���deviate < 0����deviate = -deviate������deviate = -deviate - 1��
20.arrow_count++��total_count++��
21.�ص���ʮ�߲���
22.���������������֣������С�
23.row_number++���ص���ʮ�岽��
24.�㷨������
�㷨��������γ������Ҫ��ʱ������׶Σ�ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(n)��
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
//ȫ����ȷ 
