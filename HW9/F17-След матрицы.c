/*
F17-След матрицы

Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.

Input format
25 целых чисел через пробел.

Output format
Одно целое число.


Input
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5

Output
15
 */


#include <stdio.h>
#define SIZE 5

void input(int array[SIZE][SIZE])
{
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			scanf("%d", &array[i][j]);
		}
	}
}

int sum_diaginal(int array[SIZE][SIZE])
{
	int sum_diaginal = 0;
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(i==j) sum_diaginal +=array[i][j];
		}
	}	
	return sum_diaginal;
}

int main(int argc, char **argv)
{
	int array[SIZE][SIZE];
	
	input(array);
	
	printf("%d", sum_diaginal(array));
	
	return 0;
}

