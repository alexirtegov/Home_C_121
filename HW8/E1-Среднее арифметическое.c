/*
E1-Среднее арифметическое

Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

Input format
5 целых не нулевых чисел через пробел

Output format
Одно число в формате "%.3f"


Input
4 15 3 10 14
Output
9.200
 */


#include <stdio.h>

#define SIZE 5

int main(int argc, char **argv)
{
	
	int array [5] ={0};
	int sum =0;
	
	for (int i =0; i < SIZE; i++){
		scanf("%d", &array[i]);
		sum +=array[i];
	}
	
	
	float res = (float)sum/SIZE;
	printf("%.3f", res);
	
	
	return 0;
}

