#include <stdio.h>
#include <stdlib.h>

//����hanoi��������n���̴ӵ�one��������two�����Ƶ���three�� 
void hanoi(int n,char one, char two, char three)
{
	void move(char x, char y);//�� move����������
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
void move(char x, char y)//����move����
{
	printf("%c-->%c\n",x,y);
}

void main()
{
	void hanoi(int n, char one, char two, char three); //��hanoi����������
	int m;
	printf("���������ӵ�����:"); 
	scanf_s("%d", &m);
	printf("The step to moveing %d diskes:\n", m); 
	hanoi(m,'A','B','C');
		system("pause");
}
