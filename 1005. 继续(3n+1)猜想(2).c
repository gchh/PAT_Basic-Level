#include <stdio.h>

int main() 
{
	int num[101];
	int i, k, n, length;
	//num[]��ʼ��-1 
	for(i = 0; i < 101; i ++) 
	{
		num[i] = -1;
	}
	scanf("%d", &k);
	for(i = 0; i < k; i ++) 
	{
		scanf("%d", &n);
		//�±�Ϊ�������ݵ�num[]����  
		num[n] = 0;
	}
	for(i = 0; i < 101; i ++) 
	{
		if(num[i] != 0) 
		{
			continue;
		}
		n = i;
		while(n != 1) 
		{
			if(n % 2 == 0) 
			{
				n = n / 2;
				if(n <= 100) 
				{
					//�����ǵ� num[n]��1 
					num[n] = 1;
				}
			}
			else
			{
				n = 3 * n + 1;
				n = n / 2;
				if(n <= 100)
				{
					//�����ǵ� num[n]��1 
					num[n] = 1;
				}
			}
		}
	}
	//num[n]==0��n���ǹؼ��� 
	for(i = 0, length = 0; i < 101; i ++) 
	{
		if(num[i] == 0) 
		{
			length ++;
		}
	}
	for(i = 100; i > 1; i --) //��Ϊ�����ÿ��������>1 <=100 
	{
		if(num[i] == 0) 
		{
			length --;
			if(length != 0) 
			{
				printf("%d ", i);
			}
			else 
			{
				printf("%d", i);
				break;
			}
		}
	}
}
