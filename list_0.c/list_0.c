#include "func.h";

int main()
{
	//pstu ��һ����ַ *pstuȡ��ַ��ֵ
	pstu phead = NULL, ptail = NULL;//����ṹ�������phead��ptail
	int val;
	while (scanf("%d", &val) != EOF)
	{
		list_head_insert(&phead,&ptail,val);
		//list_tail_insert(&phead, &ptail, val);
	}
	list_print(phead);
	system("pause");
}