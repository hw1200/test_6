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


int find_two_value(int* arr,int even_val,int odd_val)//even(偶数) odd(奇数)
//odd_val把单个数再添进去,则该数成双,异或为0
{
	//因为有两个不同的数，所有数异或结果必有一位是1，
	//我们找最低位1用来分堆，先找到xor的二进制位中最低位为1的位，
	//再根据该位将数组中的数据分成两类，

	int /*res,*/ res_1 = 0, res_2 = 0;//存储数组所有元素异或后的结果
	int split_flag,i;
	//res = find_one_value(arr);
	split_flag = /*res*/even_val & /*-res*/-even_val;//找出最低位1
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
			res_2 ^= arr[i];//9和24异或的结果
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
	//思想：有三个不同的数，其异或结果可能为0、1，所以先把所有数分成两堆。
	
	/*目的：将3个不同的数，分到一个奇数堆和一个偶数堆，
	这样再利用（1）、（2）的结果就可以区分出三个数。*/
	
	/*方法：用不断左移的1去和所有数异或。
	如果是1分到第1堆，如果是0分到第二堆。直到分堆成功（因为有可能所有数的某位都一样）*/
	
	//注意：有可能一个1会把三个数分到同一堆，需要对偶数堆进行异或，若结果为0则说明分堆失败。

	int res_1, res_2,count_1,count_2;
	int flag = 1, i,j;
	for (i = 0; i < 32; i++)
	{
		res_1 = res_2 = count_1 = count_2 = 0;
		for (j = 0; j < N; j++)
		{
			if (flag & arr[j])//如果为假(0),进入if语句,否则进入else语句
			{
				res_1 ^= arr[j];//相同的两个数排除,留下单数
				count_1++;//if语句执行的次数
			}
			else
			{
				res_2 ^= arr[j];
				count_2++;
			}
		}
		if (count_1 % 2 == 0 && res_1 != 0)//如果进入if语句的个数为偶数,且有两个成单的数进入
		{
			printf("find_one_val=%d\n", res_2);//else语句中有唯一的一个成单的数
			find_two_value(arr, res_1, res_2);//进入该语句
			break;
		}
		if (count_2 % 2 == 0 && res_2 != 0)
		{
			printf("find_one_val=%d\n", res_1);
			find_two_value(arr, res_2, res_1);
			break;
		}
		flag = flag << 1; //左移一位,直至分成两堆
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
