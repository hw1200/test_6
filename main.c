#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void use_pointer()
{
	int i = 10;
	int* p;
	printf("i=%d\n", i);//直接访问
	p = &i;
	printf("*p=%d\n", *p);//间接访问
}

void change(int *j)//j为形参
{
	//函数调用的本质就是值传递,j=&i
	*j = 5;
	printf("j=%d\n", *j);
}
void pointer_trans()
{
	//指针的传递使用场景
	int i = 10;
	printf("使用指针之前i=%d\n", i);
	change(&i);//&i为实参
	printf("使用指针之后i=%d\n", i);

	//在被调(子)函数中去改变调用(主)函数中某个变量的值，一定要用指针
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
	printf("*p++ = %d\n", *p++); //*p++ 先取指针p指向的值（数组第一个元素1），再将指针p自增1；
	printf("*++p = %d\n", *++p);//先将指针p自增1（此时指向数组下一个元素），* 操作再取出该值
	j = *p++;
	printf("a[0] = %d,j = %d,*p = %d\n", a[0], j, *p);
	j = *++p;
	printf("a[1] = %d,j = %d,*p = %d\n", a[1], j, *p);
	j = p[0]++;
	//p[0]++ == (*p)++; 先去指针p指向的值，再将该值自增1
	printf("a[1] = %d,j = %d,*p = %d\n", a[1], j, *p);
	j = ++ * p;//先取指针p指向的值（数组第一个元素），再将该值自增1
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