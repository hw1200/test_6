#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct L {
	int num;
	struct L* next;
}L,*List;

int main()
{
	int x;
	List L_0 = NULL,L_1 = NULL;
	L_0 = (L*)malloc(sizeof(L));//创建头节点
		L_0->next = NULL;//初始为空链表
		while (scanf("%d", &x) != EOF)//输入节点的值
		{
			L_1 = (L*)malloc(sizeof(L));//创建新节点
			if (L_1 == NULL)
			{
				return false;
			}
			memset(L_1, 0, sizeof(L));
			L_1->num = x;
			L_1->next = L_0->next;
			//将头结点中的指针域赋值给新节点的指针域,则新节点指向下一元素节点
			L_0->next = L_1;
		}
		while (L_1)//L_1 == L_1 !=NULL
		{
			printf("%3d",L_1->num);
			L_1 = L_1->next;
		}
		printf("\n");
		
	system("pause");
}

