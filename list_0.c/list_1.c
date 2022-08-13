#include "func.h";

void list_print(pstu phead)
{
	while (phead)
	{
		printf("%3d", phead->num);
		phead = phead->pNext;
	}
	printf("\n");
}

void list_head_insert(pstu* pphead, pstu* pptail, int val)
{
	//pstu* == stu**
	pstu pnew = (stu*)malloc(sizeof(pstu));
	memset(pnew,0, sizeof(stu));
	pnew->num = val;
	//判断链表是否为空
	if (NULL == *pphead)//*pphead == phead
	{
		//头尾指针指向同一节点
		*pphead = pnew;
		*pptail = pnew;
	}
	else
	{
		pnew->pNext = *pphead;//把原有的头指针赋值给新节点的pNext
		*pphead = pnew;//新节点就作为头结点
	}
}

void list_tail_insert(pstu* pphead, pstu* pptail, int val)
{
	pstu pnew = (pstu)calloc(1,sizeof(stu));
	//calloc申请的空间大小是sizeof(pstu)*1
	pnew->num = val;
	//判断链表是否为空
	if (NULL == *pphead)
	{
		//头尾指针指向同一节点
		*pphead = pnew;
		*pptail = pnew;
	}
	else
	{
		(*pptail)->pNext = pnew;
		*pptail = pnew;
	}
}