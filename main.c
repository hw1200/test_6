#include <stdio.h>
#include <stdlib.h>

int i = 10;
void print()
{
	
	printf("print i = %d\n", i);
}

int main()
{
	int i = 8;
	printf("main i = %d\n", i);
	i = 5;
	print(i);
	system("pause");
	return 0;
}