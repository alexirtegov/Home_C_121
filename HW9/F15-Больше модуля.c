/*
F15-Больше модуля

Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент.
Прототип функции int count_bigger_abs(int n, int a[]);

Input format
Функция получает размер массива и массив целых чисел

Output format
Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент.


Input
1 -20 3 4 -50 6 7 8 9 10
Output
2
 */


#include <stdio.h>
#define SIZE 10

void input(int array[])
{
	for(int i =0; i<SIZE; i++){
		scanf("%d", &array[i]); 
	}
}

int count_bigger_abs(int n, int a[])
{
	//ищем максимальное число
	int max = a[0];
	for(int i=0; i<n; i++){
		if(max<a[i]) max=a[i];
	}
	
	//если max отрицательное берем модуль
	if(max<0) max=-max;
	
	// если члены массива отрицательные, делаем их положительными и сравниваем с max
	int count = 0;
	for(int i=0; i<n; i++){
		int temp = a[i];
		if(a[i]<0) temp = - a[i];
		if(temp>max) count ++;
	}
	
	return count;
}

int main(int argc, char **argv)
{
	int array[SIZE];
	input(array);
	
	int count = count_bigger_abs(SIZE, array);
	printf("%d", count);
	
	return 0;
}

