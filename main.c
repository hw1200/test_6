#include <stdio.h>
#include <stdlib.h>
#define N 7

int find_one_value(int* arr)
{
	int i;
	int res = 0;
	for (i = 0; i < N; i++)
	{
		res ^= arr[i];
	}
	return res;
}


int find_two_value(int* arr,int even_val,int odd_val)//even(ż��) odd(����)
//odd_val�ѵ����������ȥ,�������˫,���Ϊ0
{
	//��Ϊ��������ͬ���������������������һλ��1��
	//���������λ1�����ֶѣ����ҵ�xor�Ķ�����λ�����λΪ1��λ��
	//�ٸ��ݸ�λ�������е����ݷֳ����࣬

	int /*res,*/ res_1 = 0, res_2 = 0;//�洢��������Ԫ������Ľ��
	int split_flag,i;
	//res = find_one_value(arr);
	split_flag = /*res*/even_val & /*-res*/-even_val;//�ҳ����λ1
	//even & -even == 2;
	//add & -add == 1;
	for (i = 0; i < N; i++)
	{
		if (split_flag & arr[i])
		{
			res_1 ^= arr[i];
		}
		else
		{
			res_2 ^= arr[i];//9��24���Ľ��
		}
	}
	if (split_flag & odd_val)
	{
		printf("two_value = %d  three_value = %d", res_1 ^ odd_val, res_2);
	}
	else
	{
		printf("two_value = %d  three_value = %d", res_2 ^ odd_val, res_1);
	}
	
	
	//printf("res_1 = %d res_2 = %d\n", res_1, res_2);
}


int find_three_value(int* arr)
{
	//˼�룺��������ͬ�����������������Ϊ0��1�������Ȱ��������ֳ����ѡ�
	
	/*Ŀ�ģ���3����ͬ�������ֵ�һ�������Ѻ�һ��ż���ѣ�
	���������ã�1������2���Ľ���Ϳ������ֳ���������*/
	
	/*�������ò������Ƶ�1ȥ�����������
	�����1�ֵ���1�ѣ������0�ֵ��ڶ��ѡ�ֱ���ֶѳɹ�����Ϊ�п�����������ĳλ��һ����*/
	
	//ע�⣺�п���һ��1����������ֵ�ͬһ�ѣ���Ҫ��ż���ѽ�����������Ϊ0��˵���ֶ�ʧ�ܡ�

	int res_1, res_2,count_1,count_2;
	int flag = 1, i,j;
	for (i = 0; i < 32; i++)
	{
		res_1 = res_2 = count_1 = count_2 = 0;
		for (j = 0; j < N; j++)
		{
			if (flag & arr[j])//���Ϊ��(0),����if���,�������else���
			{
				res_1 ^= arr[j];//��ͬ���������ų�,���µ���
				count_1++;//if���ִ�еĴ���
			}
			else
			{
				res_2 ^= arr[j];
				count_2++;
			}
		}
		if (count_1 % 2 == 0 && res_1 != 0)//�������if���ĸ���Ϊż��,���������ɵ���������
		{
			printf("find_one_val=%d\n", res_2);//else�������Ψһ��һ���ɵ�����
			find_two_value(arr, res_1, res_2);//��������
			break;
		}
		if (count_2 % 2 == 0 && res_2 != 0)
		{
			printf("find_one_val=%d\n", res_1);
			find_two_value(arr, res_2, res_1);
			break;
		}
		flag = flag << 1; //����һλ,ֱ���ֳ�����
	}

}




int main()
{
	int a[N] = { 5,6,8,5,8,24,9};
	int val;
	//val = find_one_value(a);
	//printf("val = %d\n", val);
	//val = find_two_value(a);
	val = find_three_value(a);






	system("pause");



}