#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
	if (1 == n)
	{
		return 1;
	}
	return n * f(n - 1);//找公式
}

int step(int n)
{
	if (1 == n)
	{
		return 1;
	}
	if (2 == n)
	{
		return 2;
	}
	return step(n - 1) + step(n - 2);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("n! = %d\n",f(n));
		//printf("n个台阶的走法有{ %d }种\n", step(n));
	}

	system("pause");
}