/*
E15-Разложить по двум

Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. 
Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

Input format
10 целых чисел через пробел.

Output format
Сперва положительные числа, потом отрицательыне числа, через пробел.

Input
5 -4 0 1 4 -3 -3 3 0 2
Output
5 1 4 3 2 -4 -3 -3
 */


#include <stdio.h>
# define SIZE 10

void input_array(int array[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
}


void output_array(int array[], int count)
{
	for(int i=0; i<count; i++){
		printf("%d ", array[i]);
	}
}

void copy_pos(int array[], int pos_arr[])
{
	int count =0;

	for(int i=0; i<SIZE; i++){
		if(array[i]>0){
			pos_arr[count]=array[i];
			count++;
		}
	}
	output_array(&pos_arr[0], count);
}

void copy_neg(int array[], int neg_arr[])
{
	int count =0;

	for(int i=0; i<SIZE; i++){
		if(array[i]<0){
			neg_arr[count]=array[i];
			count++;
		}
	}
	output_array(&neg_arr[0], count);
}


int main(int argc, char **argv)
{
	int array[SIZE];
	
	input_array(&array[0]);
	
	int pos_arr[SIZE];
	copy_pos(array, pos_arr);
	
	int neg_arr[SIZE];
	copy_neg(array, neg_arr);
	
	
	
	return 0;
}

