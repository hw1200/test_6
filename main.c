#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void use_pointer()
{
	int i = 10;
	int* p;
	printf("i=%d\n", i);//ֱ�ӷ���
	p = &i;
	printf("*p=%d\n", *p);//��ӷ���
}

void change(int *j)//jΪ�β�
{
	//�������õı��ʾ���ֵ����,j=&i
	*j = 5;
	printf("j=%d\n", *j);
}
void pointer_trans()
{
	//ָ��Ĵ���ʹ�ó���
	int i = 10;
	printf("ʹ��ָ��֮ǰi=%d\n", i);
	change(&i);//&iΪʵ��
	printf("ʹ��ָ��֮��i=%d\n", i);

	//�ڱ���(��)������ȥ�ı����(��)������ĳ��������ֵ��һ��Ҫ��ָ��
}

#define n 5
void pointer_move()
{
	int a[n] = { 1,4,3,4,5 };
	int* p;
	int i;
	p = a;
	for (i = 0; i < n; i++)
	{
		printf("%3d", *(p+i));
	}
	printf("\n");
	p = &a[4];
	for (i = 0; i < n; i++)
	{
		printf("%3d", *(p - i));
	}
	printf("\n");
}

void pointer_self_add()
{
	int a[8] = { 1,3,5,7,9,13,15 };
	int* p;
	int j;
	p = a;
	printf("*p++ = %d\n", *p++); //*p++ ��ȡָ��pָ���ֵ�������һ��Ԫ��1�����ٽ�ָ��p����1��
	printf("*++p = %d\n", *++p);//�Ƚ�ָ��p����1����ʱָ��������һ��Ԫ�أ���* ������ȡ����ֵ
	j = *p++;
	printf("a[0] = %d,j = %d,*p = %d\n", a[0], j, *p);
	j = *++p;
	printf("a[1] = %d,j = %d,*p = %d\n", a[1], j, *p);
	j = p[0]++;
	//p[0]++ == (*p)++; ��ȥָ��pָ���ֵ���ٽ���ֵ����1
	printf("a[1] = %d,j = %d,*p = %d\n", a[1], j, *p);
	j = ++ * p;//��ȡָ��pָ���ֵ�������һ��Ԫ�أ����ٽ���ֵ����1
	printf("a[1] = %d,j = %d,*p = %d\n", a[1], j, *p);
}

int main()
{
	//use_pointer();

	//pointer_trans();

	//pointer_move();

	pointer_self_add();

	return 0;
}