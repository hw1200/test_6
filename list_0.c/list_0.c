#include "func.h";

int main()
{
	//pstu 是一个地址 *pstu取地址求值
	pstu phead = NULL, ptail = NULL;//定义结构体变量名phead和ptail
	int val;
	while (scanf("%d", &val) != EOF)
	{
		list_head_insert(&phead,&ptail,val);
		//list_tail_insert(&phead, &ptail, val);
	}
	list_print(phead);
	system("pause");
}