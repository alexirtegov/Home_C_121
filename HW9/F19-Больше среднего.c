/*
F19-Больше среднего

Определить количество положительных элементов квадратной матрицы, 
превышающих по величине среднее арифметическое всех элементов главной диагонали. 
Реализовать функцию среднее арифметическое главной диагонали.

Input format
5 строк по 5 целых чисел через пробел

Output format
Одно целое число


Input
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5

Output
10
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	int array [5][5];
	
	for(int i =0; i<5; i++){
		for(int j = 0; j<5; j++){
			scanf("%d", &array[i][j]);
		}
	}
	
	
	int sum=0;
	for(int i =0; i<5; i++){
		for(int j = 0; j<5; j++){
			if (i==j) sum +=array [i][j];
		}
	}
	int average = sum/5;
	
	int count =0;
	for(int i =0; i<5; i++){
		for(int j = 0; j<5; j++){
			if(array [i][j]>0 && array [i][j]>average) count++;
		}
	}
			
	printf("%d", count);
	
	return 0;
}

