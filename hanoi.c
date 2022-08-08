#include <stdio.h>
#include <stdlib.h>

//定义hanoi函数，将n个盘从第one柱借助第two柱，移到第three柱 
void hanoi(int n,char one, char two, char three)
{
	void move(char x, char y);//对 move函数的声明
	if (n == 1) 
	{
		move(one, three);
	}	
	else
	{
		hanoi(n - 1, one, three, two); 
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
	
}
void move(char x, char y)//定义move函数
{
	printf("%c-->%c\n",x,y);
}

void main()
{
	void hanoi(int n, char one, char two, char three); //对hanoi函数的声明
	int m;
	printf("请输入盘子的数量:"); 
	scanf_s("%d", &m);
	printf("The step to moveing %d diskes:\n", m); 
	hanoi(m,'A','B','C');
		system("pause");
}
