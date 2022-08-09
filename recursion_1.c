#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[3] = { 0 };
	char* parr[3] = { "alp","num","oth" };
	char c;
	int i, j,tmp; 
	char* ptmp;
	printf("ÇëÊäÈë:");
	while (scanf("%c", &c) != EOF)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		{
			arr[0]++;//alpµÄÊýÄ¿
		}
		else if (c >= '0' && c <= '9')
		{
			arr[1]++;//numµÄÊýÁ¿
		}
		else if (c != '\n')
		{
			arr[2]++;
		}
	}
	for (i = 3; i > 1; i--)
	{
		for (j = 0; j <= i - 1; j++)
		{
			if (arr[j]<arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				ptmp = parr[j];
				parr[j] = parr[j + 1];
				parr[j + 1] = ptmp;
			}
		}
	}
	for (i = 0; i <= arr[0]; i++)
	{
		if (0 == i)
		{
			printf("%6d  ", arr[0]);
		}
		else
		{
			printf("   *****");
		}
		if (arr[0] - arr[1]==i)
		{
			printf("%6d  ", arr[1]);
		}
		else if(i>arr[0]-arr[1])
		{
			printf("   *****");
		}
		if (arr[0] - arr[2] == i)
		{
			printf("%6d  ", arr[2]);
		}
		else if (i > arr[0] - arr[2])
		{
			printf("   *****");
		}
		printf("\n\n");
	}
	printf("%7s %7s %7s\n",parr[0],parr[1],parr[2]);

	system("pause"); 
}
