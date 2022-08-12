#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//students 为结构体名
//typedef 在编译时进行  define 则是在预处理时进行
typedef struct students {
	int num;
	char name[20];
	char sex;
}stu,*pstu;//pstu == struct students*

typedef int INTERGE;//将 int 替换为 INTERGE
//#define INTERGE int //将 int 替换为 INTERGE

int main()
{
	//s 为结构体变量名
	stu s = { 1001,"lele",'M'};
	stu arr[3] = { 1005,"lele",'M',1002,"xiongda",'M',1003,"peiqi",'W' };
	//stu* p;
	pstu p;
	//int num;
	INTERGE num;
	p = &s;
	printf("num = %d\nname = %s\nsex = %c\n ",
		p->num,p->name,p->sex);
	printf("----------------------\n");
	p = arr;
	printf("num = % d\nname = % s\nsex = % c\n ",
		p->num, p->name, p->sex);

	num = p->num++;
	printf("num = %d p->num = %d\n",
		num,p->num);

	num = p++->num;
	printf("num = %d p++->num = %d\n",
		num, p->num);

	system("pause");
}