#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//students Ϊ�ṹ����
//typedef �ڱ���ʱ����  define ������Ԥ����ʱ����
typedef struct students {
	int num;
	char name[20];
	char sex;
}stu,*pstu;//pstu == struct students*

typedef int INTERGE;//�� int �滻Ϊ INTERGE
//#define INTERGE int //�� int �滻Ϊ INTERGE

int main()
{
	//s Ϊ�ṹ�������
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