/*
F18-Сумма максимумов

Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. Напечатать значение этой суммы. 
Предполагается, что в каждой строке такой элемент единственный. Реализовать функцию поиска максимума в строке из 10 элементов

Input format
10 строк состоящих из 10 целых чисел через пробел.

Output format
Одно целое число


Input
61 75 55 2 35 34 77 93 28 49
11 34 22 78 19 14 67 67 11 0
72 39 23 53 92 51 60 34 71 63
14 27 72 6 0 79 98 56 30 15
31 16 3 4 95 59 25 17 11 20
5 93 21 61 96 30 79 38 73 40
89 4 66 19 36 99 67 67 92 36
87 54 7 35 40 43 44 46 4 69
98 57 20 75 9 66 85 9 39 31
8 90 94 25 12 30 18 10 23 15

Output
930
 */


#include <stdio.h>
#define SIZE 10

void input(int array[SIZE][SIZE])
{
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			scanf("%d", &array[i][j]);
		}
	}
}

int max_str(int array[SIZE][SIZE])
{
	int max_array = 0;
	
	
	for(int i=0; i<SIZE; i++){
		int max_str = array[i][0];
		
		for(int j=0; j<SIZE; j++){
			if(max_str < array[i][j]) max_str = array[i][j];
		}
		max_array +=max_str;
		
	}	
	return max_array;
}

int main(int argc, char **argv)
{
	int array[SIZE][SIZE];
	
	input(array);
	
	printf("%d", max_str(array));
	
	return 0;
}
