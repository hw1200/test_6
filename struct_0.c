#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct students {
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
};

int main()
{
	struct students s = { 1001,"lele",'M',20,98.5,"BeiJing" };
	struct students sarr[3] ;
	memset(sarr, 0, sizeof(sarr));
	int ret,i;
	memset(&s, 0, sizeof(s));
	ret = scanf("%d%s %c%d%f%s", &s.num, s.name, &s.sex, &s.age, &s.score, s.addr);
	printf(" num = %d\n name = %s\n sex = %c\n age = %d\n score = %f\n addr = %s\n ", 
		s.num, s.name, s.sex, s.age,s.score, s.addr);
	printf("-----------------------\n");
	for (i = 0; i < 3; i++)
	{
		scanf("%d%s %c%d%f%s", &sarr[i].num, sarr[i].name, 
			&sarr[i].sex, &sarr[i].age, &sarr[i].score, sarr[i].addr);
	}
	for (i = 0; i < 3; i++)
	{
		printf(" num = %d name = %s sex = %c age = %d score = %f addr = %s\n ",
			sarr[i].num, sarr[i].name, sarr[i].sex, sarr[i].age, sarr[i].score, sarr[i].addr);
	}

	system("pause");
}