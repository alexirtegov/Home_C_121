/*
E3-Максимум и минимум и их номера

считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.

Input format
10 целых чисел через пробел

Output format
4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.


Input
4 -5 3 10 -4 -6 8 -10 1 0
Output
4 10 8 -10
 */


#include <stdio.h>

#define SIZE 10

void data_of_max(int array[])
{
	int max = array[0];
	int count = 1;
	for(int i=0; i<SIZE; i++){
		if(max<array[i]){
			max=array[i];
			count =i+1;
		}
	}
	
	printf("%d %d ", count, max);
}

void data_of_min(int array[])
{
	int min = array[0];
	int count = 1;
	for(int i=0; i<SIZE; i++){
		if(min>array[i]){
			min=array[i];
			count =i+1;
		}
	}
	
	printf("%d %d", count, min);
}




int main(int argc, char **argv)
{
	int array [SIZE];
	
	for(int i=0; i<SIZE; i++){
		scanf("%d", &array[i]);
	}
	
	data_of_max(array);
	data_of_min(array);
	
	return 0;
}

