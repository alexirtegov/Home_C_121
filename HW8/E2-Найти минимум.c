/*
E2-Найти минимум

Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

Input format
5 целых чисел через пробел

Output format
Одно единственное целое число


Input
4 15 3 10 14
Output
3
 */


#include <stdio.h>
#define SIZE 5

int main(int argc, char **argv)
{
	int arr[SIZE];
	
	
	for (int i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	
	}
	
	int min = arr[0];
	
		for (int i=0; i<SIZE; i++){
			if(min > arr[i]) min = arr[i];
	
	}
	
	printf("%d", min);
	
	return 0;
}

