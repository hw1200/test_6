#include <stdio.h>
#include <stdlib.h>

/*链表是一种动态地进行存储分配的常见的、重要的数据结构。
链表中的头指针存放一个地址，该地址指向一个元素结点
(包含用户需要的实际数据和链接结点的地址),这样我们就只需定义一个头指针，
即可不断地增加结点，最后一个结点内的指针要存储为NULL，
用于判断是否到达链表尾部。链表的头指针head只需存储第一个结点的首地址，
通过遍历，即可访问每个元素。*/


typedef struct students {
	int num;
	struct students *pNext;
}stu, * pstu;

void list_print(pstu phead);
//头插法
void list_head_insert(pstu* pphead, pstu* pptail, int val);
//尾插法
void list_tail_insert(pstu* pphead, pstu* pptail, int val);
//有序插入
