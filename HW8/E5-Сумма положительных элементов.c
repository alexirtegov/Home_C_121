/*
E5-Сумма положительных элементов

Считать массив из 10 элементов и посчитать 
сумму положительных элементов массива.


Формат входных данных:
10 целых чисел через пробел


Формат результата:
Одно целое число - 
сумма положительных элементов массива

Input
4 -5 3 10 -4 -6 8 -10 1 0

Output
26
*/



#include <stdio.h>

#define SIZE 10

void input_array (int arr[])
{
	for(int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
}

int sum_positiv(int arr[])
{
	int res = 0;
	
	for(int i=0; i<SIZE; i++){
		if(arr[i]>=0) res+=arr[i];
	}
		
	
	return res;
}

int main(int argc, char **argv)
{
	int array[SIZE];
	
	input_array(array); 
	
	printf("%d", sum_positiv(array));
	
	return 0;
}

