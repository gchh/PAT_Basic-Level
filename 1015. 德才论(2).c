#include <stdio.h>
#include <stdlib.h>

typedef struct info{
	int id, de, cai, sum, type;
}info;

int get_type(int de, int cai);
int compar(const void *pa, const void *pb);
int high, low;
int main(void)
{
	int size;
	scanf("%d %d %d", &size, &low, &high);
	info *xs = malloc(size * sizeof(*xs));
	
	int i,cnt = 0;
	for (i = 0; i < size; i++) 
	{
		scanf("%d %d %d", &xs[i].id, &xs[i].de, &xs[i].cai);

		xs[i].sum = xs[i].de + xs[i].cai;
		xs[i].type = get_type(xs[i].de, xs[i].cai);
		if (xs[i].type != 5) 
		{
			cnt++;
		}
	}
	printf("%d\n", cnt);
	
	qsort(xs, size, sizeof(*xs), compar);
	for(i = 0; i < cnt; i++)
	{
		printf("%d %d %d\n", xs[i].id, xs[i].de, xs[i].cai);
	}
	
	free(xs);
	return 0;
}

int compar(const void *pa, const void *pb)
{
	info a = *(info *)pa;
	info b = *(info *)pb;
	int ret;
	if (a.type == b.type) 
	{
		if (a.sum == b.sum) 
		{
			if (a.de == b.de) 
			{
				ret = a.id - b.id;
			} 
			else 
			{
				ret = b.de - a.de;
			}
		} 
		else 
		{
			ret = b.sum - a.sum;
		}
	} 
	else 
	{
		ret = a.type - b.type;
	}
	return ret;
}

int get_type(int de, int cai)
{
	int type;
	if (de >= high) 
	{
		if (cai >= high) 
		{
			type = 1;
		} 
		else if (cai >= low) 
		{
			type = 2;
		} 
		else 
		{
			type = 5;
		}
	} 
	else if (de >= low) 
	{
		if (cai >= high) 
		{
			type = 4;
		} 
		else if (cai >= low)
		{
			if (de >= cai) 
			{
				type = 3;
			} 
			else 
			{
				type = 4;
			}
		} 
		else 
		{
			type = 5;
		}
	} 
	else 
	{
		type = 5;
	}
	return type;
}
