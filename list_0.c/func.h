#include <stdio.h>
#include <stdlib.h>

/*������һ�ֶ�̬�ؽ��д洢����ĳ����ġ���Ҫ�����ݽṹ��
�����е�ͷָ����һ����ַ���õ�ַָ��һ��Ԫ�ؽ��
(�����û���Ҫ��ʵ�����ݺ����ӽ��ĵ�ַ),�������Ǿ�ֻ�趨��һ��ͷָ�룬
���ɲ��ϵ����ӽ�㣬���һ������ڵ�ָ��Ҫ�洢ΪNULL��
�����ж��Ƿ񵽴�����β���������ͷָ��headֻ��洢��һ�������׵�ַ��
ͨ�����������ɷ���ÿ��Ԫ�ء�*/


typedef struct students {
	int num;
	struct students *pNext;
}stu, * pstu;

void list_print(pstu phead);
//ͷ�巨
void list_head_insert(pstu* pphead, pstu* pptail, int val);
//β�巨
void list_tail_insert(pstu* pphead, pstu* pptail, int val);
//�������
