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
	L_0 = (L*)malloc(sizeof(L));//����ͷ�ڵ�
		L_0->next = NULL;//��ʼΪ������
		while (scanf("%d", &x) != EOF)//����ڵ��ֵ
		{
			L_1 = (L*)malloc(sizeof(L));//�����½ڵ�
			if (L_1 == NULL)
			{
				return false;
			}
			memset(L_1, 0, sizeof(L));
			L_1->num = x;
			L_1->next = L_0->next;
			//��ͷ����е�ָ����ֵ���½ڵ��ָ����,���½ڵ�ָ����һԪ�ؽڵ�
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

