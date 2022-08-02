#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_malloc()
{
	int len;
	char* p;
	printf("������Ҫ����Ŀռ��С:");
	scanf("%d", &len);
	p = (char*)malloc(len);//ʹ��malloc��̬����ѿռ�
	if (p != NULL)
	{
		strcpy(p, "hello");
		puts(p);
	}
	//p++;����ƫ��,���Ҫƫ��,Ҫ�������λ��,freeʱ,��free��ָ����������malloc���ص�
	free(p);
}

void pointer_init()
{
	char* p = "hello";//�ַ���������ַ��ֵ��p;
	char c[10] = "hello";//strcpy(c,"hello");
	c[0] = 'H';
	//p[0] = 'H';
	p = "world";
	//c = "world";
	puts(p);
}

/*char* stack_string()
{
	char c[10] = "hello";
	return c;
}*///����ִ�н�����,��Ӧ����ʹ�õ�ջ�ռ�ͻ��ͷ�
char* stack_string()
{
	char* p = (char*)malloc(10);
	if (p != NULL)
	{
		strcpy(p, "hello");
	}
	//p = "hello";
	return p;
}//�ѿռ��ں���ִ�н����󲻻��ͷ�
void stack_heap()
{
	char* p;
	p = stack_string();
	printf("%s\n", p);
}

void wild_pointer()
{
	int* p1, * p2, * p3;
	p1 = (int*)malloc(4);
	*p1 = 1;
	p2 = (int*)malloc(4);
	*p2 = 2;
	free(p1);
	p1 = NULL;//free��Ŀռ�,һ��Ҫ��p1��ΪNULL,����p1ΪҰָ��
	p3 = (int*)malloc(4);
	*p3 = 3;
	printf("*p3 = %d\n", *p3);
	//*p1 = 100;
	printf("*p3 = %d\n", *p3);
}

void use_const()
{
	const char* p;//��������pȥ�޸���ָ��Ŀռ������
	char c[] = "hello";
	p = c; 
	c[0] = 'H';
	//p[0] = 'm';//������
	printf("p = %s\n", p);
}

void use_const1()
{
	char c[] = "hello";
	char c1[] = "helloworld";
	char* const p = c;
	//p = c + 1;����
	//p = c1//����
	p[0] = 'A';
	printf("p = %s\n", p);
}

void mymemmove(void* to, void* from, size_t count)
{
	char* pto, * pfrom;
	if (from > to)
	{
		pto = (char*)to;
		pfrom = (char*)from;
		while (count)
		{
			*pto = *pfrom;
			pfrom++;
			pto++;
			count--;
		}
	}
	else if(from<to) {
		pto = (char*)to+count-1;
			pfrom = (char*)from+count-1 ;
			while (count)
			{
				*pto = *pfrom;
				pfrom--;
				pto--;
				count--;
			}
	}
}
void use_mem()
{
	int c[8] = { 1,2,3,4,5,6,7,8};
	//memcpy(c , c+2, sizeof(int)*6);
	mymemmove(c, c+2 , sizeof(int) * 6);
}

void arr2_printer(int (*p)[4],int row)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < sizeof(*p) / sizeof(int); j++)
		{
			printf("%3d", p[i][j]);
		}
		printf("\n");
	}
}
void arr_pointer()
{
	int(*p)[4];
	//int* p1[4];
	int i = 10;
	int a[3][4] = { 1,3,5,7,9,2,4,6,8,10,13,16 };
	int b[4] = { 1,3,5,7 };
	p = a;
	//p = &b;
	arr2_printer(a,3);
}



int main()
{
	//use_malloc();

	//pointer_init();

	//stack_heap();

	//wild_pointer();

	//use_const();

	//use_const1();

	//use_mem();

	arr_pointer();

	system("pause");
	return 0;
}