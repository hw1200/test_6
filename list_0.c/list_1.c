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
	//�ж������Ƿ�Ϊ��
	if (NULL == *pphead)//*pphead == phead
	{
		//ͷβָ��ָ��ͬһ�ڵ�
		*pphead = pnew;
		*pptail = pnew;
	}
	else
	{
		pnew->pNext = *pphead;//��ԭ�е�ͷָ�븳ֵ���½ڵ��pNext
		*pphead = pnew;//�½ڵ����Ϊͷ���
	}
}

void list_tail_insert(pstu* pphead, pstu* pptail, int val)
{
	pstu pnew = (pstu)calloc(1,sizeof(stu));
	//calloc����Ŀռ��С��sizeof(pstu)*1
	pnew->num = val;
	//�ж������Ƿ�Ϊ��
	if (NULL == *pphead)
	{
		//ͷβָ��ָ��ͬһ�ڵ�
		*pphead = pnew;
		*pptail = pnew;
	}
	else
	{
		(*pptail)->pNext = pnew;
		*pptail = pnew;
	}
}